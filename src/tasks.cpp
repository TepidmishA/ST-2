// Copyright 2022 UNN-CS
#include <cstdint>
#include <utility>
#include "tasks.h"
#include "circle.h"


double task1() {
    double radius = 6378.1 * 1000;  // radius of the Earth in meters

    Circle c(radius);
    c.setFerence(c.getFerence() + 1);

    return c.getRadius() - radius;
}

std::pair<double, double> task2() {
    double radius = 3.0;        // radius of the pool in meters
    double width = 1.0;         // width of the road around the pool in meters
    double priceRoad = 1000.0;  // price per square meter
    double priceFence = 2000.0; // price per meter

    Circle pool(radius);
    Circle road(radius + width);

    double costRoad = (road.getArea() - pool.getArea()) * priceRoad;
    double costFence = road.getFerence() * priceFence;

    return { costRoad, costFence };
}
