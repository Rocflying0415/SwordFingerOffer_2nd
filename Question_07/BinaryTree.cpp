/*
 * BinaryTree.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */

#include "BinaryTree.h"

BinaryTreeNode* constructBinaryTree(int *preOrder, int *inOrder, const int length)
{
	if (nullptr == preOrder || nullptr == inOrder || 0 >= length)
		return nullptr;
	return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length -1);
}

BinaryTreeNode* ConstructCore
(\
		int *startPreorder, int *endPreorder,
		int *startInorder, int *endInorder
)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode;
	if (nullptr == root)
		throw "Failed to allocate memory dynamically.";
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startInorder == *startPreorder)
			return root;
		else
			throw "Invalid input";
	}
	// 在中序遍历中找到根结点的值
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw "Invalid input.";

	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// 构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
				startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// 构建右子树
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
				rootInorder + 1, endInorder);
	}
	return root;
}

void showPreorder(BinaryTreeNode *root)
{
	if (nullptr != root)
	{
		std::cout << root->m_nValue << " ";
		showPreorder(root->m_pLeft);
		showPreorder(root->m_pRight);
	}
}
void showIntorder(BinaryTreeNode *root)
{
	if (nullptr != root)
	{
		showIntorder(root->m_pLeft);
		std::cout << root->m_nValue << " ";
		showIntorder(root->m_pRight);
	}
}

void showPostorder(BinaryTreeNode *root)
{
	if (nullptr != root)
	{
		showPostorder(root->m_pLeft);
		showPostorder(root->m_pRight);
		std::cout << root->m_nValue << " ";
	}
}
