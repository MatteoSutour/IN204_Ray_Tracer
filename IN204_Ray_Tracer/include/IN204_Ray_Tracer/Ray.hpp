#ifndef Ray_HPP
#define Ray_HPP

#include "Vec3.hpp"

class Ray 
{ 
public: 
    Ray(const Vec3f &orig, const Vec3f &dir) : orig(orig), dir(dir) 
    { 
        invdir = Vec3f(1 / dir.x, 1 / dir.y, 1 / dir.z);
        sign[0] = (invdir.x < 0);
        sign[1] = (invdir.y < 0);
        sign[2] = (invdir.z < 0);
    } 
    Vec3f orig, dir; // ray orig and dir
    Vec3f invdir; 
    int sign[3]; 
};

#endif // !Ray_HPP