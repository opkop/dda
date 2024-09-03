#include <iostream>

using namespace std;
int factorial(int n, int &steps) {
    steps++;
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1, steps);
    }
}

int main() {
    int n;
    cout << "Enter a number to find its factorial: ";
    cin >> n;

    int steps = 0;
    int result = factorial(n, steps);

    cout << "Factorial of " << n << " is " << result << endl;
    cout << "Total number of steps: " << steps << endl;

    return 0;
}
