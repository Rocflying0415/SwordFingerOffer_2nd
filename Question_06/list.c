/*
 * list.c
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */
#include "list.h"

const int NODE_SIZE = sizeof(Node);

List initList()
{
	List head = (List) malloc(NODE_SIZE);

	if (head)
	{
		head->next = NULL;
		head->value = INT_MIN;
	}
	return head;
}

List createNodeOfList(int value)
{
	List pNode = (List) malloc(NODE_SIZE);

	if (pNode)
	{
		pNode->value = value;
		pNode->next = NULL;
	}
	return pNode;
}

void insertNodeByFront(List *head, int value)
{
	if (NULL == (*head))
		return;
	List pNode = createNodeOfList(value);
	List pNext = NULL;
	if (pNode)
	{
		pNext = (*head)->next;
		(*head)->next = pNode;
		pNode->next = pNext;
	}
}

void insertNodeByTail(List *head, int value)
{
	if (NULL == (*head))
		return;
	List pNode = createNodeOfList(value);
	List p = (*head)->next;
	List q = (*head);
	while (p)
	{
		q = p;
		p = p->next;
	}
	q->next = pNode;
}

void showList(List head)
{
	if (NULL == head)
		return;
	List p = head->next;
	while (p)
	{
		p->next == NULL ? printf("%d\n", p->value) : printf("%d ", p->value);
		p = p->next;
	}
}

void showRecursiveReverse(List head)
{
	if (NULL != head)
	{
		showRecursiveReverse(head->next);
		printf("%d ", head->value);
	}
}

void showNonRecursiveReverse(List head)
{
	if (NULL == head || NULL == head->next)
		return;
	List p = head->next;
	List q = p->next;
	p->next = NULL;

	while (q)
	{
		p = q->next;
		q->next = head->next;
		head->next = q;
		q = p;
	}
}

void destroyList(List head)
{
	List p = head;
	List q = NULL;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}
