#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.hpp"
#include "rtweekend.hpp"
#include <vector>

class hittable_list : public hittable
{
    public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }

    void add(shared_ptr<hittable> object)
    {
        objects.push_back(object);
    }

    bool hit(const ray& rayo, interval ray_t, hit_record& rec) const override
    {
        hit_record temp_rec;
        bool isHit = false;
        auto closest_so_far = ray_t.max;
        for (const auto& object : objects)
        {
            if (object->hit(rayo, interval(ray_t.min, closest_so_far), temp_rec))
            {
                isHit = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return isHit;
    }
};

#endif