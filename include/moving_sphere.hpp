//
// Created by 38975 on 03.7.2023.
//

#ifndef HOMEWORK_HELL_MOVING_SPHERE_HPP
#define HOMEWORK_HELL_MOVING_SPHERE_HPP

#include "rtweekend.hpp"

#include "aabb.hpp"

#include "hittable.hpp"

class moving_sphere : public hittable {
public:
    point3 center0, center1;
    double time0, time1;
    double radius;
    shared_ptr<material> mat_ptr;

    moving_sphere();

    moving_sphere(const point3 &center0, const point3 &center1, double time0, double time1, double radius,
                  const shared_ptr<material> &matPtr);

    virtual bool hit(
            const ray &r, double t_min, double t_max, hit_record &rec) const override;

    virtual bool bounding_box(
            double _time0, double _time1, aabb& output_box) const override;

    point3 center(double time) const;
};


#endif //HOMEWORK_HELL_MOVING_SPHERE_HPP
