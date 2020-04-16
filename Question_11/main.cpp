/*
 * main.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: rocflying
 */
#include <iostream>
#include <climits>
#include "MyException.h"

int Min(const int *numbers, const int length);
int MinInOrder(const int *numbers, const int low, const int high);

int main(int argc, char *argv[])
{
	int nMin;
	/*1, 2, 3, 4, 5, 6*/
	const int szData[] = { 3, 4, 5, 6, 1, 2 };
	const int length = sizeof(szData) / sizeof(szData[0]);
	try
	{
		nMin = Min(szData, length);
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		exit(0);
	}
	std::cout << "Min: " << nMin << std::endl;
	return 0;
}

int Min(const int *numbers, const int length)
{
	if (nullptr == numbers || 0 >= length)
		throw MyException("Invalid parameter!");

	int low = 0;
	int high = length - 1;
	int mid = low;

	while (numbers[low] >= numbers[high])
	{
		if (high - low == 1)
		{
			mid = high;
			break;
		}
		mid = (low + high) >> 1;
		if (numbers[low] == numbers[high] && numbers[mid] == numbers[low])
			return MinInOrder(numbers, low, high);
		if (numbers[mid] >= numbers[low])
			low = mid;
		else if (numbers[mid] <= numbers[high])
			high = mid;
	}
	return numbers[mid];
}

int MinInOrder(const int *numbers, const int low, const int high)
{
	int result = numbers[low];
	int i = low + 1;
	for (; i <= high; ++i)
	{
		if (result > numbers[i])
			result = numbers[i];
	}
	return result;
}

