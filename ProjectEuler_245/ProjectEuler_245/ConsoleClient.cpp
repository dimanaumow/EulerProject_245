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
	vector<int> primes = GetVectorOfSumPrimes(10); 
	clock_t end = clock(); 
	double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
	cout << seconds; 
	return 0; 
}