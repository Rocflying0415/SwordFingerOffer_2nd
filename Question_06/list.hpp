/*
 * list.hpp
 *
 *  Created on: 2019年12月11日
 *      Author: Zuokp
 */

#ifndef LIST_HPP_
#define LIST_HPP_
#include <iostream>
#include <stack>

typedef struct stNode
{
	int m_nValue;
	struct stNode* next;
}Node, *List;

//const int NODE_SIZE = sizeof(Node);

List initList();
List createNode(int nValue);
void insertNodeByTail(List head, int nValue);//尾插
void insertNodeByFront(List head, int nValue);//前插
void showList(List head);
void destroyList(List head);
void reverseOutputNode(List head);//不改变链表顺序
void reverseByStack(List head);//通过STL中的stack来反向输出
void reverseNode(List head);//改变链表顺序
List initList()
{
	List pHead = new Node;

	if (nullptr != pHead)
	{
		pHead->m_nValue = 0;
		pHead->next = nullptr;
	}
	return pHead;
}
List createNode(int nValue)
{
	List pNode = new Node;

	if (nullptr != pNode)
	{
		pNode->m_nValue = nValue;
		pNode->next = nullptr;
	}
	return pNode;
}
void insertNodeByTail(List head, int nValue)
{
	if (nullptr == head)
		return;
	List pNewNode = createNode(nValue);
	if (nullptr != pNewNode)
	{
		List pStart = head;
		List pTemp = nullptr;
		while (nullptr != pStart)
		{
			pTemp = pStart;
			pStart = pStart->next;
		}
		pTemp->next = pNewNode;
	}
}
void insertNodeByFront(List head, int nValue)
{
	if (nullptr == head)
		return;
	List pNewNode = createNode(nValue);
	List pRearNode = head->next;

	if (nullptr != pNewNode)
	{
		head->next = pNewNode;
		pNewNode->next = pRearNode;
	}
}
void showList(List head)
{
	if (nullptr == head)
		return;
	List pStart = head->next;
	while(nullptr != pStart)
	{
		pStart->next ? (std::cout << pStart->m_nValue << " ") : (std::cout << pStart->m_nValue << std::endl);
		pStart = pStart->next;
	}
}
void destroyList(List head)
{
	List pStart = head;
	List pTemp = nullptr;

	while (nullptr != pStart)
	{
		pTemp = pStart->next;
		delete pStart;
		pStart = pTemp;
	}
}
void reverseOutputNode(List head)//递归（节点少），如果节点多会出现栈溢出。
{
	if (nullptr != head)
	{
		if (nullptr != head->next)
			reverseOutputNode(head->next);
		std::cout << head->m_nValue << " ";
	}
}
void reverseByStack(List head)
{
	if (nullptr == head)
		return;
	std::stack<List> stlStackForList;
	List pStart = head->next;
	List pTemp = nullptr;
	while (nullptr != pStart)
	{
		stlStackForList.push(pStart);
		pStart = pStart->next;
	}
	while (!stlStackForList.empty())
	{
		pTemp = stlStackForList.top();
		if (nullptr != pTemp)
			std::cout << pTemp->m_nValue << " ";
		stlStackForList.pop();
	}
	std::cout << std::endl;
}
void reverseNode(List head)
{
	if (nullptr == head || nullptr == head->next)
		return;
	List pRearNode = head->next;
	List pTemp = pRearNode->next;
	pRearNode->next = nullptr;
	while (nullptr != pTemp)
	{
		pRearNode = pTemp->next;
		pTemp->next = head->next;
		head->next = pTemp;
		pTemp = pRearNode;
	}
}
#endif /* LIST_HPP_ */
