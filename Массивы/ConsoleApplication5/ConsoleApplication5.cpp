// ConsoleApplication5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "cstdio"
#include "iostream"
#include "cstdlib"


double processArray(double sarr[], unsigned int N, double marr[], double rarr[])
{
	for (unsigned int i = 0; i < N; i++) //���������� ��������
	{
		sarr[i] = 20 + rand() % (100 - 20);
	}

	double minnum = sarr[0]; unsigned int minindex = 1; //����������� �������� �������, ����������� ������

	for (unsigned int i = 1; i < N; i++) //����� ������������ ��������
	{
		if (sarr[i] < minnum)
		{
			minnum = sarr[i];
			minindex = i;
		}
	}

	for (unsigned int i = 0; i < N; i++) //������������ ������� (sarr - minnum)
	{
		marr[i] = sarr[i] - minnum;
	}

	for (unsigned int i = 0; i < N; i++) //������������ ����������������� �������
	{
		if (i <= minindex) { rarr[i] = sarr[i]; }
		else { rarr[i] = sarr[minindex]; }
	}

	return minnum;

}

void PrintAllArrays(double sarr[], unsigned int N, char message[]) //����� ���� ��������
{
	std::cout << message << ": ";
	for (unsigned int i = 0; i < N; i++)
	{
		std::cout << sarr[i] << " ";
	}
	std::cout << std::endl;
	
}

int main()
{
	const unsigned short int DLINA = 15; 
	double sourcearray[DLINA] = { 0.0 }; //�������� ������
	double minusarray[DLINA] = { 0.0 }; //������ ��� ��������� min(sourcearray)
	double resultarray[DLINA] = { 0.0 }; //���������������� ������

	srand(0);

	double paRes = processArray(sourcearray, DLINA, minusarray, resultarray);
	std::cout << "Minimal massive element: " << paRes << std::endl << "----" << std::endl;
	PrintAllArrays(sourcearray, DLINA, "Source massive");
	PrintAllArrays(minusarray, DLINA, "Massive after decrement");
	PrintAllArrays(resultarray, DLINA, "Result massive");
	system("pause");

	return 0;
}
