//
// Created by 38975 on 29.6.2023.
//

#include "../include/material.hpp"


lambertian::lambertian(const color &a) {
    albedo = make_shared<solid_color>(a);
}

lambertian::lambertian(shared_ptr<texture> a) {
    albedo = a;
}

bool lambertian::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {

    vec3 scatter_direction = rec.normal + random_unit_vector();

    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }

    scattered = ray(rec.p, scatter_direction, r_in.time());
    attenuation = albedo->value(rec.u,rec.v,rec.p);
    return true;
}

