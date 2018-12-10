#include <iostream>
using namespace std;
struct Node
{
	int Data;
	struct Node *pNext;
};
typedef struct Node NODE;
struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;
void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}
NODE* GetNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL) return NULL;
	p->Data = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST&l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void InPut(LIST &l)
{
	int n;
	cout << "\nNhap vao so phan tu :"; cin >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		Node *p = GetNode(x);
		AddTail(l, p);
	}
}
void OutPut(LIST l)
{
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Data << " ";
	}
	
}
bool checkpos(LIST l)
{
	for (NODE *p = l.pHead; p; p = p->pNext)
	{
		if (p->Data < 0) return false;
	}
	return true;
}
void interchangesort(LIST&l)
{
	for (NODE*p = l.pHead; p!=l.pTail; p = p->pNext)
	{
		for (NODE*j = p->pNext; j; j = j->pNext)
		{
			if ((p->Data) > (j->Data))
			{
				swap(p->Data, j->Data);
			}
		}
	}
}

void main()
{
	LIST a;
	InPut(a);
	OutPut(a);
	if (checkpos(a)) cout << "\nAll the numbers in the list are positive!";
	interchangesort(a);
	cout << endl << "Sorted !" << endl;
	OutPut(a);
	system("pause");
}