//
// Created by 38975 on 06.7.2023.
//

#ifndef HOMEWORK_HELL_PERLIN_HPP
#define HOMEWORK_HELL_PERLIN_HPP

#include "rtweekend.hpp"

class perlin {
private:
    static const int point_count = 256;
    double *ranfloat;
    int *perm_x;
    int *perm_y;
    int *perm_z;

    static int *perlin_generate_perm();
    static void permute(int* p, int n);

public:
    perlin();
    ~perlin();
    double noise(const point3& p) const;
};


#endif //HOMEWORK_HELL_PERLIN_HPP
