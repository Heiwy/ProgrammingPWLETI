#include <iostream>
#include <ctime>
#include <chrono>

bool sorted = false;
bool generated = false;

void listArray(int* arr, int size) {
    std::cout << "\nArray elements: " << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void generateArray(int *arr, int *arr2, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 199 - 99;
        arr2[i] = arr[i];
    }

    generated = true;
    listArray(arr, size);
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std:: swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortArray(int* arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(arr, 0, size - 1);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    sorted = true;

    listArray(arr, size);

    std::cout << "\nElapsed time: " << elapsed.count() << " us" << std::endl;
}

void findMaxAndMinValues(int* arr, int* arr2, int size) {
    int max = arr[0], min = arr[0];
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\nMaximum: " << max << "\nMinimum: " << min << std::endl;

    std::cout << "\nElapsed time for non-sorted array: " << elapsed.count() << " us" << std::endl;

    if (sorted) {
        start = std::chrono::high_resolution_clock::now();

        min = arr2[0], max = arr2[size - 1];

        end = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Elapsed time for sorted array: " << elapsed.count() << " us" << std::endl;
    } else {
        std::cout << "\nThe array is not sorted!" << std::endl;
    }
}

void findAverage(int* arr, int size) {
    int max = arr[0], min = arr[0], count = 0;
    float average;

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    average = round((max + min) / 2);

    std::cout << "\nAverage: " << average << std::endl;
    std::cout << "Values indeces that are equal to the average: ";

    for (int i = 0; i < size; i++) {
        if (average == arr[i]) {
            std::cout << i << " ";
            count++;
        }
    }

    std::cout << "\nAmount of this values: " << count << std::endl;
}

void countLessThan(int n, int* arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < n) {
            count++;
        } else {
            break;
        }
    }

    std::cout << "Amount of elements that are less than " << n << ": " << count << std::endl;
}

void countGreaterhan(int value, int* arr, int size) {
    int count = 0;

    for (int i = size - 1; i > -1; i--) {
        if (arr[i] > value) {
            count++;
        } else {
            break;
        }
    }

    std::cout << "Amount of elements that are greater than " << value << ": " << count << std::endl;
}

void binarySearch(int value, int* arr, int size) {
    //Binary search
    int start = 0, end = size - 1, middle, found = false;
    auto startTime = std::chrono::high_resolution_clock::now();

    while (start <= end) {
        middle = start + (end - start) / 2;

        if (value == arr[middle]) {
            found = true;
            break;
        }

        if (value > arr[middle]) start = middle + 1;
        else end = middle - 1;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "\nElapsed time for binary search: " << elapsed.count() << " us" << std::endl;

    //Standard search
    startTime = std::chrono::high_resolution_clock::now();
    found = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            found = true;
        }

        if (found) break;
    }

    endTime = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Elapsed time for standard search: " << elapsed.count() << " us\n" << std::endl;

    if (found) {
        std::cout << "Value " << value << " is in the array!";
    } else {
        std::cout << "Value " << value << " is not in the array!";
    }
}

void swapElements(int* arr, int size) {
    int el1, el2;

    M:
    std::cout << "Type indeces of the elements to swap: ";
    std::cin >> el1 >> el2;
    if (el1 < 0 or el2 > 99) {
        std::cout << "The indeces are incorrect!" << std::endl;
        goto M;
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    int buf = arr[el1];
    arr[el1] = arr[el2];
    arr[el2] = buf;

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "\nElapsed time for elements swapping: " << elapsed.count() << " us" << std::endl;

}

int menu() {
    int choice, value;
    const int size = 100;
    int array[size],
        sortedArray[size];

    while (true) {
        system("cls");
        std::cout << "Available options: " << std::endl;
        std::cout << "  1. Generate array." << std::endl;
        std::cout << "  2. List non-sorted array." << std::endl;
        std::cout << "  3. List sorted array." << std::endl;
        std::cout << "  4. Sort the array." << std::endl;
        std::cout << "  5. Find maximum and minimum values." << std::endl;
        std::cout << "  6. Find the average of max and min values." << std::endl;
        std::cout << "  7. Count elements in the sorted array that are less than some value." << std::endl;
        std::cout << "  8. Count elements in the sorted array that are greater than some value." << std::endl;
        std::cout << "  9. Check whether some value is in the sorted array." << std::endl;
        std::cout << "  10. Swap elements in the array." << std::endl;
        std::cout << "  100. Exit program." << std::endl;
        std::cout << "\nSelect the option: ";
        std::cin >> choice;

        if (choice == 100) {
            return 0;
        }

        if (!generated and choice != 1) {
            std::cout << "Generate array first!" << std::endl;
            system("pause");
            continue;
        }

        if (!sorted and (choice == 3 or choice == 7 or choice == 8 or choice == 9)) {
            std::cout << "The array was not sorted!" << std::endl;
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            generateArray(array, sortedArray, size);
            break;
        case 2:
            listArray(array, size);
            break;
        case 3:
            listArray(sortedArray, size);
            break;
        case 4:
            sortArray(sortedArray, size);
            break;
        case 5:
            findMaxAndMinValues(array, sortedArray, size);
            break;
        case 6:
            findAverage(array, size);
            break;
        case 7:
            std::cout << "Type the value: ";
            std::cin >> value;
            countLessThan(value, sortedArray, size);
            break;
        case 8:
            std::cout << "Type the value: ";
            std::cin >> value;
            countGreaterhan(value, sortedArray, size);
            break;
        case 9:
            std::cout << "Type the value: ";
            std::cin >> value;
            binarySearch(value, sortedArray, size);
            break;
        case 10:
            swapElements(array, size);
            break;
        default:
            std::cout << "Such option does not exist! Type the correct one." << std::endl;
        }

        std::cout << std::endl;
        system("pause");
    }
}

int main() {
    menu();

    return 0;
}