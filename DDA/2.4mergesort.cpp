/*
 * Program: Merge Sort
 *
 * Merge sort is a divide and conquer algorithm that divides the array into two halves, calls itself for the two halves, and then merges the two sorted halves.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 *
 */

#include <iostream>
using namespace std;

void mergeSort(int[], int, int, int&);
void merge(int[], int, int, int, int&);

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int stepCount = 0;
    mergeSort(arr, 0, n - 1, stepCount);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total number of steps: " << stepCount << endl;

    return 0;
}

void mergeSort(int arr[], int l, int r, int& stepCount)
{
    if (l < r)
    {
        // find the middle index
        int m = l + (r - l) / 2;

        // sort the first and second halves
        mergeSort(arr, l, m, stepCount);
        mergeSort(arr, m + 1, r, stepCount);

        // merge the sorted halves
        merge(arr, l, m, r, stepCount);

        stepCount++; // Increment step count for merge operation
    }
}

void merge(int arr[], int l, int m, int r, int& stepCount)
{
    int i, j, k;
    int n1 = m - l + 1; // size of left subarray
    int n2 = r - m;     // size of right subarray

    // create temp arrays
    int L[n1], R[n2];

    // copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i]; // l is the starting index of the array
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j]; // m is the middle index of the array
    }

    // merge the temp arrays back into arr[l..r]

    // initial index of first subarray
    i = 0;
    // initial index of second subarray
    j = 0;
    // initial index of merged subarray
    k = l;

    // compare the elements of L[] and R[] and copy the smaller element to arr[]
    while (i < n1 && j < n2)
    {
        stepCount++; // Increment step count for comparison
        if (L[i] <= R[j])
        {
            // copy the element of L[] to arr[]
            arr[k] = L[i];
            // increment the index of L[]
            i++;
        }
        else
        {
            // copy the element of R[] to arr[]
            arr[k] = R[j];
            // increment the index of R[]
            j++;
        }
        // increment the index of arr[]
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}



