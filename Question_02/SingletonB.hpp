/*
 * SingletonB.hpp
 *
 *  Created on: 2019年12月9日
 *      Author: Zuokp
 */

#ifndef SINGLETONB_HPP_
#define SINGLETONB_HPP_
#include "SingletonA.hpp"

class SingletonB //饿汉模式
{
public:
	static SingletonB* getInstance();
	~SingletonB() {}
private:
	SingletonB() = default;
	SingletonB(const SingletonB& other) = default;
	SingletonB& operator = (const SingletonB& other) = default;

	static SingletonB* pInstance;
};

SingletonB* SingletonB::pInstance = new SingletonB;

SingletonB* SingletonB::getInstance()
{
	return pInstance;
}
#endif /* SINGLETONB_HPP_ */
