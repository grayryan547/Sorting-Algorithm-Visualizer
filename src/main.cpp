#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>

#include "utils.h"
#include "sorts.h"
#include "visualizer.h"

using namespace std;
using namespace std::chrono;

// Time a sort on a copy of the data and return milliseconds
double timeSort(const string& name, vector<int> arr) {
    auto start = high_resolution_clock::now();

    if (name == "Bubble") bubbleSort(arr);
    else if (name == "Merge") mergeSort(arr, 0, (int)arr.size() - 1);
    else if (name == "Quick") quickSort(arr, 0, (int)arr.size() - 1);

    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed = end - start;

    if (!isSortedArray(arr)) {
        cout << "WARNING: " << name << " sort failed!\n";
    }
    return elapsed.count();
}

void runVisualDemo() {
    vector<int> data = generateRandomArray(20, 60);
    int choice;

    cout << "Choose algorithm:\n1. Bubble\n2. Merge\n3. Quick\n> ";
    cin >> choice;

    if (choice == 1) bubbleSort(data, true);
    else if (choice == 2) mergeSort(data, 0, (int)data.size() - 1, true);
    else if (choice == 3) quickSort(data, 0, (int)data.size() - 1, true);
    else {
        cout << "Invalid choice.\n";
        return;
    }

    visualize(data, -1, -1, 0);
    cout << "\nDone! Sorted successfully.\n";
}

void runBenchmark() {
    vector<int> sizes = {100, 1000, 5000, 10000};

    cout << "\n" << left << setw(10) << "Size"
         << setw(15) << "Bubble (ms)"
         << setw(15) << "Merge (ms)"
         << setw(15) << "Quick (ms)" << "\n";
    cout << string(55, '-') << "\n";

    for (int size : sizes) {
        vector<int> data = generateRandomArray(size, 100000);
        double bubbleTime = timeSort("Bubble", data);
        double mergeTime = timeSort("Merge", data);
        double quickTime = timeSort("Quick", data);

        cout << left << setw(10) << size
             << setw(15) << fixed << setprecision(3) << bubbleTime
             << setw(15) << mergeTime
             << setw(15) << quickTime << "\n";
    }
}

int main() {
    int option;
    cout << "=== Sorting Algorithm Visualizer ===\n";
    cout << "1. Visual demo\n2. Timing benchmark\n> ";
    cin >> option;

    if (option == 1) runVisualDemo();
    else if (option == 2) runBenchmark();
    else cout << "Invalid option.\n";

    return 0;
}