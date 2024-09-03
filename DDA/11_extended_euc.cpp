#include <iostream>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1; // To store results of recursive call
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using the results of the recursive call
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a = 18;
    int b = 72;
    int x, y;

    int gcd = extendedGCD(a, b, x, y);

    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;
    cout << "Coefficients x and y are: " << x << " and " << y << endl;
    cout << "Linear combination: " << a << "*" << x << " + " << b << "*" << y << " = " << gcd << endl;

    return 0;
}
