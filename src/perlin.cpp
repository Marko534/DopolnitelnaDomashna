//
// Created by 38975 on 06.7.2023.
//

#include "../include/perlin.hpp"

int *perlin::perlin_generate_perm() {

    auto p = new int[point_count];

    for (int i = 0; i < perlin::point_count; i++) {
        p[i] = i;
    }

    permute(p, point_count);

    return p;

}

void perlin::permute(int *p, int n) {
    for (int i = n - 1; i > 0; i--) {
        int tartget = random_int(0, i);
        int temp = p[i];
        p[tartget] = temp;
    }

}

perlin::perlin() {
    ranfloat = new double[point_count];
    for(int i =0; i<point_count; ++i){
        ranfloat[i] = random_double();
    }

    perm_x = perlin_generate_perm();
    perm_y = perlin_generate_perm();
    perm_z = perlin_generate_perm();
}

perlin::~perlin() {
    delete[] ranfloat;
    delete[] perm_x;
    delete[] perm_y;
    delete[] perm_z;
}

double perlin::noise(const point3 &p) const {
    int i = static_cast<int>(4*p.x()) & 255;
    int j = static_cast<int>(4*p.y()) & 255;
    int k = static_cast<int>(4*p.z()) & 255;

    return ranfloat[perm_x[i] ^ perm_y[j] ^ perm_z[k]];
}
