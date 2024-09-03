

#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int target, int& steps) {
    steps = 0;
    for (int i = 0; i < size; ++i) {
        steps++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int size, target, steps;
    cout << "Enter size of array: "; cin >> size;
    int* arr = new int[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) cin >> arr[i];
    cout << "Enter target element: "; cin >> target;
    int index = sequentialSearch(arr, size, target, steps);
    if (index != -1) cout << "Element found at index " << index << endl;
    else cout << "Element not found." << endl;
    cout << "Steps taken: " << steps << endl;
    delete[] arr;
    return 0;
}
