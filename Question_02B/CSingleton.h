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
	CSingleton& operator =(const CSingleton& other) = default;
	~CSingleton();
private:
	static CSingleton* m_pInstance;
};

CSingleton* CSingleton::m_pInstance = new CSingleton;

CSingleton* CSingleton::getInstance() { return m_pInstance;}

CSingleton::~CSingleton() { delete m_pInstance; m_pInstance = nullptr;}
#endif /* CSINGLETON_H_ */
