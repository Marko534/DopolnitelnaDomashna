//
// Created by 38975 on 29.6.2023.
//

#ifndef HOMEWORK_HELL_RTWEEKEND_HPP
#define HOMEWORK_HELL_RTWEEKEND_HPP

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

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

//Random numb [0,1)
inline double random_double(){
    return rand()/(RAND_MAX+1.0f);
}

inline double random_double(double min, double max){
    return min + (max-min)*random_double();
}

#include "ray.hpp"
#include "vec3.hpp"


#endif //HOMEWORK_HELL_RTWEEKEND_HPP
