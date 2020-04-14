/*
 * main.cpp
 *
 *  Created on: 2020年2月25日
 *      Author: Zuokp
 */
#include "CMyString.h"

int main(int argc, char *argv[])
{
	const char *pStr = "Hello! Shenzhen.";
	CMyString str0(pStr);
	CMyString str1(str0);
	CMyString str2(3, '6');
	CMyString str3 = "";

	std::cout << str0 << std::endl;
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	str1 += str2;
	str0 = str1;
	std::cout << str1 << std::endl;
	std::cout << str0 << std::endl;
	str0 = pStr;
	std::cout << str0 << std::endl;
	str0 += "666";
	std::cout << str0 << std::endl;
	std::cout << str3 << std::endl;
	return 0;
}

