#include<iostream>
#include"List.h"
#include"Enum.h"


int main()
{
	List l();
	std::cin >> l;
	std::cout << l;
	setlocale(LC_ALL, "Ru");
	try
	{
	}
	catch (Mistakes mistake)
	{
		switch (mistake)
		{
		case Invalid_size:
			std::cout << "�������� ������";
			exit(0);
		case Invalid_index:
			std::cout << "�������� ������";
			exit(1);
		default:
			std::cout << "���-�� ����� �� ���";
			exit(-1);
		}
	}
	return 0;
}