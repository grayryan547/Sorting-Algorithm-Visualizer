#include "sorts.h"
#include "visualizer.h"
#include <algorithm>

// ---------- Bubble Sort ----------
void bubbleSort(std::vector<int>& arr, bool show) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                if (show) visualize(arr, j, j + 1);
            }
        }
        if (!swapped) break; // Already sorted
    }
}

// ---------- Merge Sort ----------
static void mergeHalves(std::vector<int>& arr, int left, int mid, int right, bool show) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
        if (show) visualize(arr, left + (int)k, -1);
    }
}

void mergeSort(std::vector<int>& arr, int left, int right, bool show) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, show);
    mergeSort(arr, mid + 1, right, show);
    mergeHalves(arr, left, mid, right, show);
}

// ---------- Quick Sort ----------
static int partitionArray(std::vector<int>& arr, int low, int high, bool show) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            if (show) visualize(arr, i, j);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    if (show) visualize(arr, i + 1, high);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, bool show) {
    if (low < high) {
        int pi = partitionArray(arr, low, high, show);
        quickSort(arr, low, pi - 1, show);
        quickSort(arr, pi + 1, high, show);
    }
}