//
// Created by 38975 on 03.7.2023.
//

#ifndef HOMEWORK_HELL_TEXTURE_HPP
#define HOMEWORK_HELL_TEXTURE_HPP

#include "rtweekend.hpp"

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

#endif //HOMEWORK_HELL_TEXTURE_HPP
