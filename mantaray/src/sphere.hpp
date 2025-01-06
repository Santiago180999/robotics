#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"
#include "rtweekend.hpp"

class sphere : public hittable
{
    public:
    sphere(const point3& center, double radius) : center(center), radius(std::fmax(0, radius)) {}
    bool hit(const ray& rayo, interval ray_t, hit_record& rec) const override
    {
        vec3 oc = center - rayo.origin();
        auto a = rayo.direction().length_squared();
        auto h = dot(rayo.direction(), oc);
        auto c = oc.length_squared() - radius*radius;
        auto discriminant = h*h - a*c;

        if (discriminant < 0) {
            return false;
        }
        auto sqrtd = std::sqrt(discriminant);
        
        // find the nearest root that lies in the acceptable range. 
        auto root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root))
        {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = rayo.at(rec.t);
        rec.normal = (rec.p - center) / radius;

        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(rayo, outward_normal);
        return true;
    } 

    private:
    point3 center;
    double radius;
};

#endif