#include <iostream>
using namespace std;
// Function to find GCD using recursion
int gcd(int a, int b, int &steps) {
    steps++;
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b, steps);
    }
}
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int steps = 0;
    int result = gcd(a, b, steps);
    
    cout << "GCD of " << a << " and " << b << " is " << result << endl;
    cout << "Total number of steps: " << steps << endl;

    return 0;
}
