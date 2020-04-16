/*
 * main.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: rocflying
 */
#include <iostream>

typedef unsigned long long ULL;
typedef unsigned int UINT;

ULL Fibonacci(UINT n);//Recursive
ULL FibonacciNon(UINT n);//Non-recursive

int main(int argc, char* argv[])
{
	int n;
	std::cout << "Please enter the number of the Fibonacci sequence: ";
	std::cin >> n;
	if (0 > n)
		std::cerr << "Invalid input!" << std::endl;
	else
	{
		std::cout << "Fibonacci(" << n << ") = " << FibonacciNon(n) << std::endl;
		std::cout << "Fibonacci(" << n << ") = " << Fibonacci(n) << std::endl;
	}
	return 0;
}

ULL Fibonacci(UINT n)
{
	if (n <= 1)
		return n;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

ULL FibonacciNon(UINT n)
{
	if (n <= 1)
		return n;
	ULL fibOne = 0ull, fibTwo = 1ull;
	ULL fibN = 0ull;
	UINT i = 2;
	for (; i <= n; ++i)
	{
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}
	return fibN;
}

