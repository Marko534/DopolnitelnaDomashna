//
// Created by 38975 on 29.6.2023.
//

#ifndef HOMEWORK_HELL_RTWEEKEND_HPP
#define HOMEWORK_HELL_RTWEEKEND_HPP

#include <cmath>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers

inline double clamp(double x, double min, double max) {
    if (x < min) {
        return min;
    } else if (x > max) {
        return max;
    } else {
        return x;
    }
}


#include "random.hpp"
#include "ray.hpp"
#include "vec3.hpp"


#endif //HOMEWORK_HELL_RTWEEKEND_HPP
