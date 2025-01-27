#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the first subarray
    int n2 = right - mid;    // Size of the second subarray

    // Create temporary arrays
    int leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left array
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements of the right array
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Prompt user for array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int array[n];

    // Input array elements from user
    cout << "Enter " << n << " integers in sorted order for two halves:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Assume the first half and second half are sorted
    int mid = n / 2 - 1;

    // Merge the two sorted halves
    merge(array, 0, mid, n - 1);

    // Print the merged array
    cout << "Merged array:" << endl;
    printArray(array, n);

    return 0;
}

