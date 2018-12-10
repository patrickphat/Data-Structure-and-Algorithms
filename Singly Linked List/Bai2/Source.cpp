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
	cout << endl;
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p << " ";
	}
}
bool checkodd(LIST l)
{
	for (NODE*p = l.pHead; p; p = p->pNext)
	{
		int value = p->Data;
		if (value % 2 == 1) return true;
	}
	return false;
}
NODE* GetMin(LIST l)
{
	NODE *target=l.pHead;
	for (NODE *p = l.pHead->pNext; p; p = p->pNext)
	{
		int value = p->Data;
		if (value < target->Data)
		{
			target = p;
		}
	}
	return target;
}
void main()
{
	LIST a;
	InPut(a);
	OutPut(a);
	if (checkodd(a)) cout << "\nAt least 1 odd number available!";
	cout << "\nAddress of min Node: " << GetMin(a) << " ";
	system("pause");
}