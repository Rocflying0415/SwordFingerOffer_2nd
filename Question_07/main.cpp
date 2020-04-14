/*
 * main.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */
#include "BinaryTree.h"

int main(int argc, char* argv[])
{
	BinaryTreeNode *root = nullptr;

	int szPreOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int szInOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	const int length = sizeof(szPreOrder) / sizeof(szPreOrder[0]);

	try
	{
		root = constructBinaryTree(szPreOrder, szInOrder, length);
	} catch (const char *msg)
	{
		std::cerr << msg << std::endl;
	}
	if (nullptr != root)
		std::cout << "the address of root is " << root << std::endl;
	std::cout << "Preorder: ";
	showPreorder(root);
	putchar('\n');

	std::cout << "Inorder: ";
	showIntorder(root);
	putchar('\n');

	std::cout << "Postorder: ";
	showPostorder(root);
	putchar('\n');
	return 0;
}



