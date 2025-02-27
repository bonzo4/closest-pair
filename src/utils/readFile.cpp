#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "../point/Point.hpp"

std::vector<Point> readFile(std::string filename) {
    std::vector<Point> points;
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return points;
    }
    
    std::string line;
    int lineNumber = 0;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        lineNumber++;
        std::stringstream ss(line);
        std::string token;
        
        Point point;
        
        try {
            std::getline(ss, token, ',');
            if (std::getline(ss, token, ',')) {
                point.x_coor = std::stod(token);
            } else {
                std::cerr << "Error parsing x_coor at line " << lineNumber << std::endl;
                continue;
            }
            
            if (std::getline(ss, token)) {
                point.y_coor = std::stod(token);
            } else {
                std::cerr << "Error parsing y_coor at line " << lineNumber << std::endl;
                continue;
            }
            
            points.push_back(point);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number format at line " << lineNumber 
                      << ": " << line << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Number out of range at line " << lineNumber 
                      << ": " << line << std::endl;
        }
    }
    
    file.close();

    return points;
}