/*
 * list.h
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*List With Header node*/
typedef struct stNode
{
	int value;
	struct stNode *next;
} Node, *List;

extern const int NODE_SIZE;

List initList();/*Initialize the linked list*/
List createNodeOfList(int value);
void insertNodeByFront(List *head, int value);
void insertNodeByTail(List *head, int value);
void showList(List head);
void showRecursiveReverse(List head);
void showNonRecursiveReverse(List head);
void destroyList(List head);

#endif /* LIST_H_ */
