/*
 * Program: Binary Search Program
 *
 * Binary search is a searching algorithm that searches for an element in a sorted array.
 * It works by repeatedly dividing the search interval in half.
 * Begin with an interval covering the whole array.
 * If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
 * Otherwise narrow it to the upper half.
 * Repeatedly check until the value is found or the interval is empty.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int low, int high, int data, int &steps) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // OR int mid = (high + low) / 2
        steps++;
        cout << "Step " << steps << ": Searching in range [" << low << ", " << high << "]" << endl;
        if (arr[mid] == data) {
            return mid;
        } else if (arr[mid] < data) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int data = 40; // Element to be searched
    int steps = 0; // Counter for total steps

    cout << "Binary Search Demonstration" << endl;
    cout << "---------------------------" << endl;
    cout << "Array: {";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "}" << endl;
    cout << "Searching for element: " << data << endl << endl;

    int result = binarySearch(arr, 0, n - 1, data, steps);

    if (result != -1) {
        cout << endl << "Element found at index " << result << endl;
    } else {
        cout << endl << "Element not found in array" << endl;
    }

    cout << "Total steps taken: " << steps << endl;

    return 0;
}

