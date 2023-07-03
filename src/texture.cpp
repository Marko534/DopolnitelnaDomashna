//
// Created by 38975 on 03.7.2023.
//

#include "../include/texture.hpp"

solid_color::solid_color() {

}

solid_color::solid_color(color c) {
    color_value = c;
}

solid_color::solid_color(double red, double green, double blue) : vec3(red, green, blue) {
    color_value = color(red, green, blue);
}

color solid_color::value(double u, double v, const vec3 &p) const {
    return color_value;
}
