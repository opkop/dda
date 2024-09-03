

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size, int& steps) {
    steps = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            steps++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                steps++;
            }
        }
    }
}

int main() {
    int size, steps;
    cout << "Enter size of array: "; cin >> size;
    int* arr = new int[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) cin >> arr[i];
    bubbleSort(arr, size, steps);
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << "\nSteps taken: " << steps << endl;
    delete[] arr;
    return 0;
}

