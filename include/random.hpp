//
// Created by 38975 on 29.6.2023.
//

#ifndef HOMEWORK_HELL_RANDOM_HPP
#define HOMEWORK_HELL_RANDOM_HPP

#include <cstdlib>

//Random numb [0,1)
inline double random_double() {
    return rand() / (RAND_MAX + 1.0f);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

#endif //HOMEWORK_HELL_RANDOM_HPP
