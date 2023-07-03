//
// Created by 38975 on 28.6.2023.
//

#ifndef HOMEWORK_HELL_RAY_HPP
#define HOMEWORK_HELL_RAY_HPP

#include "vec3.hpp"

class ray {
public:
    point3 orig;
    vec3 dir;
    double tm;

    ray();

    ray(const point3 &origin, const vec3 &direction, double time = 0.0f);

    point3 origin() const;

    vec3 direction() const;

    double time() const;

    point3 at(double t) const;
};

#endif //HOMEWORK_HELL_RAY_HPP
