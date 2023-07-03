//
// Created by 38975 on 28.6.2023.
//

#include "../include/ray.hpp"

ray::ray() {

}

ray::ray(const point3 &origin, const vec3 &direction, double time) {
    orig = origin;
    dir = direction;
    tm = time;
}

point3 ray::origin() const {
    return orig;
}

vec3 ray::direction() const {
    return dir;
}

point3 ray::at(double t) const {
    return orig + t * dir;
}

double ray::time() const {
    return tm;
}
