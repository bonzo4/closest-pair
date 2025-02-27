#include "./point/Point.hpp"
#include "./utils/getDistance.hpp"
#include "closestPair.hpp"

#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

ClosestPair closestPair(std::vector<Point> points_x, std::vector<Point> points_y) {
    // base case
    if (points_x.size() <= 3) {
        return closestPairBruteForce(points_x);
    }

    // get mid index of points
    int mid = points_x.size() / 2;

    // copy left half
    std::vector<Point> left_x(points_x.begin(), points_x.begin() + mid);
    // copy right half
    std::vector<Point> right_x(points_x.begin() + mid, points_x.end());

    // get the mid point
    Point mid_point = points_x[mid];

    // assign empty vectors for the sorted y
    std::vector<Point> left_y = std::vector<Point>();
    std::vector<Point> right_y = std::vector<Point>();

    // for each point in the sorted by y points vector
    for (Point& point : points_y) {
        // if the point exists in left half
        if (point.x_coor <= mid_point.x_coor) {
            // append the point to the left half
            left_y.push_back(point);
        // else if the point exists in the right half
        } else {
            // append the point to the right half
            right_y.push_back(point);
        }
    }

    // Recurisely run 
    ClosestPair left_pair = closestPair(left_x, left_y);
    ClosestPair right_pair = closestPair(right_x, right_y);

    // intialze the minimum pair and minimum distance
    ClosestPair min_pair;

    // compare the two pairs and assign the minimum pair and distance
    if (left_pair.distance < right_pair.distance) {
        min_pair.distance = left_pair.distance;
        min_pair.pair = left_pair.pair;
    } else {
        min_pair.distance = right_pair.distance;
        min_pair.pair = right_pair.pair;
    }

    // get the minimum pair in the strip
    ClosestPair pair_in_strip = closestPairInStrip(points_y, mid_point, min_pair.distance);

    // if minimum pair in the strip is less than the left and right pair return it
    if (pair_in_strip.distance < min_pair.distance) {
        return pair_in_strip;
    // else return the original min pair
    } else {
        return min_pair;
    }
}

ClosestPair closestPairBruteForce(std::vector<Point> points) {
    ClosestPair pair;
    pair.distance = INFINITY;

    // Get the distances of all pair of points
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = i + 1; j < points.size(); j++) {
            double distance = getDistance(points[i], points[j]);
            // if the distance is less than current pair, replace it
            if (distance < pair.distance) {
                pair.distance = distance;
                pair.pair = {points[i], points[j]};
            }
        }
    }

    return pair;
}

ClosestPair closestPairInStrip(std::vector<Point> points_y, Point mid_point, double min_dist) {
    // intialize an empty strip vector
    std::vector<Point> strip = std::vector<Point>();

    // for all points in the sorted by y vector
    for (Point& point : points_y) {
        // get all the coordinates that within the strip
        if (abs(point.x_coor - mid_point.x_coor) < min_dist) {
            strip.push_back(point);
        }
    }
    
    // intialize minimum pair
    ClosestPair pair;
    pair.distance = INFINITY;
    // get the size of the strip
    int strip_size = strip.size();

    // for all points in the strip
    for (int i = 0; i < strip_size - 1; i++) {
        // and all other points in the strip up to 7 or the the size of strip
        for (int j = i + 1; j < std::min(i + 7, strip_size); j++) {
            // get the distance
            double distance = getDistance(strip[i], strip[j]);
            // if the distance is less than the distance of the current pair, replace the current pair
            if (distance < pair.distance) {
                pair.distance = distance;
                pair.pair = {strip[i], strip[j]};
            }
        }
    }

    return pair;
}