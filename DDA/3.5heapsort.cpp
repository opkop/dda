#include <iostream>
using namespace std;

// Global variable to count steps
int total_steps = 0;

void heapify(int[], int, int);
void heapSort(int[], int);

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

    heapSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nTotal number of steps: " << total_steps << endl;

    return 0;
}

void heapSort(int arr[], int n)
{
    total_steps = 0; // Reset step counter for each new sort

    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // one by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    total_steps++; // Increment step count for each call to heapify
    int largest = i;   // initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // if left child is larger than root
    if (l < n)
    {
        total_steps++; // Increment step count for comparison
        if (arr[l] > arr[largest])
        {
            largest = l;
        }
    }

    // if right child is larger than largest so far
    if (r < n)
    {
        total_steps++; // Increment step count for comparison
        if (arr[r] > arr[largest])
        {
            largest = r;
        }
    }

    // if largest is not root
    if (largest != i)
    {
        total_steps++; // Increment step count for swap
        swap(arr[i], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

