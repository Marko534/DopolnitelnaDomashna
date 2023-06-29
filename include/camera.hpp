//
// Created by 38975 on 29.6.2023.
//

#ifndef HOMEWORK_HELL_CAMERA_HPP
#define HOMEWORK_HELL_CAMERA_HPP

#include "rtweekend.hpp"

class camera {
private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
public:
    camera(
            double vfov, // vertical field-of-view in degrees
            double aspect_ratio
    );

    ray get_ray(double u, double v) const;
};


#endif //HOMEWORK_HELL_CAMERA_HPP
