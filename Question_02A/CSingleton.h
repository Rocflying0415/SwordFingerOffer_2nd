/*
 * CSingleton.h
 *
 *  Created on: 2020年2月26日
 *      Author: Zuokp
 */

#ifndef CSINGLETON_H_
#define CSINGLETON_H_
#include <iostream>
#include <thread>
#include <unistd.h>

#define PID_THREADS 10

class CSingleton
{
public:
	static CSingleton* getInstance();
protected:
	CSingleton() = default;
	CSingleton(const CSingleton& other) = default;
	CSingleton& operator = (const CSingleton& other) = default;
	~CSingleton();
private:
	static CSingleton* m_pInstance;
	static pthread_mutex_t  mutexLock;

};

CSingleton* CSingleton::m_pInstance = nullptr;
pthread_mutex_t CSingleton::mutexLock = PTHREAD_MUTEX_INITIALIZER;

CSingleton* CSingleton::getInstance()
{
	if (nullptr == m_pInstance)
	{
		pthread_mutex_lock(&mutexLock);
		if (nullptr == m_pInstance)
			m_pInstance = new CSingleton;
		pthread_mutex_unlock(&mutexLock);
	}
	return m_pInstance;
}

CSingleton::~CSingleton()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}
#endif /* CSINGLETON_H_ */
