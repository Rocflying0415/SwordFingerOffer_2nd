/*
 * main.c
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */
#include "list.h"

int main(int argc, char* argv[])
{
	int i;
	List head = initList();

	for (i = 0; i < 10; ++i)
		insertNodeByFront(&head, i);
	showList(head);
	showRecursiveReverse(head->next);
	putchar('\n');
	puts("----------------------");
	showNonRecursiveReverse(head);
	showList(head);
	puts("----------------------");
	destroyList(head);

	head = initList();

	for (i = 0; i < 10; ++i)
		insertNodeByTail(&head, i);
	showList(head);
	destroyList(head);

	return 0;
}



