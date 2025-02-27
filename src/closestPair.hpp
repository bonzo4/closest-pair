#ifndef CLOSEST_PAIR_HPP
#define CLOSEST_PAIR_HPP

#include "./point/Point.hpp"

#include <vector>
#include <array>

struct ClosestPair
{
    std::array<Point, 2> pair;
    double distance;
};


ClosestPair closestPair(std::vector<Point> points_x, std::vector<Point> points_y);

ClosestPair closestPairBruteForce(std::vector<Point> points_x);

ClosestPair closestPairInStrip(std::vector<Point> points_y, Point mid_point, double min_dist);

#endif