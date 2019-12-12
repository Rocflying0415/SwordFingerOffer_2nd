/*
 * main.cpp
 *
 *  Created on: 2019年12月11日
 *      Author: Zuokp
 */
#include <iostream>

int DoubleArray[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

bool findArrayElements(int* DoubleDimensionalArray, int rows, int columns, int number);

int main(int argc, char* argv[])
{
	int elem = 2;
	if (findArrayElements(static_cast<int*>(*DoubleArray), 4, 4, elem))
		std::cout << "contains this element(" << elem << ")." << std::endl;
	else
		std::cout << "no contains this element(" << elem << ")." << std::endl;
	return 0;
}

bool findArrayElements(int* DoubleDimensionalArray, int rows, int columns, int number)
{
	bool found = false;

	if (nullptr != DoubleDimensionalArray && rows > 0 && columns > 0)
	{
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0)
        {
            if(DoubleDimensionalArray[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if(DoubleDimensionalArray[row * columns + column] > number)
                --column;
            else
                ++row;
        }
	}
	return found;
}


