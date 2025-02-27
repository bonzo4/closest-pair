#include <math.h>

#include "../point/Point.hpp"

double getDistance(Point point1, Point point2) {
    double x_diff = point1.x_coor - point2.x_coor;
    double y_diff = point1.y_coor - point2.y_coor;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2)); 
}