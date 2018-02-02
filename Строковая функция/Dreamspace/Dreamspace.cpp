// Dreamspace.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "cstdio"


const char* reversestrchr(const char* s, int c) //��� �������
{
	unsigned int index = 0; //������ ������� ��������� ��������� � ������
	const char* rofs = NULL; //��������� �� ������ ��������� ��������� � ������
	while (s[index] != '\0')
	{
		if (s[index] == c) { rofs = s + index; break; } index++;
	}
	return rofs;
};

int main()
{
	char teststring[] = "This is - a senseless test string. You think your life is different than that from her?"; //�������� ������
	const char* original_function = strchr(teststring, '.'); //����� ������������ strchr
	const char* reversed_function = reversestrchr(teststring, '.'); //����� ������������ �������
	printf("Source String: %s\nStandard function: %s\nReversed function: %s\n", teststring, original_function, reversed_function); 
	getchar(); //�������� ����� ��������� ����
    return 0;
}

