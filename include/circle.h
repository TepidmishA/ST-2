// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#define _USE_MATH_DEFINES
#include <cstdint>
#include <cmath>


class Circle {
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double radius_);

    void setRadius(double radius_);
    void setFerence(double ference_);
    void setArea(double area_);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
