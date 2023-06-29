//
// Created by 38975 on 29.6.2023.
//

#ifndef HOMEWORK_HELL_MATERIAL_HPP
#define HOMEWORK_HELL_MATERIAL_HPP

#include "rtweekend.hpp"
//MAY NEED TO CHANGE IT
#include "hittable.hpp"

class material {
public:
    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const = 0;
};

class lambertian : public material {
public:
    color albedo;
public:
    lambertian(const color& a);

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override;
};

class metal : public material{
public:
    color albedo;

    metal (const color& a);

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override;
};

#endif //HOMEWORK_HELL_MATERIAL_HPP
