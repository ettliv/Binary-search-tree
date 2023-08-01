#include "Header.h"



int main()
{
	setlocale( LC_ALL, "rus");

	PAuto Root = NULL, elem = NULL;
	int choise;
	Menu();
	scanf_s("%d", &choise);
	cin.get();
	system("cls");// очищение консоли
	do 
	{
		switch (choise)// ветвление по каждому пункту меню
		{
		case(1):
			printf("\n1.	Добавление нового элемента.\n ");
			elem = CreateAuto();
			Insert(Root, elem);
			break;
				
		case(2):
			printf("\n2.	Длина дерева.\n ");
			cout << NodeCount(Root);
			
			break;
		case(3):
			printf("\n3.	Поиск машины по названию.\n ");
			BToutOneEl(Find(Root));
			break;
	
		case(4):
			printf("\n4.	Высота дерева.\n ");
			cout << Height(Root);
			break;
	

		case(5):
			printf("\n5.	Вывод всех машин на экран.\n\n");
			
			BTout(Root);
			break;

		case(6):
			printf("\n6.	Освобождение памяти, выделенной для дерева.\n ");

			Destroy(Root);
			Root = NULL;
			if (exit)
			{
				choise = 7;
				break;
			}
			break;

		case(7):
			
			if (Root)
			{
				Destroy(Root);
				//break;
			}
			return false;

		default://если вводим любое другое число кроме тех что описаны в кейсах приходим сюда
			printf("\n Значение %d не соответствует ни одной функции из меню.\n ", choise);
			break;

		}
		
			Menu();
			scanf_s("%d", &choise);
			cin.get();
			
	} while (true);

	return 0;
}

