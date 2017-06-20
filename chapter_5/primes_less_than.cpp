#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// fundamental theorem of arithmetic, or unique factorization theorem: every 
// integer greater than 1 either is prime itself or is the product of prime numbers 
// and this product is unique up to the order of the factors
int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> flag(n, true);
    flag[0] = flag[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (flag[i]) { // i is prime
            for (int j = i * i; j < n; j += i) flag[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++) cnt += flag[i];
    return cnt;
}

int main(int argc, char **argv) {
    int n;
    while (n) {
        cin >> n;
        printf("the number of primes less than %d: %d\n", n, countPrimes(n));
    }
    return 0;
}
