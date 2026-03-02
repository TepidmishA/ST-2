// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

const double EPS = 1e-9;

//
// Constructor
//
TEST(circle, Constructor_RadiusOne) {
    Circle c(1.0);
    EXPECT_NEAR(1.0, c.getRadius(), EPS);
}

TEST(circle, Constructor_RadiusZero) {
    Circle c(0.0);
    EXPECT_NEAR(0.0, c.getRadius(), EPS);
}

TEST(circle, Constructor_NegativeThrows) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

//
// getRadius
//
TEST(circle, GetRadius) {
    Circle c(5.0);
    EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

//
// getFerence
//
TEST(circle, GetFerence) {
    Circle c(2.0);
    EXPECT_NEAR(4 * M_PI, c.getFerence(), EPS);
}

//
// getArea
//
TEST(circle, GetArea) {
    Circle c(3.0);
    EXPECT_NEAR(9 * M_PI, c.getArea(), EPS);
}

//
// setRadius
//
TEST(circle, SetRadius_UpdatesRadius) {
    Circle c(1.0);
    c.setRadius(5.0);
    EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(circle, SetRadius_UpdatesFerence) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_NEAR(2 * M_PI * 2.0, c.getFerence(), EPS);
}

TEST(circle, SetRadius_UpdatesArea) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(M_PI * 9.0, c.getArea(), EPS);
}

TEST(circle, SetRadius_NegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

//
// setFerence
//
TEST(circle, SetFerence_UpdatesFerence) {
    Circle c(1.0);
    c.setFerence(10.0);
    EXPECT_NEAR(10.0, c.getFerence(), EPS);
}

TEST(circle, SetFerence_UpdatesRadius) {
    Circle c(1.0);
    c.setFerence(2 * M_PI * 4.0);
    EXPECT_NEAR(4.0, c.getRadius(), EPS);
}

TEST(circle, SetFerence_UpdatesArea) {
    Circle c(1.0);
    c.setFerence(2 * M_PI * 3.0);
    EXPECT_NEAR(M_PI * 9.0, c.getArea(), EPS);
}

TEST(circle, SetFerence_NegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

//
// setArea
//
TEST(circle, SetArea_UpdatesArea) {
    Circle c(1.0);
    c.setArea(16.0 * M_PI);
    EXPECT_NEAR(16.0 * M_PI, c.getArea(), EPS);
}

TEST(circle, SetArea_UpdatesRadius) {
    Circle c(1.0);
    c.setArea(25.0 * M_PI);
    EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(circle, SetArea_UpdatesFerence) {
    Circle c(1.0);
    c.setArea(4.0 * M_PI);
    EXPECT_NEAR(4.0 * M_PI, c.getFerence(), EPS);
}

TEST(circle, SetArea_NegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

//
// task1
//
TEST(tasks, Task1_PositiveGap) {
    EXPECT_GT(task1(), 0);
}

TEST(tasks, Task1_GapValue) {
    EXPECT_NEAR(1.0 / (2 * M_PI), task1(), 1e-9);
}

//
// task2
//
TEST(tasks, Task2_RoadCostPositive) {
    auto res = task2();
    EXPECT_GT(res.first, 0);
}

TEST(tasks, Task2_FenceCostPositive) {
    auto res = task2();
    EXPECT_GT(res.second, 0);
}

TEST(tasks, Task2_RoadCost) {
    auto res = task2();
    EXPECT_NEAR(7000 * M_PI, res.first, 1e-9);
}

TEST(tasks, Task2_FenceCost) {
    auto res = task2();
    EXPECT_NEAR(16000 * M_PI, res.second, 1e-9);
}
