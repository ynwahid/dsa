// Selection sort in Cpp
// Source: https://www.programiz.com/dsa/selection-sort, https://www.youtube.com/watch?v=GUDLRan2DWM&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=2
#include <iostream>
#include <map>
#include <iterator>

void printArray(int array[], size_t length) {
    std::cout << "[";
    for (size_t i = 0; i < length; ++i) {
        std::cout << array[i];
        std::cout << (i != length-1 ? ", " :"");
    }
    std::cout << "]" << std::endl;
}

void selectionSort(int array[], size_t length, bool mode=0) {
    size_t index;
    bool isSwapped;
    
    if (mode == 0) {
        for (size_t i = 0; i < length - 1; ++i) {
            index = i;
            isSwapped = 0;
            for (size_t j = i + 1; j < length; ++j) {
                if (array[j] < array[index]) {
                    index = j;
                    isSwapped = 1;
                }
            }
            if (isSwapped)
                std::swap(array[i], array[index]);
            printArray(array, length);
        }
    }

    else {
        for (size_t i = 0; i < length - 1; ++i) {
            index = i;
            isSwapped = 0;
            for (size_t j = i + 1; j < length; ++j) {
                if (array[j] > array[index]) {
                    index = j;
                    isSwapped = 1;
                }
            }
            if (isSwapped)
                std::swap(array[i], array[index]);
            printArray(array, length);
        }
    }
}

int main() {
    bool mode = 0;
    std::map<bool, std::string> sortingMode = {
        {0, "Ascending"},
        {1, "Descending"}
    };

    int data[] = {1, 2, 1, 3, 4, 5, 8 , 9, 5, 2, 3, 4, 1, 0, 9, 77, 1, 4};
    // int data[] = {-2, 45, 0, 11, -9};
    // int data[] = {2, 7, 4, 1, 5, 13, 4, 5};

    // Get array's length
    size_t length = std::size(data);

    // Before sorting
    std::cout << "Array Before Sorted:" << std::endl;
    printArray(data, length);
    std::cout << std::endl;

    std::cout << "Array is Sorting:" << std::endl;
    selectionSort(data, length, mode);

    std::cout << std::endl;
    std::cout << "Sorted Array in " << sortingMode[mode] << " Order:" << std::endl;
    printArray(data, length);

    return 0;
}