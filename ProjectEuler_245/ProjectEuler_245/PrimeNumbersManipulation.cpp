#include "PrimeNumbersManipulation.h" 

#pragma region sieve of Eratosthenes
std::vector<bool> GetIndexOfPrimeVector(int n) {

	std::vector<bool>SieveIndexVector(n + 1);
	SieveIndexVector[0] = true; 
    SieveIndexVector[1] = true; 
    for (int i = 2; i * i <= n; i++) {
        if (SieveIndexVector[i] == false) {
            for (int j = i * i; j <= n; j += i) {
                SieveIndexVector[j] = true;
            }
        }
    }

    return SieveIndexVector;
}

std::vector<int> GetVectorOfSumPrimes(int n)
{
    std::vector<bool> source = GetIndexOfPrimeVector(n);
    std::vector<int> result(0); 
    int sumPrimes = 0; 
    for (int i = 2; i <= n; i++)
    {
        if (source[i] == false)
        {
            result.push_back(sumPrimes + i); 
            sumPrimes = sumPrimes + i; 
        }
    }
    return result; 
}
#pragma endregion

#pragma region Legandre's formula

#pragma endregion