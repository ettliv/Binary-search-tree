
#include "Header.h"

using namespace std;

PHotel CreateHotel()
{

	
	PHotel NewNode = new Auto; // ��������� �� ����� ����.
	cout << "������� �������� ������:";
	gets_s(NewNode->model);
	//strcpy(NewNode->name, nm);
	cout << "������� ������ ������������:";
	gets_s(NewNode->country);
	//strcpy(NewNode->addres, nm);
	cout << "������� ���� ������������:";
	gets_s(NewNode->date);
	//strcpy(NewNode->telephone, nm);
	cout << "������� �������� ���������:";
	cin >> NewNode->power;
	cout << "������� ���� ������:";
	cin >> NewNode->price;
	cin.get();
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;

}


void Insertr(PAuto& Root, PAuto elem)
{
	//������� �������� � ����
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
	//������� �������� � ����
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
int iLout = 1;//������� ��� ��������
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
		cout << "������ �����. ������ ��������."<<endl;
		return;
	}
	cout << "�������� ������ ������:" << endl;
	cout << "1. � ������� �������� ����������� (� ���� �� �����):" << endl;
	cout << "2. � ���������� ������� (� ����� �� ����):" << endl;
	cout << "3. � ������������ �������:" << endl;
	cin >> choice;

	cout << "�|" << setw(14) << "�������� ������" << "|" << setw(20) << "������" << "|" << setw(10) << "���� ������������" << "|" << setw(24) << "��������" << "|" << setw(14) << "����" << "|" << setw(24) << "����� ������� ���� " << "|" << setw(24) << "����� ������ ���� " << "|" << endl;
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
		cout << "������ �����. ������ ��������." << endl;
		return;
	}
	

	cout << "�|" << setw(14) << "�������� ������" << "|" << setw(20) << "������" << "|" << setw(10) << "���� ������������" << "|" << setw(24) << "��������" << "|" << setw(14) << "����" << "|" << setw(24) << "����� ������� ���� " << "|" << setw(24) << "����� ������ ���� " << "|" << endl;
	cout << "=============================================================================================================================================" << endl;
	cout << iLout++ << "|" << setw(14) << Root->model << "|" << setw(20) << Root->country << "|" << setw(10) << Root->date << "|" << setw(24) << Root->power << "|" << setw(14) << Root->price << "|" << setw(24) << Root->right << "|" << setw(24) << Root->left << "|" << endl;

	cout << "==============================================================================================================================================" << endl;
	iLout = 1;

}

PAuto Find(PAuto Root)
{
	char NewWord[100];
	cout << "������� �������� ������, ������. ������ �����:" << endl;
	gets_s(NewWord);
	PAuto R = Findr(Root, NewWord);
	if (R)	return R;
	else cout << "����� ������ �� ����������, ���� �������� ������� �������.";
	return R;
}
PAuto Findr(PAuto Root, char * name)
{
	if (Root == NULL)
	{
		cout << "������ �����" << endl;
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
// ����������� ������� ��� ���������� ������ ��������� ��������� ������
int Height(PAuto Root)
{
	// ������� ������: ������ ������ ����� ������ 0
	if (Root == NULL) {
		return 0;
	}

	// ��������� ��� ������ � ������� ��������� � ��������� ������������ �������
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
void DeleteNoder(PAuto Tree)//�������� ���� �� ����� ���������
{
	if (Tree == NULL)
	{
		cout << "������ ������" << endl;
		return;
	}
	if (Tree == NULL)
	{
		cout << "������ ������" << endl;
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
	printf("\n ����\n ");
	printf("\n �� ������ � ��������� �������� ������ �����. \n �������� �����:\n ");

	printf("\n1.	���������� ������ ��������.\n ");//��� ����
	printf("\n2.	����� ������.\n ");//��� ����
	printf("\n3.	����� ������ �� ��������.\n ");//��� ����
	printf("\n4.	������ ������.\n ");
	printf("\n5.	����� ���� ����� �� �����.\n ");
	printf("\n6.	������������ ������, ���������� ��� ������.\n ");
	printf("\n7.	����� �� ���������.\n ");
	

	printf("\n������� �������� �����:\n ");
}



