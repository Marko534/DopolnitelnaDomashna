//
// Created by 38975 on 03.7.2023.
//

#include "../include/moving_sphere.hpp"

moving_sphere::moving_sphere() {

}

moving_sphere::moving_sphere(const point3 &center0, const point3 &center1, double time0, double time1, double radius,
                             const shared_ptr<material> &matPtr) : center0(center0), center1(center1), time0(time0),
                                                                   time1(time1), radius(radius), mat_ptr(matPtr) {}

point3 moving_sphere::center(double time) const {
    return center0 + ((time - time0) / (time1 - time0))*(center1 - center0);
}

bool moving_sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    vec3 oc = r.origin() - center(r.time());
    double a = r.direction().length_squared();
    double half_b = dot(oc,r.direction());
    double c = oc.length_squared() - radius*radius;

    double discriminant = half_b*half_b - a*c;
    if(discriminant<0){
        return false;
    }
    double sqrtd= sqrt(discriminant);

    double root = (-half_b - sqrtd)/a;
    if(root < t_min || t_max < root){
        root = (-half_b + sqrtd) / a;
        if(root <t_min || t_max <root){
            return false;
        }
    }

    rec.t =root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center(r.time()))/radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}
