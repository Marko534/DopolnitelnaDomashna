//
// Created by 38975 on 28.6.2023.
//

#ifndef HOMEWORK_HELL_SPHERE_HPP
#define HOMEWORK_HELL_SPHERE_HPP

#include "hittable.hpp"
#include "vec3.hpp"

class sphere : public hittable {
public:

    point3 center;
    double radius;
    shared_ptr<material> mat_ptr;

    sphere();

    sphere(point3 cen, double r, shared_ptr<material> m);

    virtual bool hit(
            const ray &r, double t_min, double t_max, hit_record &rec
    ) const override;

};


#endif //HOMEWORK_HELL_SPHERE_HPP
