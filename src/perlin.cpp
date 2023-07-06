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
