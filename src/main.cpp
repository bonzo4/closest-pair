#include <algorithm>
#include <iostream>
#include <array>

#include "./point/Point.hpp"
#include "./utils/readFile.hpp"
#include "./closestPair.hpp"

bool compareX(Point a, Point b){
    return a.x_coor < b.x_coor;
}

bool compareY(Point a, Point b){
    return a.y_coor < b.y_coor;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please specify a filename\n";
        return 1;
    }

    // // get all points from the csv file
    std::vector<Point> points_x = readFile(argv[1]);
    // // copies over points to another vector
    std::vector<Point> points_y = readFile(argv[1]);

    // sort points_x by x coordinates
    std::sort(points_x.begin(), points_x.end(), compareX);
    // sort points_y by x coordinates
    std::sort(points_y.begin(), points_y.end(), compareY);

    // run closest pair function
    ClosestPair pair = closestPair(points_x, points_y);

    // Print Results
    std::cout << "Closest Pair: \n";
    std::cout << "(" << pair.pair[0].x_coor << ", " << pair.pair[0].y_coor << ")\n";
    std::cout << "(" << pair.pair[1].x_coor << ", " << pair.pair[1].y_coor << ")\n";
    std::cout << "Distance: " << pair.distance << "\n";

    return 0;
}