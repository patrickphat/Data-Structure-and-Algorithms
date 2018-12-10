#include <iostream>
#include <fstream>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int Data;
	struct node *pNext;
	struct node *pPrev;
};
typedef struct node NODE;
struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void Init(LIST&l)
{
	l.pHead = l.pTail = NULL;
}
NODE* GetNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL) return NULL;
	p->Data = x;
	p->pNext = p;
	p->pPrev = p;
	return p;
}
void AddTail(LIST&l, NODE*p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		p->pNext = l.pHead;
		l.pHead->pPrev;
		l.pTail = p;
	}
}
void Input(LIST&l)
{
	int n;
	cout << "Nhap so phan tu: "; cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		NODE*p = GetNode(x);
		AddTail(l, p);
	}
}
void Output(LIST l)
{
	cout << endl;
	NODE *p = l.pHead;
	do
	{
		cout << p->Data << " ";
		p = p->pNext;
	} while (p != l.pHead);
	cout << endl;
}

void Random_File(int size)
{
	ofstream A("taptin.dat", ofstream::in | ofstream::out | ofstream::app | ofstream::binary);

	srand(time(NULL));
	for (int i = 0; i < size; i++)
		A << rand() % 100000 << " ";

	A.close();
}
void List_Input(list &l, int size)
{
	Init(l);
	node *p;
	int info;
	ifstream A("taptin.dat");
	for (int i = 0; i < size; i++)
	{
		A >> info;
		p = GetNode(info);
		AddTail(l, p);
	}
	A.close();
}
bool checkodd(LIST l)
{
	NODE*p = l.pHead;
	do
	{
		int value = p->Data;
		if (value % 2 == 1) return true;
		p = p->pNext;
	} while (p != l.pHead);
	return false;
}
NODE* GetMin(LIST l)
{
	NODE*p = l.pHead;
	NODE *target = l.pHead;
	do
	{
		int value = p->Data;
		if (value < target->Data)
		{
			target = p;
		}
		p = p->pNext;
	} while (p != l.pHead);
	return target;
}
void main()
{
	LIST l; int n; cout << "Nhap so phan tu: "; cin >> n;
	Random_File(n);
	List_Input(l, n);
	Output(l);
	if (checkodd(l)) cout << "\nAt least 1 odd number available!";
	cout << "\nAddress of min Node: " << GetMin(l) << " ";
	system("pause");
}