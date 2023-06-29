//
// Created by 38975 on 29.6.2023.
//

#ifndef HOMEWORK_HELL_MATERIAL_HPP
#define HOMEWORK_HELL_MATERIAL_HPP

#include "rtweekend.hpp"

struct hit_record;

class material {
public:
    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const = 0;
};

#endif //HOMEWORK_HELL_MATERIAL_HPP
