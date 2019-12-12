/*
 * main.cpp
 *
 *  Created on: 2019年12月10日
 *      Author: Zuokp
 */
#include <iostream>

#define ARRAY_SIZE(array)    (sizeof(array) / sizeof(array[0]))
int szData[] = { 2, 3, 1, 0, 2, 5, 3 };
int szValue[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
const int LENGTH_ONE = ARRAY_SIZE(szData);
const int LENGTH_TWO = ARRAY_SIZE(szValue);

bool findDuplicateNumbers(int numbers[], int length, int* duplicate);
int findDuplicateNumbers(const int numbers[], int length);
int ZonalStatistics(const int numbers[], int length, int start, int end);
void Swap(int& a, int &b);

int main(int argc, char* argv[])
{
	int value = 0;

	if (findDuplicateNumbers(szData, LENGTH_ONE, &value))
		std::cout << "value: " << value << std::endl;
	if (-1 != (value = findDuplicateNumbers(szValue, LENGTH_TWO)))
		std::cout << "value: " << value << std::endl;
	return 0;
}
//Question_03_01
bool findDuplicateNumbers(int numbers[], int length, int* duplicate)
{
	if (0 >= length)
		return false;
	int i;
	for (i = 0; i < length; ++i)
	{
		if (0 > numbers[i] || numbers[i] > (length - 1))
			return false;
	}
	for (i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplicate = numbers[i];
				return true;
			}
			Swap(numbers[i], numbers[numbers[i]]);
		}
	}
	return false;
}
//Question_03_02
int findDuplicateNumbers(const int numbers[], int length)
{
	if (0 >= length)
		return -1; //时间复杂度和空间复杂度
	int i;

	for (i = 0; i < length; ++i)
	{
		if (1 > numbers[i] || numbers[i] > (length - 1))
			return -1;
	}
	int start = 1;
	int end = length - 1;
	int middle;
	int count;

	while (end >= start)
	{
		middle = ((end - start) >> 1) + start;
		count = ZonalStatistics(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

int ZonalStatistics(const int numbers[], int length, int start, int end)
{
	int i;
	int count = 0;

	for (i = 0; i < length; ++i)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}
void Swap(int& a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}
