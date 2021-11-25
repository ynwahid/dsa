// Find prime numbers in interval (Sieve of Eratosthenes)
// Source: https://www.youtube.com/watch?v=eKp56OLhoQs
#include <iostream>
#include <vector>
#include <math.h>

// Print prime numbers
void printPrimeNumbers(int array[], size_t n, int counter) {
    std::cout << "[";
    for (int i = 0; i <= n; ++i) {
        if (array[i] == 1){
            counter--;
            std::cout << i;
            std::cout << (counter != 0 ? ", " : "");
        }
    }
    std::cout << "]" << std::endl;
}

// Finding prime numbers
void findPrimeNumbers(int primes[], size_t n) {
    int counter = n-1;
    for (size_t i = 0; i <= n; ++i) {
        primes[i] = 1;
    }

    primes[0] = 0;
    primes[1] = 0;

    for (size_t i = 2; i <= std::sqrt(n); ++i) {
        if (primes[i] == 1) {
            for (size_t j = 2; i*j <= n; ++j) {
                if (primes[i*j] == 0)
                    continue;
                primes[i*j] = 0;
                counter--;
            }
        }
    }
    printPrimeNumbers(primes, n, counter);
}

int main() {
    int n = 30;
    int array[n+1];

    findPrimeNumbers(array, n);

    return 0;
}