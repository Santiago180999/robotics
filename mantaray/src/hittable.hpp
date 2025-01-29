#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.hpp"
class material;

struct hit_record
{ 
    point3 p;
    vec3 normal;
    shared_ptr<material> mat;
    double t;
    bool front_face;

    void set_face_normal(const ray& rayo, const vec3& outward_normal)
    {
        // sets the hit record normal vector
        // NOTE: param outward normal is assumed to be unit length

        front_face = dot(rayo.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable 
{
    public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& rayo, interval ray_t, hit_record& rec) const = 0;
};

#endif