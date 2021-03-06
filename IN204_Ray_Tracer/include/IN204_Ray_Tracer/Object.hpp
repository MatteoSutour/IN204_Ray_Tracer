#ifndef Object_HPP
#define Object_HPP

#include "Vec3.hpp"
#include "Vec2.hpp"
#include <random>

std::random_device rd; 
std::mt19937 gen(rd()); 
std::uniform_real_distribution<float> dis(0, 1);

class Object { 
 public:
    Vec3f surfaceColor, emissionColor;      /// surface color and emission (light) 
    float transparency, reflection;         /// surface transparency and reflectivity 
 public:
    Object() : surfaceColor(dis(gen), dis(gen), dis(gen)),
            emissionColor(dis(gen), dis(gen), dis(gen)),
            transparency(dis(gen)), reflection(dis(gen)) {};
    Object(const Vec3f& sc, const float& refl = 0, const float& transp = 0, const Vec3f& ec = 0) :
            surfaceColor(sc), emissionColor(ec),
            transparency(transp), reflection(refl) {};
    virtual ~Object() {} 
    // Method to compute the intersection of the object with a ray
    // Returns true if an intersection was found, false otherwise
    // See method implementation in children class for details
    virtual bool intersect(const Vec3f &, const Vec3f &, float &, float &) const = 0; 
    // Method to compute the surface data such as normal and texture coordnates at the intersection point.
    // See method implementation in children class for details
    //virtual void getSurfaceData(const Vec3f &, Vec3f &, Vec2f &) const = 0; 
};

#endif // !Object_HPP