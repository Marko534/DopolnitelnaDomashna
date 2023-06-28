#include "../include/vec3.hpp"
#include "../include/color.hpp"
#include "../include/ray.hpp"

#include <iostream>
#include <fstream>
#include <string>

const std::string FILE_OUTPUT = "../output.ppm";

color ray_color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    double t = 0.5*(unit_direction.y()+1);
    return (1.0f-t)*color (1.0f, 1.0f, 1.0f) + t*color (0.5f,0.7f, 1.0f);
}

int main() {
    //Makeing a file
    std::ofstream file(FILE_OUTPUT);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Image

    const double aspect_ratio = 16.0f / 9.0f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera

    double viewport_height  = 2.0f;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    vec3 origin = point3 (0,0,0);
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0 , viewport_height,0);
    vec3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0,0,focal_length);

    // Render

    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width-1);
            double v = double (j) / (image_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            write_color(file, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";



}