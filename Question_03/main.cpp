/*
 * main.cpp
 *
 *  Created on: 2020年3月1日
 *      Author: Zuokp
 */
#include "function.hpp"

int main(int argc, char *argv[])
{
	int szData[] = { 2, 3, 1, 0, 2, 5, 3 };
	int szValue[] = {2, 3, 5, 4, 3, 2, 6, 7};
	int length = sizeof(szData) / sizeof(szData[0]);
	bool bFind = false;
	int nNum = -1, i;

	bFind = duplicate(szData, length, &nNum);

	if (bFind)
		std::cout << "nNum: " << nNum << std::endl;
	for (i = 0; i < length; ++i)
		i + 1 != length ? std::cout << szData[i] << " " : std::cout << szData[i] << std::endl;
	length = sizeof(szValue) / sizeof(szValue[0]);
	nNum = getDuplication(szValue, length);
	std::cout << "nNum: " << nNum << std::endl;
	return 0;
}

