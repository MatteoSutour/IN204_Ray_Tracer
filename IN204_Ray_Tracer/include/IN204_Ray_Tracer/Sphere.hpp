#ifndef Sphere_HPP
#define Sphere_HPP

#include "Vec3.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include <cmath> 

class Sphere : public Object
{
public:
    Vec3f center;                           /// position of the sphere 
    float radius, radius2;                  /// sphere radius and radius^2 
    Sphere(
        const Vec3f& c,
        const float& r,
        const Vec3f& sc,
        const float& refl = 0,
        const float& transp = 0,
        const Vec3f& ec = 0) :
        Object(sc, refl, transp, ec), center(c), radius(r), radius2(r* r) {};
    //Compute a ray-sphere intersection using the geometric solution
    bool intersect(const Ray& ray, float& t0, float& t1) const
    {
        Vec3f rayorig = ray.orig;
        Vec3f raydir = ray.dir;
        Vec3f l = center - rayorig;
        float tca = l.dot(raydir);
        if (tca < 0) return false;
        float d2 = l.dot(l) - tca * tca;
        if (d2 > radius2) return false;
        float thc = sqrt(radius2 - d2);
        // t0 distance entre l'origine du rayon et le point d'intersection à l'entrée de la sphère.
        // t1 distance entre l'origine du rayon et le point de sortie de la sphère.
        t0 = tca - thc;
        t1 = tca + thc;

        return true;
    }
};

#endif // !Sphere_HPP