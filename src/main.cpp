#include "../include/vec3.hpp"
#include "../include/color.hpp"

#include <iostream>
#include <fstream>
#include <string>
const std::string FILE_OUTPUT = "../output.ppm";

int main() {
    //Makeing a file

    std::ofstream file(FILE_OUTPUT);

    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1),0.25f);
            write_color(file, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";

}