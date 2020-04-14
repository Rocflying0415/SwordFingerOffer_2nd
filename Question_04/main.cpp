/*
 * main.cpp
 *
 *  Created on: 2020年3月2日
 *      Author: Zuokp
 */
#include <iostream>

const int szData[][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };

bool findMatrixElem(const int *matrix, const int rows, const int columns, const int number);

int main(int argc, char *argv[])
{
	bool bFind = false;
	const int rows = 4;
	const int columns = 4;
	const int number = 7;

	bFind = findMatrixElem((int*)szData, rows, columns, number);

	if (bFind)
		std::cout << "Found it." << std::endl;
	else
		std::cout << "unfound it." << std::endl;
	return 0;
}

bool findMatrixElem(const int *matrix, const int rows, const int columns, const int number)
{
	bool bFind = false;

	int row = 0;
	int column = columns - 1;
	int nIndex;

	if ((nullptr == matrix) || (rows < 0) || (columns < 0))
		return bFind;
	while (row < rows && column >= 0)
	{
		nIndex = row * columns + column;

		std::cout << "matrix[" << row << "][" << column << "]: " << matrix[nIndex] << std::endl;
		if (matrix[nIndex] == number)
		{
			bFind = true;
			break;
		}
		else if (matrix[nIndex] > number)
			--column;
		else
			++row;
	}
	return bFind;
}

