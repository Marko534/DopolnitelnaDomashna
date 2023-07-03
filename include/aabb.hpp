//
// Created by 38975 on 03.7.2023.
//

#ifndef HOMEWORK_HELL_AABB_HPP
#define HOMEWORK_HELL_AABB_HPP

#include "rtweekend.hpp"

class aabb {
public:
    point3 minimum;
    point3 maximum;

    aabb();

    aabb(const point3 &minimum, const point3 &maximum);

    point3 min() const;
    point3 max()const;

    inline bool hit(const ray& r, double t_min, double t_max) const {
        for (int a = 0; a < 3; a++) {
            double invD = 1.0f / r.direction()[a];
            double t0 = (min()[a] - r.origin()[a]) * invD;
            double t1 = (max()[a] - r.origin()[a]) * invD;
            if (invD < 0.0f)
                std::swap(t0, t1);
            t_min = t0 > t_min ? t0 : t_min;
            t_max = t1 < t_max ? t1 : t_max;
            if (t_max <= t_min)
                return false;
        }
        return true;
    }
};


#endif //HOMEWORK_HELL_AABB_HPP
