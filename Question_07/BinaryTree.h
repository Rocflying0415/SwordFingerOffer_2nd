/*
 * BinaryTree.h
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <exception>
#include <climits>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode()
	{
		m_nValue = INT_MIN;
		m_pLeft = nullptr;
		m_pRight = nullptr;
	}
};

BinaryTreeNode*  constructBinaryTree(int *preOrder, int *inOrder, const int length);
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
#endif /* BINARYTREE_H_ */
