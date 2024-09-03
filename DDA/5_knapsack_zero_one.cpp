#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    // dp[i][w] will be storing the maximum value that can be obtained with i items and a weight limit of w
    vector<vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp array
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity = 60; // Total capacity of the knapsack
    vector <int> weights = {20, 30, 40}; // Weights of the items
    vector<int> values = {50, 100, 130}; // Values of the items
    int n = weights.size(); // Number of items
 
    cout << "Maximum value in Knapsack = " << knapsack(capacity, weights, values, n) << endl;

    return 0;
}
