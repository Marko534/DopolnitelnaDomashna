//
// Created by 38975 on 28.6.2023.
//

#ifndef HOMEWORK_HELL_HITTABLE_HPP
#define HOMEWORK_HELL_HITTABLE_HPP

#include "ray.hpp"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
};

#endif //HOMEWORK_HELL_HITTABLE_HPP
