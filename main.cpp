#include<iostream>
#include"List.h"
#include"Enum.h"


int main()
{
	setlocale(LC_ALL, "Ru");
	List list(5);
	std::cin >> list;
	list[2] = 19;
	std::cout << list;
	try
	{
	}
	catch (Mistakes mistake)
	{
		switch (mistake)
		{
		case Invalid_size:
			std::cout << "Неверный размер";
			exit(0);
		case Invalid_index:
			std::cout << "Неверный индекс";
			exit(1);
		default:
			std::cout << "Что-то пошло не так";
			exit(-1);
		}
	}
	return 0;
}