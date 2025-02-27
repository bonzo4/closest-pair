# Closest Pair of Points Problem

## Problem:
Given a list of (x, y) coordinates on a cartesian plane, find the two points that have least euclidean distance.

## Solution:
1. Sort the list into decreasing

## Instructions
Compile with: g++ -g $(find src/ -type f -iregex ".*\.cpp") -o closest-pair

Run ./closest-pair RandomPoints*.csv 
 - RandomPoints50.csv
 - RandomPoints100.csv
 - RandomPoints500.csv
 - RandomPointsFull.csv

## File Structure
 - src/* - All source code files
 - src/main.cpp - Entry point
 - src/closestPair.cpp - main logic
 - src/point/Point.hpp - Point Struct
 - src/utils/* - Utility Functions
 - src/utils/getDistance.cpp - Calculates euclidean distance of 2 points
 - src/utils/readFiles.cpp - Returns a vector of points given a csv file
