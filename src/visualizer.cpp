#include "visualizer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>

void visualize(const std::vector<int>& arr, int highlightA, int highlightB, int delayMs) {
    std::cout << "\033[2J\033[H"; // Clear the screen

    for (size_t i = 0; i < arr.size(); i++) {
        if ((int)i == highlightA || (int)i == highlightB) {
            std::cout << "\033[31m"; // Red for highlighted items
        }
        std::cout << std::setw(3) << arr[i] << " | "
                  << std::string(arr[i] / 2, '#')
                  << "\033[0m\n"; // Reset color
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
}