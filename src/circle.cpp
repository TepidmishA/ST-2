// Copyright 2022 UNN-CS
#include <cstdint>
#include <stdexcept>
#include "circle.h"


Circle::Circle(double radius_) {
    setRadius(radius_);
}

void Circle::setRadius(double radius_) {
    if (radius_ < 0)
        throw std::invalid_argument("Radius must be non-negative");

    radius = radius_;

    ference = 2 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::setFerence(double ference_) {
    if (ference_ < 0)
        throw std::invalid_argument("Ference must be non-negative");

    ference = ference_;
    
    radius = ference / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::setArea(double area_) {
    if (area_ < 0)
        throw std::invalid_argument("Area must be non-negative");

    area = area_;
    
    radius = std::sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
}

double Circle::getRadius() const { 
    return radius; 
}

double Circle::getFerence() const { 
    return ference; 
}

double Circle::getArea() const { 
    return area; 
}
