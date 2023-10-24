#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include "quick_sort.h"

using namespace std;
using namespace std::chrono;

template <typename T>
bool isSorted(const vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> values(10000);

    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };

    // Fill up the vector
    generate(values.begin(), values.end(), f);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the sorting function, here quickSort
    quickSort<int>(values);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Subtract timepoints to get duration.
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by quickSort: "
        << duration.count() << " microseconds" << endl;

    // Check if the vector is sorted
    if (isSorted(values)) {
        cout << "The vector is sorted." << endl;
    }
    else {
        cout << "The vector is not sorted." << endl;
    }

    return 0;
}
