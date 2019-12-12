/*
 * main.cpp
 *
 *  Created on: 2019年12月9日
 *      Author: Zuokp
 */
#include <windows.h>

#include "SingletonA.hpp"
#include "SingletonB.hpp"

const int NUMBER_OF_THREADS = 10;

void* funTestA(void* args)
{
	int* value;
	value = reinterpret_cast<int*>(args);

	std::cout << "value[A]: " << *value << std::endl;

	SingletonA* pInstance = nullptr;
	while (true)
	{
		pInstance = SingletonA::getInstance();
		if (nullptr != pInstance)
		{
			std::cout << "SingletonA: " << pInstance << std::endl;
			Sleep(6000);
		}
	}
	return (reinterpret_cast<void*>(0));
}

void* funTestB(void* args)
{
	int* value;
	value = reinterpret_cast<int*>(args);

	std::cout << "value[B]: " << *value << std::endl;

	SingletonB* pInstance = nullptr;
	while (true)
	{
		pInstance = SingletonB::getInstance();
		if (nullptr != pInstance)
		{
			std::cout << "SingletonB: " << pInstance << std::endl;
			Sleep(6000);
		}
	}
	return (reinterpret_cast<void*>(0));
}

int main(int argc, char* argv[])
{
	pthread_t pidA[NUMBER_OF_THREADS];
	pthread_t pidB[NUMBER_OF_THREADS];

	int i;

	for (i = 0; i < NUMBER_OF_THREADS; ++i)
	{
		if (-1 == pthread_create(&pidA[i], nullptr, funTestA, &i))
		{
			std::cout << "Thread creation failed!" << std::endl;
			return -1;
		}
		Sleep(500);
	}
	//
	for (i = 0; i < NUMBER_OF_THREADS; ++i)
	{
		if (-1 == pthread_create(&pidB[i], nullptr, funTestB, &i))
		{
			std::cout << "Thread creation failed!" << std::endl;
			return -1;
		}
		Sleep(500);
	}
	for (i = 0; i < NUMBER_OF_THREADS; ++i)
	{
		if (-1 == pthread_join(pidA[i], nullptr))//阻塞
		{
			std::cout << "fail to recollect thread!" << std::endl;
			return -1;
		}
		std::cout << "##########################################" << std::endl;
		if (-1 == pthread_join(pidB[i], nullptr))
		{
			std::cout << "fail to recollect thread!" << std::endl;
			return -1;
		}
	}
	return 0;
}



