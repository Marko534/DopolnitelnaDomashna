cmake_minimum_required(VERSION 3.25)
project(HOMEWORK_HELL)

set(CMAKE_CXX_STANDARD 17)

add_executable(HOMEWORK_HELL src/main.cpp src/vec3.cpp include/vec3.hpp include/color.hpp src/ray.cpp include/ray.hpp include/hittable.hpp src/sphere.cpp include/sphere.hpp src/hittable_list.cpp include/hittable_list.hpp include/rtweekend.hpp src/camera.cpp include/camera.hpp include/random.hpp include/material.hpp src/lambertian.cpp src/metal.cpp src/dielectric.cpp src/camera.cpp src/moving_sphere.cpp include/moving_sphere.hpp src/aabb.cpp include/aabb.hpp src/bvh.cpp include/bvh.hpp src/texture.cpp include/texture.hpp)
