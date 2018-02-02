// Fright Night.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"


int factorial(int n) //факториал
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

void initializeSArr(int** arr, int n) //Инициализация массива 5x5
{
	std::cout << "Print initialized array:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < n; j++)
		{
			*(*(arr + i) + j) = factorial(i) + factorial(j); //x[i][j] = x! + y!
			std::cout << std::setw(8) << *(*(arr + i) + j); //Вывод инициализированного массива в консоль
		}
	}
}

int* convertArrayto1D(int** arr, unsigned int n) //2D -> 1D
{
	int* resarr = new int[n*2]; //Результатирующий 1-мерный массив
	unsigned int uindex = 0; //Для работы с результатирующим массивом
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i % 2) == 0) { continue; }
			*(resarr + uindex) = *(*(arr+i)+j); //Только чётные столбцы
			uindex++;
		}
	}
	return resarr;
}

void PrintResultArr(int *arr, unsigned int count) //Печать результатирующего массива
{
	std::cout << std::endl << std::endl << "Result 1D massive:" << std::endl << std::endl;
	for (unsigned int i = 0; i < count; i++)
		std::cout << std::setw(3) << *(arr + i);
}

void freeArrMem(int **arr1, int *rarr) //Освобождение памяти, выделенной массивам
{
	delete arr1;
	delete rarr;
}

int main()
{
	const unsigned int lsl = 5; //5
	const unsigned int hsl = lsl; // на 5
	int** sourcearr = new int*[5]; //создание динамического массива
	for (unsigned int i = 0; i < hsl; i++)
		*(sourcearr + i) = new int[hsl];

	initializeSArr(sourcearr, lsl);
	int* resarr = convertArrayto1D(sourcearr, lsl);
	PrintResultArr(resarr, lsl + hsl);
	freeArrMem(sourcearr, resarr);

	std::cout << std::endl; //Для красоты вывода
	system("pause"); //Задержка
    return 0;
}

