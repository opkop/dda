#include <iostream>
using namespace std;

// Function to print the subset
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Backtracking function to find all subsets that sum up to the target sum
void subsetSum(int set[], int subset[], int n, int subsetSize, int total, int sum, int index) {
    if (total == sum) {
        printSubset(subset, subsetSize);  // Print the current subset
        return;
    }

    if (index == n || total > sum) {
        return;  // If the total exceeds sum or we reach the end of the set, backtrack
    }

    // Include the current element in the subset and recurse
    subset[subsetSize] = set[index];
    subsetSum(set, subset, n, subsetSize + 1, total + set[index], sum, index + 1);

    // Exclude the current element from the subset and recurse
    subsetSum(set, subset, n, subsetSize, total, sum, index + 1);
}

// Wrapper function for the backtracking algorithm
void findSubsets(int set[], int n, int sum) {
    int subset[n];  // Array to store the current subset
    subsetSum(set, subset, n, 0, 0, sum, 0);
}

int main() {
    int set[] = {2,3,4,5};  // The set of numbers
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 10;  // The target sum

    cout << "Subsets of the set that sum up to " << sum << " are:\n";
    findSubsets(set, n, sum);

    return 0;
}
