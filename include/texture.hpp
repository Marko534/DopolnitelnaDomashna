//
// Created by 38975 on 03.7.2023.
//

#ifndef HOMEWORK_HELL_TEXTURE_HPP
#define HOMEWORK_HELL_TEXTURE_HPP

#include "rtweekend.hpp"
#include "perlin.hpp"

class texture {
public:
    virtual color value(double u, double v, const point3& p) const = 0;
};

class solid_color : public texture {
private:
    color color_value;
public:
    solid_color();
    solid_color(color c);

    solid_color(double red, double green, double blue);

    virtual color value(double u, double v, const vec3& p) const override;
};

class checker_texture : public texture {
public:
    shared_ptr<texture> odd;
    shared_ptr<texture> even;

    checker_texture();
    checker_texture(shared_ptr<texture> _even, shared_ptr<texture> _odd);
    checker_texture(color c1, color c2);

    virtual color value (double u, double v,  const point3& p) const override;
};

class noise_texture : public texture{
public:
    perlin noise;

    noise_texture();
    virtual color value (double u, double v, const point3& p) const override;
};


#endif //HOMEWORK_HELL_TEXTURE_HPP
