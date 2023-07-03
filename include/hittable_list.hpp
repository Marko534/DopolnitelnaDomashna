//
// Created by 38975 on 28.6.2023.
//

#ifndef HOMEWORK_HELL_HITTABLE_LIST_HPP
#define HOMEWORK_HELL_HITTABLE_LIST_HPP

#include "aabb.hpp"

#include "hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list();

    hittable_list(shared_ptr<hittable> object);

    void clear();

    void add(shared_ptr<hittable> object);

    virtual bool hit(
            const ray &r, double t_min, double t_max, hit_record &rec) const override;

    virtual bool bounding_box(
            double time0, double time1, aabb& output_box) const override;
};

#endif //HOMEWORK_HELL_HITTABLE_LIST_HPP
