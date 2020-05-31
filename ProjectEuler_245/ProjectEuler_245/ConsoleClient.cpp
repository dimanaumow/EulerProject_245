#include <iostream> 
#include <time.h>
#include "PrimeNumbersManipulation.h" 
using std::cout; 
using std::cin; 
using std::vector; 

int main()
{	
	int count = 0; 
	clock_t start = clock();
	vector<long> primes = GetVectorOfSumPrimes(1000); 
	long sum = s(25, 3, primes); 
	clock_t end = clock(); 
	double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
	cout << sum << " " << seconds; 
	return 0; 
}