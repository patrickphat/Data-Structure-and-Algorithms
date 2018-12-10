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
	for (NODE*p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (NODE*j = p->pNext; j; j = j->pNext)
		{
			if ((p->Data) >(j->Data))
			{
				swap(p->Data, j->Data);
			}
		}
	}
}

void main()
{
	LIST l;
	Input(l);
	if (checkpos(l)) cout << "\nAll the numbers in the list are positive!";
	cout << "\nNot all numberws in the list are positive!";
	interchangesort(l);
	cout << endl << "Sorted !" << endl;
	Output(l);
	system("pause");
}