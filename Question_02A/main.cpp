/*
 * main.cpp
 *
 *  Created on: 2020年2月26日
 *      Author: Zuokp
 */
#include "CSingleton.h"

void* funcTest(void* args)
{
	int* pInt = reinterpret_cast<int*>(args);
	std::cout << "Value: " << *pInt << std::endl;
	CSingleton* pInstance = nullptr;
	while(1)
	{
		pInstance = CSingleton::getInstance();
		if (nullptr != pInstance)
			std::cout <<": " << pInstance << std::endl;
		sleep(1);
	}
	return reinterpret_cast<void*>(0);
}

int main(int argc, char* argv[])
{
	pthread_t  pid[PID_THREADS];

	int i = 0;

	for (; i < PID_THREADS; ++i)
	{
		if (-1 == pthread_create(&pid[i], nullptr, funcTest, &i))
		{
			std::cerr << "create failed!!!" << std::endl;
			exit(0);
		}
		sleep(1);
	}
	i = 0;
	for (; i < PID_THREADS; ++i)
		pthread_join(pid[i], nullptr);

	return 0;
}



