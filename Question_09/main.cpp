/*
 * main.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */
#include "Queue.hpp"

int main(int argc, char *argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	queue.appendTail('d');

	char cElem;
	try
	{
		cElem = queue.deleteHead();
		cElem = queue.deleteHead();
		cElem = queue.deleteHead();
		cElem = queue.deleteHead();
		queue.appendTail('e');
		cElem = queue.deleteHead();
	} catch (const char *msg)
	{
		std::cout << msg << std::endl;
	}
	std::cout << "cElem: " << cElem << std::endl;
	return 0;
}

