#include <iostream>

// Static array is an array whose size is fixed at compile time. 
// The size of the array must be known at compile time.

// Dynamic array is an array whose size is fixed at run time.
// The size of the array must be known at run time.

// Static arrays are allocated on the stack, while dynamic arrays are allocated on the heap.
// Static arrays are deallocated automatically when the function returns, while dynamic arrays must be deallocated manually using delete[].
// Static arrays are faster than dynamic arrays, while dynamic arrays are more flexible.

int main() {
    static_array_example();
    dynamic_array_example();
    swap_array_example();
}


void static_array_example() {
    int array[5];
    for (int i = 0; i < 5; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


void dynamic_array_example() {
    int size;
    std::cout << "Please enter the size of the array: ";
    std::cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    delete[] array;
}

void swapArray(int* array1, int* array2) {
    int* temp = array1;
    array1 = array2;
    array2 = temp;
}

void swap_array_example() {
    int size;
    std::cout << "Please enter the size of the array: ";
    std::cin >> size;
    int* array1 = new int[size];
    int* array2 = new int[size];

    for (int i = 0; i < size; ++i) {
        array1[i] = i;
        array2[i] = size - i;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << array1[i] << " ";
    }

    std::cout << std::endl;
    
    for (int i = 0; i < size; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    // Swap the content of array1 and array2
    swapArray(array1, array2);

    for (int i = 0; i < size; ++i) {
        std::cout << array1[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << array2[i] << " ";
    }

    delete[] array1;
    delete[] array2;
}