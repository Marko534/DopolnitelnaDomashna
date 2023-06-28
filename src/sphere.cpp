//
// Created by 38975 on 28.6.2023.
//

#include "../include/sphere.hpp"

sphere::sphere() {

}

sphere::sphere(point3 cen, double r) {
    centar = cen;
    radius = r;
}

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius*radius;

    double discriminant = half_b*half_b - a*c;
    if (discriminant < 0) {
        return false;
    }
    double sqrtd = sqrt(discriminant);

    double root = (-half_b - sqrtd) /a ;
    if (root < t_min || t_max < root){
        root = (-half_b - sqrtd) /a;
        if (root < t_min || t_max < root){
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - centar) / radius;
}
