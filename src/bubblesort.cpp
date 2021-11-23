// Bubble sort in Cpp
// Source: https://www.programiz.com/dsa/bubble-sort
#include <iostream>
#include <utility>
#include <iterator>
#include <map>

// Perform bubble sort
void bubbleSort(int array[], size_t size, bool mode=0) {
    if (mode == 0) {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = i; j < size; ++j) {
                if (array[i] > array[j]) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }

    else {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = i; j < size; ++j) {
                if (array[i] < array[j]) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
}

// Print array
void printArray(int array[], size_t size) {
    std::cout << "[";
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << "\b\b";
    std::cout << "]" << std::endl;
}

int main() {
    bool mode = 0;
    std::map<bool, std::string> sortingMode = {
        {0, "Ascending"},
        {1, "Descending"}
    };

    int data[] = {-2, 45, 0, 11, -9};

    // Get array's size
    size_t length = std::size(data);

    // Before sorting
    std::cout << "Array Before Sorted:" << std::endl;
    printArray(data, length);

    bubbleSort(data, length);

    std::cout << "Sorted Array in " << sortingMode[mode] << " Order:" << std::endl;
    printArray(data, length);
}