// Dreamspace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "cstdio"


const char* reversestrchr(const char* s, int c) //Моя функция
{
	unsigned int index = 0; //Индекс первого вхождения подстроки в строку
	const char* rofs = NULL; //Указатель на первое вхождение подстроки в строку
	while (s[index] != '\0')
	{
		if (s[index] == c) { rofs = s + index; break; } index++;
	}
	return rofs;
};

int main()
{
	char teststring[] = "This is - a senseless test string. You think your life is different than that from her?"; //Тестовая строка
	const char* original_function = strchr(teststring, '.'); //Вызов оригинальной strchr
	const char* reversed_function = reversestrchr(teststring, '.'); //Вызов ревервсивной функции
	printf("Source String: %s\nStandard function: %s\nReversed function: %s\n", teststring, original_function, reversed_function); 
	getchar(); //Задержка перед закрытием окна
    return 0;
}

