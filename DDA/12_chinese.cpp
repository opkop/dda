#include <iostream>
using namespace std;

// Function to find the GCD using the Euclidean algorithm
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to find the modular inverse of a with respect to m
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to apply the Chinese Remainder Theorem
int chineseRemainder(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i]; // Calculate product of all num[] values

    int result = 0;

    for (int i = 0; i < k; i++) {
        int pp = prod / num[i]; // Calculate partial product
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int num[] = {3, 5, 7};       // Moduli
    int rem[] = {2, 3, 2};       // Remainders
    int k = sizeof(num) / sizeof(num[0]);

    int x = chineseRemainder(num, rem, k);

    cout << "x is " << x << endl;

    return 0;
}
