/*
 * main.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */
#include <iostream>
#include <cstring>

void replaceBlankSpace(char szString[], const int nMaxLength);

int main(int argc, char* argv[])
{
	const int nMaxLength = 128;
	char szString[nMaxLength] = {'\0'};

	std::cout << "Please input string(< 128):";

	std::cin.getline(szString, nMaxLength);
	std::cout << szString << std::endl;
	replaceBlankSpace(szString, nMaxLength);
	std::cout << szString << std::endl;

	return 0;
}

void replaceBlankSpace(char szString[], const int nMaxLength)
{
	int i = 0;
	int nOriginLength = 0;
	int nNumberOfSpaces = 0;

	while (szString[i] != '\0')
	{
		if (szString[i] == ' ')
			++nNumberOfSpaces;
		++i;
	}
	nOriginLength = i;
	int nNewLength = nOriginLength + nNumberOfSpaces * 2;

	if (nNewLength >= nMaxLength)
		return;
	int nIndexOfOrigin = nOriginLength;
	int nIndexOfNew = nNewLength;

	while (nIndexOfOrigin >= 0 && nIndexOfNew > nIndexOfOrigin)
	{
		if (szString[nIndexOfOrigin] == ' ')
		{
			szString[nIndexOfNew--] = '0';
			szString[nIndexOfNew--] = '2';
			szString[nIndexOfNew--] = '%';
		}
		else
			szString[nIndexOfNew--] = szString[nIndexOfOrigin];
		--nIndexOfOrigin;
	}
}
