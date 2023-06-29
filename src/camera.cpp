//
// Created by 38975 on 29.6.2023.
//

#include "../include/camera.hpp"


camera::camera(double vfov, double aspect_ratio) {
    double theta = degrees_to_radians(vfov);
    double  h = tan(theta/2);
    double viewport_height = 2.0*h;
    double viewport_width  = aspect_ratio * viewport_height;

    double focal_length = 1.0;

    origin = point3(0, 0, 0);
    horizontal = vec3(viewport_width, 0.0, 0.0);
    vertical = vec3(0.0, viewport_height, 0.0);
    lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

}


ray camera::get_ray(double u, double v) const {
    return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}

