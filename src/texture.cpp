//
// Created by 38975 on 03.7.2023.
//

#include "../include/texture.hpp"

solid_color::solid_color() {

}

solid_color::solid_color(color c) {
    color_value = c;
}

solid_color::solid_color(double red, double green, double blue)  {
    color_value = color(red, green, blue);
}

color solid_color::value(double u, double v, const vec3 &p) const {
    return color_value;
}

checker_texture::checker_texture() {

}

checker_texture::checker_texture(shared_ptr<texture> _even, shared_ptr<texture> _odd) {
    even = _even;
    odd = _odd;
}

checker_texture::checker_texture(color c1, color c2) {
    even = make_shared<solid_color>(c1);
    odd = make_shared<solid_color>(c2);
}

color checker_texture::value(double u, double v, const point3 &p) const {
    double sines = sin(10*p.x())* sin(10*p.y())* sin(10*p.z());
    if (sines<0){
        return odd ->value(u,v,p);
    } else{
        return even ->value(u,v,p);
    }
}

noise_texture::noise_texture() {

}

color noise_texture::value(double u, double v, const point3 &p) const {
    return color(1,1,1) * 0.5 * (1.0 + noise.noise(scale * p));
}

noise_texture::noise_texture(double sc) {
    scale = sc;
}


