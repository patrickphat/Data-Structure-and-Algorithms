#include <iostream>
#include <fstream>
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
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}
void AddHead(LIST&l, NODE*p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
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
		AddHead(l, p);
	}
}

int OutputFile(char*fn, LIST l)
{
	FILE *fp = fopen(fn, "wb");
	if (fp == NULL) return 0;
	NODE*p = l.pHead;
	while (p)
	{
		fwrite(&p->Data, sizeof(int), 1, fp);
		p = p->pNext;
	}
	fclose(fp);
	return 1;
} //Nhap file binary
int InputFile(char*fn, LIST&l)
{
	FILE*fp = fopen(fn, "rb");
	if (fp = NULL) return 0;
	int temp;
	Init(l);
	while (fread(&temp, sizeof(int), 1, fp) == 1)
	{
		NODE*p = GetNode(temp);
		if (p != NULL) AddHead(l, p);
	}
	fclose(fp);
	return 1;
} //Xuat file binary
void Output(LIST l)
{
	for (NODE *p = l.pTail; p; p = p->pPrev)
	{
		cout << p->Data << " ";
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
	NODE *target = l.pHead;
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
	LIST l;
	Input(l);
	Output(l);
	if (checkodd(l)) cout << "\nAt least 1 odd number available!";
	cout << "\nAddress of min Node: " << GetMin(l) << " ";
	system("pause");
}