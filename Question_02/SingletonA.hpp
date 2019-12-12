/*
 * SingletonA.hpp
 *
 *  Created on: 2019年12月9日
 *      Author: Zuokp
 */

#ifndef SINGLETONA_HPP_
#define SINGLETONA_HPP_
#include <iostream>

#include <pthread.h>

class SingletonA //懒汉模式
{
public:
	static SingletonA* getInstance ();
	~SingletonA(){}
private:
	SingletonA() = default;
	SingletonA(const SingletonA& other) = default;
	SingletonA& operator = (const SingletonA& other) = default;
	static SingletonA* pInstance;
	static pthread_mutex_t  mutexLock;
};

pthread_mutex_t SingletonA::mutexLock = PTHREAD_MUTEX_INITIALIZER;
SingletonA* SingletonA::pInstance = nullptr;

SingletonA* SingletonA::getInstance()
{
	if (nullptr == pInstance)
	{
		pthread_mutex_lock(&mutexLock);
		if (nullptr == pInstance)
		{
			pInstance = new SingletonA;
		}
		pthread_mutex_unlock(&mutexLock);
	}
	return pInstance;
}
#endif /* SINGLETONA_HPP_ */
