//
// Created by 38975 on 06.7.2023.
//

#ifndef HOMEWORK_HELL_PERLIN_HPP
#define HOMEWORK_HELL_PERLIN_HPP

#include "rtweekend.hpp"

class perlin {
private:
    static const int point_count = 256;
    vec3* ranvec;
    int *perm_x;
    int *perm_y;
    int *perm_z;

    static int *perlin_generate_perm();
    static void permute(int* p, int n);

public:
    perlin();
    ~perlin();
    double noise(const point3& p) const;
    static double trilinear_interp(double c[2][2][2], double u, double v, double w);
    static double perlin_interp(vec3 c[2][2][2], double u, double v, double w);
    double turb(const point3& p, int depth=7) const;
};


#endif //HOMEWORK_HELL_PERLIN_HPP
