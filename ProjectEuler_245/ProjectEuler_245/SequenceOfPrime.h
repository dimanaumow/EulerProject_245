#pragma once
#include <iostream> 
#include <vector>

using std::vector; 

class SequenceOfPrime 
{
public: 
	SequenceOfPrime(long x);
	long Sum—alculate(); 
private: 
	long x;
	vector<long> primes;
	vector<long> sumPrimes;
	const int MAXSIEVELIMIT = 100000; 

	void SetPriemsVectors();
	vector<bool> SivePrimes();
	long LegandresSumCalculate(long x, long a);
	long SumOfOddNumbersCalculate(long a, long b); 
};
