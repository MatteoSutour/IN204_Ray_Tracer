#ifndef Cube_HPP
#define Cube_HPP

#include "Object.hpp"
#include "Vec3.hpp"
#include "Ray.hpp"
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

// Classe implémentant les AABB : Axis Aligned Bounding Box
class Cube : public Object
{ 
public: 
    
    Vec3f bounds[2];

    Cube(
        const Vec3f &b0,
        const Vec3f &b1,
        const Vec3f& sc,
        const float& refl = 0,
        const float& transp = 0,
        const Vec3f& ec = 0) :
        Object(sc, refl, transp, ec) {bounds[0] = b0, bounds[1] = b1;};

    bool intersect(const Ray &r, float &t0, float &t1) const 
    { 
        float tmin, tmax, tymin, tymax, tzmin, tzmax;
 
        tmin = (bounds[r.sign[0]].x - r.orig.x) * r.invdir.x; 
        tmax = (bounds[1-r.sign[0]].x - r.orig.x) * r.invdir.x; 
        tymin = (bounds[r.sign[1]].y - r.orig.y) * r.invdir.y; 
        tymax = (bounds[1-r.sign[1]].y - r.orig.y) * r.invdir.y; 
 
        if ((tmin > tymax) || (tymin > tmax)) 
            return false; 
 
        if (tymin > tmin) 
        tmin = tymin; 
        if (tymax < tmax) 
        tmax = tymax; 
 
        tzmin = (bounds[r.sign[2]].z - r.orig.z) * r.invdir.z; 
        tzmax = (bounds[1-r.sign[2]].z - r.orig.z) * r.invdir.z; 
 
        if ((tmin > tzmax) || (tzmin > tmax)) 
            return false; 
 
        if (tzmin > tmin) 
        tmin = tzmin; 
        if (tzmax < tmax) 
        tmax = tzmax; 
 
        t0 = tmin;
        t1 = tmax;
 
        if (t0 < 0) { 
            t0 = tmax; 
            if (t0 < 0) return false;
        }

        return true; 
    }

    Vec3f getNhit(const Vec3f & phit) const
    {
        std::vector<float> dist;
        dist[0] = abs(bounds[0].x - phit.x);
        dist[1] = abs(bounds[0].y - phit.y);
        dist[2] = abs(bounds[0].z - phit.z);
        dist[3] = abs(bounds[1].x - phit.x);
        dist[4] = abs(bounds[1].y - phit.y);
        dist[5] = abs(bounds[1].z - phit.z);

        int argmin = (int)std::distance(dist.begin(), std::min_element(dist.begin(), dist.end()));

        if (argmin == 0){
            if (bounds[0].x < bounds[1].x) return Vec3f(-1, 0, 0);
            else return Vec3f(1, 0, 0);
        }
        else if (argmin == 1){
            if (bounds[0].y < bounds[1].y) return Vec3f(0, -1, 0);
            else return Vec3f(0, 1, 0);
        }
        else if (argmin == 2){
            if (bounds[0].z < bounds[1].z) return Vec3f(0, 0, -1);
            else return Vec3f(0, 0, 1);
        }
        else if (argmin == 3){
            if (bounds[0].x < bounds[1].x) return Vec3f(1, 0, 0);
            else return Vec3f(-1, 0, 0);
        }
        else if (argmin == 4){
            if (bounds[0].y < bounds[1].y) return Vec3f(0, 1, 0);
            else return Vec3f(0, -1, 0);
        }
        else {
            if (bounds[0].z < bounds[1].z) return Vec3f(0, 0, 1);
            else return Vec3f(0, 0, -1);
        }
    }
};

#endif // !Cube_HPP