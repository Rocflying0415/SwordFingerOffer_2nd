/*
 * main.cpp
 *
 *  Created on: 2019年12月11日
 *      Author: Zuokp
 */
#include "list.hpp"

int main(int argc, char* argv[])
{
	List head = initList();

	int i;
	for (i = 10; i > 0; --i)
	{
		//insertNodeByTail(head, i);
		insertNodeByFront(head, i);
	}
	showList(head);
	reverseNode(head);
	showList(head);
	deleteNode(head, 1);
	showList(head);
	reverseOutputNode(head->next);
	std::cout << std::endl;
	reverseByStack(head);
	destroyList(head);
	return 0;
}



