#include "PrimeNumbersManipulation.h" 
#include <cmath>

#pragma region sieve of Eratosthenes
std::vector<bool> GetIndexOfPrimeVector(long n) {

	std::vector<bool>indexOfPrimes(n + 1);
	indexOfPrimes[0] = true; 
    indexOfPrimes[1] = true; 
    for (int i = 2; i * i <= n; i++) {
        if (indexOfPrimes[i] == false) {
            for (int j = i * i; j <= n; j += i) {
                indexOfPrimes[j] = true;
            }
        }
    }

    return indexOfPrimes;
}

std::vector<long> GetVectorOfSumPrimes(long n) {

    std::vector<bool> indexOfPrimes = GetIndexOfPrimeVector(n);
    std::vector<long> primes(0); 
    long sumPrimes = 0; 
    for (int i = 2; i <= n; i++) {
        if (indexOfPrimes[i] == false) {
            primes.push_back(sumPrimes + i); 
            sumPrimes = sumPrimes + i; 
        }
    }
    return primes; 
}
#pragma endregion

#pragma region Legandres_formula

long sumOfPrimes(long n) {   
    if (n < 100000) {
        std::vector<long> primes = GetVectorOfSumPrimes(n); 
        return primes[primes.size() - 1]; 
    }
    int squareRootOfn = (int)floor(sqrt((double)n)); 
    std::vector<long> primes = GetVectorOfSumPrimes(squareRootOfn); 
    return primes[primes.size() - 1] + s(n, primes.size(), primes); 
}


// s(x, a) = s(x, a - 1) -  prime[a] * s(x \ prime[a], a - 1). 
long s(long x, long a , std::vector<long> primes) {
    if (a == 1) {
        return SumOfOddNumbers(a, x); 
    }
    return s(x, a - 1, primes)
        - (primes[a + 1] - primes[a]) * s((x / (primes[a + 1] - primes[a])), a - 1, primes); 
}

long SumOfOddNumbers(long a, long b) {
    if (a % 2 == 0) {
        a = a + 1; 
    }
    if (b % 2 == 0) {
        b = b - 1; 
    }
    return ((a + b) / 2) * (((b - a) / 2) + 1); 
}
#pragma endregion