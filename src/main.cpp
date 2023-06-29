#include "..//include/rtweekend.hpp"

#include "../include/color.hpp"
#include "../include/hittable_list.hpp"
#include "../include/sphere.hpp"

#include <iostream>
#include <fstream>
#include <string>

const std::string FILE_OUTPUT = "../output.ppm";

color ray_color(const ray& r, const hittable& world){
    hit_record rec;
    if(world.hit(r,0,infinity,rec)){
        return 0.5*(rec.normal + color(1,1,1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    double t = 0.5*(unit_direction.y()+1);
    return (1.0f-t)*color (1.0,0.0,1.0) + t*color (0.0f, 0.0f, 0.0f);
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

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera

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
            color pixel_color = ray_color(r , world);
            write_color(file, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";



}