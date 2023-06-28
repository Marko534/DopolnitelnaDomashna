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

    ray();
    ray(const point3& origin, const vec3& direction);

    point3 origin() const;

    vec3 direction() const;

    point3 at(double t) const;
};

#endif //HOMEWORK_HELL_RAY_HPP
