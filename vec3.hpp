//
// Created by 38975 on 28.6.2023.
//

#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <iostream>

using std::sqrt;


class vec3 {
public:
    double e[3];

    vec3();

    vec3(double e0, double e1, double e2);

    double x() const;
    double y() const;
    double z() const;

    vec3 &operator-();

    double operator[](int i) const;
    double &operator[](int i);

    vec3 &operator+=(const vec3 &v);
    vec3 &operator*=(const vec3 &v);
    vec3 &operator/=(const vec3 &v);

    double lenght() const;
    double length_squared() const;
};

using point3 = vec3;
using color = vec3;


#endif //VEC3_H
