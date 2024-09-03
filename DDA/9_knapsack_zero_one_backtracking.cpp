#include <iostream>
using namespace std;

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Unbounded Knapsack problem using backtracking
void unboundedKnapsack(int W, int weights[], int values[], int n, int currentWeight, int currentValue, int& maxValue, int index) {
    // Base case: if currentWeight exceeds capacity, backtrack
    if (currentWeight > W) {
        return;
    }

    // Update maxValue if currentValue is greater
    maxValue = max(maxValue, currentValue);

    // Recur for all items starting from current index
    for (int i = index; i < n; i++) {
        // Include the current item and recur
        unboundedKnapsack(W, weights, values, n, currentWeight + weights[i], currentValue + values[i], maxValue, i);
    }
}

int main() {
    int weights[] = {6,9,14,20,30};  // Weights of items
    int values[] = {3,16,18,25,40}; // Values of items
    int W = 20;                    // Maximum weight of the knapsack
    int n = sizeof(weights) / sizeof(weights[0]); // Number of items

    int maxValue = 0; // Variable to store the maximum value found

    // Solve the Unbounded Knapsack problem using backtracking
    unboundedKnapsack(W, weights, values, n, 0, 0, maxValue, 0);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
