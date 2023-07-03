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
    vec3 u, v, w;
    double lens_radius;
    double time0, time1;
public:
    camera(
            point3 lookfrom,
            point3 lookat,
            vec3 vup,
            double vfov, // vertical field-of-view in degrees
            double aspect_ratio,
            double aperture,
            double focus_dist,
            double _time0 = 0.0f,
            double _time1 = 0.0f
    );

    ray get_ray(double s, double t) const;
};


#endif //HOMEWORK_HELL_CAMERA_HPP
