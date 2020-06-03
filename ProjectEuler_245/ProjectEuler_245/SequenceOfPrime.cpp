#include "SequenceOfPrime.h" 
#include <cmath>
using std::vector; 

#pragma region constructors
SequenceOfPrime::SequenceOfPrime(long x) {
    this->x = x; 
    this->SetPriemsVectors(); 
}
#pragma endregion

#pragma region AccesserMethods
void SequenceOfPrime::SetPriemsVectors() {
    if (x <= 0) {
        throw "The count of numbers must be positive."; 
    }

    vector<bool> sieve = SivePrimes();
    long sum = 0;
    for (int i = 2; i <= x; i++) {
        if (sieve[i] == false) {
            primes.push_back(i); 
            sumPrimes.push_back(sum + i);
            sum += i;
        }
    }
}

vector<bool> SequenceOfPrime::SivePrimes() {
    vector<bool>sieve(x + 1);
    sieve[0] = true;
    sieve[1] = true;

    for (int i = 2; i * i <= x; i++) {
        if (sieve[i] == false) {
            for (int j = i * i; j <= x; j += i) {
                sieve[j] = true;
            }
        }
    }

    return sieve;
}
#pragma endregion

#pragma region MathLogik
long SequenceOfPrime::SumÑalculate() {
    if (x < MAXSIEVELIMIT) {
        return sumPrimes[sumPrimes.size() - 1]; 
    }
    long square = (int)floor(sqrt((double)x));
    return (sumPrimes[sumPrimes.size() - 1] + LegandresSumCalculate(x, primes.size())); 
}

long SequenceOfPrime::LegandresSumCalculate(long x, long a) {
    if (a == 1) {
        return SumOfOddNumbersCalculate(a, x); 
    }
    return LegandresSumCalculate(x, a - 1) - primes[a - 1] * LegandresSumCalculate(x / primes[a - 1], a - 1); 
}

long SequenceOfPrime::SumOfOddNumbersCalculate(long a, long b) {
    if (a % 2 == 0) {
        a = a + 1;
    }
    if (b % 2 == 0) {
        b = b - 1;
    }
    return ((a + b) / 2) * (((b - a) / 2) + 1);
}
#pragma endregion
