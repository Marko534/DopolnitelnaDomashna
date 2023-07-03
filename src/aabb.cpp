//
// Created by 38975 on 03.7.2023.
//

#include "../include/aabb.hpp"

aabb::aabb() {

}

aabb::aabb(const point3 &minimum, const point3 &maximum) : minimum(minimum), maximum(maximum) {}

point3 aabb::min() const {
    return minimum;
}

point3 aabb::max() const {
    return maximum;
}

//bool aabb::hit(const ray &r, double t_min, double t_max) const {
//    for(int a = 0 ; a<3; a++){
//        double  t0 = fmin(minimum[a]-r.origin()[a]/r.direction()[a],
//                        maximum[a] - r.origin()[a]/r.direction()[a]);
//        double t1 = fmax((minimum[a] - r.origin()[a]) / r.direction()[a],
//                       (maximum[a] - r.origin()[a]) / r.direction()[a]);
//
//        t_min = fmax(t0, t_min);
//        t_max = fmin(t1,t_max);
//        if(t_max <= t_min){
//            return false;
//        }
//    }
//    return true;
//}

aabb surrounding_box(aabb box0, aabb box1) {
    point3 small(fmin(box0.min().x(), box1.min().x()),
                 fmin(box0.min().y(), box1.min().y()),
                 fmin(box0.min().z(), box1.min().z()));

    point3 big(fmax(box0.max().x(), box1.max().x()),
               fmax(box0.max().y(), box1.max().y()),
               fmax(box0.max().z(), box1.max().z()));

    return aabb(small,big);
}