#include "..//include/rtweekend.hpp"

#include "../include/color.hpp"
#include "../include/hittable_list.hpp"
#include "../include/sphere.hpp"
#include "../include/camera.hpp"
#include "../include/material.hpp"

#include <iostream>
#include <fstream>
#include <string>

const std::string FILE_OUTPUT = "../output.ppm";

color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;

    if (depth <= 0) {
        return color(0, 0, 0);
    }

    if(world.hit(r,0.001,infinity,rec)){
        ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return color(0,0,0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    double t = 0.5*(unit_direction.y()+1);
    return (1.0f-t)*color (1.0, 1.0, 1.0) + t*color (0.5, 0.7, 1.0);
    // the cooler colors
    // return (1.0f-t)*color (0.549, 0.033, 0.418) + t*color (0.0, 0.0, 0.0);
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
    const int samples_per_pixel = 100;
    const int max_depth = 50;

    // World
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.5f);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),  -0.4, material_left));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    // Camera
    camera cam;

    // Render

    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for(int s = 0; s<samples_per_pixel; s++) {
                double u = (i+ random_double()) / (image_width - 1);
                double v = (j+random_double()) / (image_height - 1);
                ray r = cam.get_ray(u,v);
                pixel_color += ray_color(r, world, max_depth);
            }
            write_color(file, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone.\n";



}