#include <iostream>
using namespace std;

int* array;  // Pointer to the array
int size;    // Size of the array

// Function to perform binary search to find the first occurrence of 1
int binary_search() {
    int beg = 0, end = size - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;
        if ((array[mid] == 1) && ((mid == 0) || (array[mid - 1] == 0))) {
            return mid;  // First occurrence of 1 found
        } else if (array[mid] == 0) {
            beg = mid + 1;  // Ignore the left half
        } else {
            end = mid - 1;  // Ignore the right half
        }
    }
    return -1;  // 1 is not present in the array
}

int main() {
    cout << "Enter the Size of Array: ";
    cin >> size;

    array = new int[size];

    cout << "Enter " << size << " elements (sorted, consisting of 0s and 1s): ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int pos = binary_search();
    if (pos == -1) {
        cout << "\nItem is not Present";
    } else {
        cout << "\nItem found at index " << pos;
    }

    delete[] array;  // Free the allocated memory
    return 0;
}
