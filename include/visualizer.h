#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>

// Draw the array as horizontal bars in the terminal.
// highlightA and highlightB are indexes shown in red.
void visualize(const std::vector<int>& arr,
               int highlightA = -1,
               int highlightB = -1,
               int delayMs = 100);

#endif