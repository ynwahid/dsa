// Insertion sort in Cpp
// Source: https://www.youtube.com/watch?v=i-SKeOcBwko
#include <iostream>
#include <map>

void printArray(int array[], size_t length) {
    std::cout << "[";
    for (size_t i = 0; i < length; ++i) {
        std::cout << array[i];
        std::cout << (i != length - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

void insertionSort(int array[], size_t length, bool mode=0) {
    int value;
    size_t hole;

    printArray(array, length);

    if (mode == 0) {
        for (size_t i = 1; i < length; ++i) {
            value = array[i];
            hole = i;

            while (hole > 0 && array[hole-1] > value) {
                array[hole] = array[hole-1];
                hole--;
            }
            array[hole] = value;
            printArray(array, length);
        }
    } else {
        for (size_t i = 1; i < length; ++i) {
            value = array[i];
            hole = i;

            while (hole > 0 && array[hole-1] < value) {
                array[hole] = array[hole-1];
                hole--;
            }
            array[hole] = value;
            printArray(array, length);
        }
    }
}

int main() {
    bool mode = 0;
    std::map<int, std::string> sortingMode = {
        {0, "Ascending"},
        {1, "Descending"}
    };

    int array[] = {
        7, 2, 4, 1, 5, 3, 4
    };
    
    // Size of array
    size_t length = std::size(array);

    // Array before sorted
    std::cout << "Array Before Sorted:" << std::endl;
    printArray(array, length);

    // Perform sorting
    std::cout << std::endl;
    std::cout << "Array is being Sorted:" << std::endl;
    insertionSort(array, length, mode);

    // Array after sorted
    std::cout << std::endl;
    std::cout << "Array Sorted in " << sortingMode[mode] << ":" << std::endl;
    printArray(array, length);
    
    return 0;
}