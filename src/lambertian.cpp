//
// Created by 38975 on 29.6.2023.
//

#include "../include/material.hpp"


lambertian::lambertian(const color &a) {
    albedo = a;
}

bool lambertian::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {

    vec3 scatter_direction = rec.normal + random_unit_vector();
    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}
