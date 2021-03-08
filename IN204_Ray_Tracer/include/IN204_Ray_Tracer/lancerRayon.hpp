#ifndef lancerRayon_HPP
#define lancerRayon_HPP

#include "Vec3.hpp"
#include "Sphere.hpp"
#include <vector>
#include <iostream> 
#include <fstream>

#define M_PI 3.141592653589793 

//This variable controls the maximum recursion depth
#define MAX_RAY_DEPTH 5 

float mix(const float& a, const float& b, const float& mix)
{
    return b * mix + a * (1 - mix);
}

//This is the main trace function. It takes a ray as argument (defined by its origin and direction). We test if this ray intersects any of the geometry in the scene. If the ray intersects an object, we compute the intersection point, the normal at the intersection point, and shade this point using this information. Shading depends on the surface property (is it transparent, reflective, diffuse). The function returns a color for the ray. If the ray intersects an object that is the color of the object at the intersection point, otherwise it returns the background color.
Vec3f trace(
    const Ray& ray,
    const std::vector<std::unique_ptr<Object>>& objects,
    const int& depth)
{
    Vec3f rayorig = ray.orig;
    Vec3f raydir = ray.dir;
    //if (raydir.length() != 1) std::cerr << "Error " << raydir << std::endl;
    float tnear = INFINITY;
    const std::unique_ptr<Object>* object = NULL;
    // find intersection of this ray with the object in the scene
    for (unsigned i = 0; i < objects.size(); ++i) {
        float t0 = INFINITY, t1 = INFINITY;
        if (objects[i]->intersect(ray, t0, t1)) {
            if (t0 < 0) t0 = t1;
            if (t0 < tnear) {
                tnear = t0;
                object = &objects[i];
            }
        }
    }
    // if there's no intersection return black or background color
    if (!object) return Vec3f(2);
    Vec3f surfaceColor = 0; // color of the ray/surfaceof the object intersected by the ray 
    Vec3f phit = rayorig + raydir * tnear; // point of intersection 
    Vec3f nhit = (*object)->getNhit(phit); // normal at the intersection point
    // If the normal and the view direction are not opposite to each other
    // reverse the normal direction. That also means we are inside the object so set
    // the inside bool to true. Finally reverse the sign of IdotN which we want
    // positive.
    float bias = 1e-4f; // add some bias to the point from which we will be tracing 
    bool inside = false;
    if (raydir.dot(nhit) > 0) nhit = -nhit, inside = true;
    if (((*object)->transparency > 0 || (*object)->reflection > 0) && depth < MAX_RAY_DEPTH) {
        // facingratio maximal lorsque la normale à la surface et la direction du rayon sont colinéaires.
        float facingratio = -raydir.dot(nhit);
        // change the mix value to tweak the effect
        float fresneleffect = mix((float)(pow(1 - facingratio, 3)), 1, 0.1f);
        // compute reflection direction (not need to normalize because all vectors
        // are already normalized)
        Vec3f refldir = raydir - nhit * 2 * raydir.dot(nhit);
        refldir.normalize();
        Vec3f reflection = trace(Ray(phit + nhit * bias, refldir), objects, depth + 1);
        Vec3f refraction = 0;
        // if the sphere is also transparent compute refraction ray (transmission)
        if ((*object)->transparency) {
            //ior : index of refraction
            float ior = 1.1f, eta = (inside) ? ior : 1 / ior; // are we inside or outside the surface? 
            float cosi = -nhit.dot(raydir);
            float k = 1 - eta * eta * (1 - cosi * cosi);
            Vec3f refrdir = raydir * eta + nhit * (eta * cosi - sqrt(k));
            refrdir.normalize();
            refraction = trace(Ray(phit - nhit * bias, refrdir), objects, depth + 1);
        }
        // the result is a mix of reflection and refraction (if the sphere is transparent)
        surfaceColor = (
            reflection * fresneleffect +
            refraction * (1 - fresneleffect) * (*object)->transparency) * (*object)->surfaceColor;
    }
    else {
        // it's a diffuse object, no need to raytrace any further
        for (unsigned i = 0; i < objects.size(); ++i) {
            if (objects[i]->emissionColor.x > 0) {
                // this is a light
                Vec3f transmission = 1;
                Vec3f lightDirection = (*object)->getNhit(phit);
                lightDirection.normalize();
                for (unsigned j = 0; j < objects.size(); ++j) {
                    if (i != j) {
                        float t0, t1;
                        if (objects[j]->intersect(Ray(phit + nhit * bias, lightDirection), t0, t1)) {
                            // Il y a une ombre
                            transmission = 0;
                            break;
                        }
                    }
                }
                surfaceColor += (*object)->surfaceColor * transmission *
                    std::max(float(0), nhit.dot(lightDirection)) * objects[i]->emissionColor;
            }
        }
    }

    return surfaceColor + (*object)->emissionColor;
}

//Main rendering function. We compute a camera ray for each pixel of the image trace it and return a color. If the ray hits an object, we return the color of the object at the intersection point, else we return the background color.
void render(const std::vector<std::unique_ptr<Object>>& objects)
{
    unsigned width = 640, height = 480;
    Vec3f* image = new Vec3f[width * height], * pixel = image;
    float invWidth = 1 / float(width), invHeight = 1 / float(height);
    float fov = 90, aspectratio = width / float(height);
    float angle = (float)(tan(M_PI * 0.5 * fov / 180.));
    // Trace rays
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x, ++pixel) {
            float xx = (float)((2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio);
            float yy = (float)((1 - 2 * ((y + 0.5) * invHeight)) * angle);
            Vec3f raydir(xx, yy, -1);
            raydir.normalize();
            *pixel = trace(Ray(Vec3f(0), raydir), objects, 0);
        }
    }
    // Save result to a PPM image (keep these flags if you compile under Windows)
    std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (unsigned i = 0; i < width * height; ++i) {
        ofs << (unsigned char)(std::min(float(1), image[i].x) * 255) <<
            (unsigned char)(std::min(float(1), image[i].y) * 255) <<
            (unsigned char)(std::min(float(1), image[i].z) * 255);
    }
    ofs.close();
    delete[] image;
}

#endif // !lancerRayon_HPP