#include "utils.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

std::vector<int> generateRandomArray(int size, int maxValue) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, maxValue);

    for (int &x : arr) {
        x = dist(gen);
    }
    return arr;
}

void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << std::setw(4) << x;
    }
    std::cout << "\n";
}

bool isSortedArray(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}