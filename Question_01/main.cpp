/*
 * main.cpp
 *
 *  Created on: 2019年12月9日
 *      Author: Zuokp
 */

#include "CMyString.h"

int main(int argc, char* argv[])
{
	CMyString strTest("welcome to shenzhen.");
	CMyString strTest1(strTest);
	CMyString strTest2 = strTest1;

	//strTest2 = strTest1;

	strTest.show();
	strTest1.show();
	strTest2.show();
	return 0;
}



