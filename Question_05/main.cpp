/*
 * main.cpp
 *
 *  Created on: 2019年12月11日
 *      Author: Zuokp
 */
#include <iostream>

const int LENGTH = 100;

void replaceBlank(char* array, int length);

int main(int argc, char* argv[])
{
	char szData[LENGTH] = "welcome to shenzhen";

	std::cout << "Original: " << szData << std::endl;
	replaceBlank(szData, LENGTH);
	std::cout << "New: " << szData << std::endl;
	return 0;
}

void replaceBlank(char* array, int length)
{
	if (nullptr == array || 0 >= length)
		return;
	int nOriginalLength = 0;
	int nNumberSpaces = 0;

	int i = 0;
	while (array[i] != '\0')
	{
		++nOriginalLength;
		if (' ' == array[i])
			++nNumberSpaces;
		++i;
	}
	if (0 == nNumberSpaces)
		return;
	int nNewLength = nOriginalLength + nNumberSpaces * 2;
	if (nNewLength >= length)
		return;
	int nIndexOriginal = nOriginalLength - 1;
	int nIndexNew = nNewLength - 1;

	while ((nIndexOriginal >= 0) && (nIndexNew > nIndexOriginal))
	{
		if (array[nIndexOriginal] == ' ')
		{
			array[nIndexNew--] = '0';
			array[nIndexNew--] = '2';
			array[nIndexNew--] = '%';
		}
		else
			array[nIndexNew--] = array[nIndexOriginal];
		--nIndexOriginal;
	}
}


