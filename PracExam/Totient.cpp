#include <iostream>
using namespace std;

// Helper function to find GCD (used for Rule 3)
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Helper function to check if a number is prime (used for Rule 2)
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Implementing the 3 rules from Topic 18
int phi(int n) {
    // Rule 1: phi(1) = 0 (as per your specific assignment)
    if (n == 1) return 0;

    // Rule 2: phi(p) = p - 1 if p is prime
    if (isPrime(n)) return n - 1;

    // Rule 3: phi(m * n) = phi(m) * phi(n) if m, n are relatively prime
    for (int i = 2; i < n; i++) {
        if (n % i == 0) { // i is a factor
            int m = i;
            int remaining_n = n / i;
            if (gcd(m, remaining_n) == 1) { // They are relatively prime
                return phi(m) * phi(remaining_n);
            }
        }
    }

    // Default case: manual calculation if no coprime factors found
    // (This handles cases like phi(4) or phi(9) which don't split into coprimes)
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) count++;
    }
    return count;
}

int main() {
    int testValues[] = {1, 7, 12, 15}; // Examples for Rules 1, 2, and 3

    cout << "--- Topic 18: Totient Rules ---" << endl;
    for (int n : testValues) {
        cout << "phi(" << n << ") = " << phi(n) << endl;
    }

    return 0;
}