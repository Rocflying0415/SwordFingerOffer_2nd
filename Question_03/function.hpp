/*
 * function.hpp
 *
 *  Created on: 2020年3月1日
 *      Author: Zuokp
 */

#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_
#include <iostream>

/*
 *长度为n的数组，取值为0～n-1,数组改变
 */
bool duplicate(int numbers[], const int length, int *duplication);
/*
 *长度为n+1的数组，取值为1～n,数组未改变--注：至少有一个重复数字
 **/
int getDuplication(const int numbers[], const int length);
int countRange(const int numbers[], const int length, int start, int end);

bool duplicate(int numbers[], const int length, int *duplication)
{
	if (nullptr == numbers || 0 >= length)
		return false;
	int i, temp;
	for (i = 0; i < length; ++i)
	{
		if (0 > numbers[i] || length <= numbers[i])
			return false;
	}
	for (i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i]  == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int getDuplication(const int numbers[], const int length)
{
	if (length <= 0)
		return -1;
	int start = 1;
	int end = length - 1;
	int middle, count;

	while (start <= end)
	{
		middle = (start + end) >> 1;
		count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start) + 1)
			end = middle;
		else
			start = middle + 1;
	}
	return 0;
}

int countRange(const int numbers[], const int length, int start, int end)
{
	int i = 0;
	int count = 0;

	for (; i < length; ++i)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}
#endif /* FUNCTION_HPP_ */
