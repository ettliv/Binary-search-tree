#include "Header.h"



int main()
{
	setlocale( LC_ALL, "rus");

	PAuto Root = NULL, elem = NULL;
	int choise;
	Menu();
	scanf_s("%d", &choise);
	cin.get();
	system("cls");// �������� �������
	do 
	{
		switch (choise)// ��������� �� ������� ������ ����
		{
		case(1):
			printf("\n1.	���������� ������ ��������.\n ");
			elem = CreateAuto();
			Insert(Root, elem);
			break;
				
		case(2):
			printf("\n2.	����� ������.\n ");
			cout << NodeCount(Root);
			
			break;
		case(3):
			printf("\n3.	����� ������ �� ��������.\n ");
			BToutOneEl(Find(Root));
			break;
	
		case(4):
			printf("\n4.	������ ������.\n ");
			cout << Height(Root);
			break;
	

		case(5):
			printf("\n5.	����� ���� ����� �� �����.\n\n");
			
			BTout(Root);
			break;

		case(6):
			printf("\n6.	������������ ������, ���������� ��� ������.\n ");

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

		default://���� ������ ����� ������ ����� ����� ��� ��� ������� � ������ �������� ����
			printf("\n �������� %d �� ������������� �� ����� ������� �� ����.\n ", choise);
			break;

		}
		
			Menu();
			scanf_s("%d", &choise);
			cin.get();
			
	} while (true);

	return 0;
}

