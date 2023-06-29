//
// Created by 38975 on 29.6.2023.
//

#include "../include/material.hpp"

metal::metal(const color &a) {
    albedo = a;
}

bool metal::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected);
    attenuation =albedo;
    return (dot(scattered.direction(), rec.normal)>0);
}
