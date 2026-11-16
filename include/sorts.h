#ifndef SORTS_H
#define SORTS_H

#include <vector>

void bubbleSort(std::vector<int>& arr, bool show = false);
void mergeSort(std::vector<int>& arr, int left, int right, bool show = false);
void quickSort(std::vector<int>& arr, int low, int high, bool show = false);

#endif