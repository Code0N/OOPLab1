// Fright Night.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"


int factorial(int n) //���������
{
	int res = 1;
	if (n == 1) { return res; }
	else
	{
		for (int i = 1; i <= n; i++)
			res *= i;
	}
	return res;
}

void initializeSArr(int** arr, int n) //������������� ������� 5x5
{
	std::cout << "Print initialized array:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < n; j++)
		{
			*(*(arr + i) + j) = factorial(i) + factorial(j); //x[i][j] = x! + y!
			std::cout << std::setw(8) << *(*(arr + i) + j); //����� ������������������� ������� � �������
		}
	}
}

int* convertArrayto1D(int** arr, unsigned int n) //2D -> 1D
{
	int* resarr = new int[n*2]; //���������������� 1-������ ������
	unsigned int uindex = 0; //��� ������ � ���������������� ��������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i % 2) == 0) { continue; }
			*(resarr + uindex) = *(*(arr+i)+j); //������ ������ �������
			uindex++;
		}
	}
	return resarr;
}

void PrintResultArr(int *arr, unsigned int count) //������ ����������������� �������
{
	std::cout << std::endl << std::endl << "Result 1D massive:" << std::endl << std::endl;
	for (unsigned int i = 0; i < count; i++)
		std::cout << std::setw(3) << *(arr + i);
}

void freeArrMem(int **arr1, int *rarr) //������������ ������, ���������� ��������
{
	delete arr1;
	delete rarr;
}

int main()
{
	const unsigned int lsl = 5; //5
	const unsigned int hsl = lsl; // �� 5
	int** sourcearr = new int*[5]; //�������� ������������� �������
	for (unsigned int i = 0; i < hsl; i++)
		*(sourcearr + i) = new int[hsl];

	initializeSArr(sourcearr, lsl);
	int* resarr = convertArrayto1D(sourcearr, lsl);
	PrintResultArr(resarr, lsl + hsl);
	freeArrMem(sourcearr, resarr);

	std::cout << std::endl; //��� ������� ������
	system("pause"); //��������
    return 0;
}

