#ifndef UTILS_H
#define UTILS_H

#include <vector>

// Generate a vector of random numbers between 1 and maxValue
std::vector<int> generateRandomArray(int size, int maxValue = 100);

// Print an array as a row of numbers
void printArray(const std::vector<int>& arr);

// Check whether an array is sorted in ascending order
bool isSortedArray(const std::vector<int>& arr);

#endif