
#include "Header.h"

using namespace std;

PHotel CreateHotel()
{

	
	PHotel NewNode = new Auto; // указвтель на новый узел.
	cout << "Введите название машины:";
	gets_s(NewNode->model);
	//strcpy(NewNode->name, nm);
	cout << "Введите страну производства:";
	gets_s(NewNode->country);
	//strcpy(NewNode->addres, nm);
	cout << "Введите дату изготовления:";
	gets_s(NewNode->date);
	//strcpy(NewNode->telephone, nm);
	cout << "Введите мощность двигателя:";
	cin >> NewNode->power;
	cout << "Введите цену машины:";
	cin >> NewNode->price;
	cin.get();
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;

}


void Insertr(PAuto& Root, PAuto elem)
{
	//элемент создаётся в меню
	if (!Root)
	{
		Root = elem;
		return;
	}
	else
	{
		if ((strcmp(Root->model, elem->model) > 0))
		{
			if (Root->left == NULL)
			{
				Root->left = elem;
			}
			else
			{
				Insert(Root->left, elem);
			}
		}
		else
		{
			if (Root->right == NULL)
			{
				Root->right = elem;
			}
			else
			{
				Insert(Root->right, elem);
			}
		}

	}
}

void Insert(PAuto& Root, PAuto elem)
{
	//элемент создаётся в меню
	if (!Root)
	{
		Root = elem;
		return;
	}
	else
	{
		if ((strcmp(Root->model, elem->model) < 0))
		{
			if (Root->left == NULL)
			{
				Root->left = elem;
			}
			else
			{
				Insert(Root->left, elem);
			}
		}
		else
		{
			if (Root->right == NULL)
			{
				Root->right = elem;
			}
			else
			{
				Insert(Root->right, elem);
			}
		}

	}
}
int iLout = 1;//костыль для рекурсии
void BTprintLKP(PAuto Root)
{
	
	if (Root->left != NULL)
	{
		BTprintLKP(Root->left);
	}
		cout << iLout++ << "|" << setw(14) << Root->model << "|" << setw(20) << Root->country << "|" << setw(10) << Root->date << "|" << setw(24) << Root->power << "|" << setw(14) << Root->price << "|" << setw(24) << Root->right << "|" << setw(24) << Root->left << "|" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	if (Root->right != NULL)
	{
		BTprintLKP(Root->right);
	}
	
}

void BTprintPKL(PAuto Root)
{
	if (Root->right != NULL)
	{
		BTprintPKL(Root->right);
	}
	cout << iLout++ << "|" << setw(14) << Root->model << "|" << setw(20) << Root->country << "|" << setw(10) << Root->date << "|" << setw(24) << Root->power << "|" << setw(14) << Root->price << "|" << setw(24) << Root->right << "|" << setw(24) << Root->left << "|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	if (Root->left != NULL)
	{
		BTprintPKL(Root->left);
	}
}

void BTprint(PAuto Root)
{
	if (Root->left != NULL)
	{
		BTprint(Root->left);
	}
	if (Root->right != NULL)
	{
		BTprint(Root->right);
	}
	cout << iLout++ << "|" << setw(14) << Root->model << "|" << setw(20) << Root->country << "|" << setw(10) << Root->date << "|" << setw(24) << Root->power << "|" << setw(14) << Root->price << "|" << setw(24) << Root->right << "|" << setw(24) << Root->left << "|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
}

void BTout(PAuto Root)
{
	int choice;
	if (Root == NULL)
	{
		cout << "Дерево пусто. Нечего выводить."<<endl;
		return;
	}
	cout << "Выберите способ вывода:" << endl;
	cout << "1. В порядке обратном алфавитному (с лева на право):" << endl;
	cout << "2. В алфавитном порядке (с права на лево):" << endl;
	cout << "3. В произвольном порядке:" << endl;
	cin >> choice;

	cout << "№|" << setw(14) << "Название машины" << "|" << setw(20) << "Страна" << "|" << setw(10) << "Дата производства" << "|" << setw(24) << "Мощность" << "|" << setw(14) << "Цена" << "|" << setw(24) << "Адрес правого сына " << "|" << setw(24) << "Адрес левого сына " << "|" << endl;
	cout << "=============================================================================================================================================" << endl;
	switch (choice)
	{
	case 1: BTprintLKP(Root); break;
	case 2: BTprintPKL( Root); break;
	case 3: BTprint(Root); break;
	default: cout << " " << endl;
	}
	
	cout << "==============================================================================================================================================" << endl;
	iLout = 1;

}

void BToutOneEl(PAuto Root)
{
	if (Root == NULL)
	{
		cout << "Дерево пусто. Нечего выводить." << endl;
		return;
	}
	

	cout << "№|" << setw(14) << "Название машины" << "|" << setw(20) << "Страна" << "|" << setw(10) << "Дата производства" << "|" << setw(24) << "Мощность" << "|" << setw(14) << "Цена" << "|" << setw(24) << "Адрес правого сына " << "|" << setw(24) << "Адрес левого сына " << "|" << endl;
	cout << "=============================================================================================================================================" << endl;
	cout << iLout++ << "|" << setw(14) << Root->model << "|" << setw(20) << Root->country << "|" << setw(10) << Root->date << "|" << setw(24) << Root->power << "|" << setw(14) << Root->price << "|" << setw(24) << Root->right << "|" << setw(24) << Root->left << "|" << endl;

	cout << "==============================================================================================================================================" << endl;
	iLout = 1;

}

PAuto Find(PAuto Root)
{
	char NewWord[100];
	cout << "Введите название машины, котору. хотите найти:" << endl;
	gets_s(NewWord);
	PAuto R = Findr(Root, NewWord);
	if (R)	return R;
	else cout << "Такой машины не существует, либо название введено неверно.";
	return R;
}
PAuto Findr(PAuto Root, char * name)
{
	if (Root == NULL)
	{
		cout << "Дерево пусто" << endl;
		return NULL;
	}

	if (strcmp(Root->name, name)==0)
	{
		return Root;
	}
	if (Root) {
		if (strcmp(Root->name, name) > 0)
		{
			Findr(Root->right, name);
		}
		else Findr(Root->left, name);
	}
	else return NULL;

}
// Рекурсивная функция для вычисления высоты заданного бинарного дерева
int Height(PAuto Root)
{
	// базовый случай: пустое дерево имеет высоту 0
	if (Root == NULL) {
		return 0;
	}

	// повторяем для левого и правого поддерева и учитываем максимальную глубину
	return 1 + max(Height(Root->left), Height(Root->right));
}

int NodeCount(PAuto node)
{
	if (node->left == NULL && node->right == NULL)
		return 1;
	int left, right;
	if (node->left != NULL)
		left = NodeCount(node->left);
	else
		left = 0;
	if (node->right != NULL)
		right = NodeCount(node->right);
	else
		right = 0;

	return left + right + 1;
}

void DeleteNode(PAuto Root)
{
	PAuto dElem = Find(Root);
	DeleteNoder(dElem);

}
void DeleteNoder(PAuto Tree)//удаление узла со всеми потомками
{
	if (Tree == NULL)
	{
		cout << "Дерево пустое" << endl;
		return;
	}
	if (Tree == NULL)
	{
		cout << "Дерево пустое" << endl;
		return;
	}
	DeleteNoder(Tree->left);
	DeleteNoder(Tree->right);
	delete Tree;
}
void Destroy(PAuto Root)
{
	DeleteNoder(Root);
}

void Menu()
{
	printf("\n Меню\n ");
	printf("\n Вы попали в программу создания дерева машин. \n Выберите опцию:\n ");

	printf("\n1.	Добавление нового элемента.\n ");//это есть
	printf("\n2.	Длина дерева.\n ");//это есть
	printf("\n3.	Поиск машины по названию.\n ");//это есть
	printf("\n4.	Высота дерева.\n ");
	printf("\n5.	Вывод всех машин на экран.\n ");
	printf("\n6.	Освобождение памяти, выделенной для дерева.\n ");
	printf("\n7.	Выход из программы.\n ");
	

	printf("\nВведите желаемую опцию:\n ");
}



