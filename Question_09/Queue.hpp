/*
 * Queue.hpp
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include <iostream>
#include <stack>
#include <exception>

template<typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const T& elem);
	T deleteHead();
private:
	std::stack<T> m_stlStackT1;
	std::stack<T> m_stlStackT2;
};

template <typename T>
CQueue<T>::CQueue() { }

template <typename T>
CQueue<T>::~CQueue() { }

template <typename T>
void CQueue<T>::appendTail(const T& elem)
{
	m_stlStackT1.push(elem);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if (m_stlStackT2.empty())
	{
		while (!m_stlStackT1.empty())
		{
			T &t = m_stlStackT1.top();
			m_stlStackT1.pop();
			m_stlStackT2.push(t);
		}
	}
	if (m_stlStackT2.empty())
		throw "queue is empty!";
	T head = m_stlStackT2.top();
	m_stlStackT2.pop();
	return head;
}
#endif /* QUEUE_HPP_ */
