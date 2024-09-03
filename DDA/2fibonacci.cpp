#include <iostream>
using namespace std;
int fibonacci(int n, int &steps) {
    steps++;
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1, steps) + fibonacci(n - 2, steps);
    }
}

int main() {
    int n;
    cout << "Enter the number of terms in Fibonacci series: ";
    cin >> n;

    int steps = 0;
    cout << "Fibonacci series: ";
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i, steps) << " ";
    }
    cout << endl;

    cout << "Total number of steps: " << steps << endl;

    return 0;
}
