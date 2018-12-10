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

int OutputFile(char*fn,LIST l)
{
	FILE *fp = fopen(fn, "wb");
	if (fp == NULL) return 0;
	NODE*p = l.pHead;
	while (p)
	{
		fwrite(&p -> Data, sizeof(int), 1, fp);
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
	for (NODE *p=l.pTail;p;p=p->pPrev)
	{
		cout << p->Data <<" ";
	}
}
bool isPrime(int num)
{
	if (num <= 1)
		return false;
	else if (num == 2)
		return true;
	else if (num % 2 == 0)
		return false;
	else
	{
		bool prime = true;
		int divisor = 3;
		double num_d = static_cast<double>(num);
		int upperLimit = static_cast<int>(sqrt(num_d) + 1);

		while (divisor <= upperLimit)
		{
			if (num % divisor == 0)
				prime = false;
			divisor += 2;
		}
		return prime;
	}
}
int countprime(LIST l)
{
	int count = 0;
	for (NODE*p = l.pHead; p; p = p->pNext)
	{
		int value = p->Data;
		if (isPrime(value)) count++;
	}
	return count;
}
bool checkperfectnum(int a)
{
	int sum = 0;
	for (int i = 1; i <= a / 2; i++)
	{
		if (a%i == 0) sum += i;
	}
	if (sum == a) return true;
	else return false;
}
int countperfectnum(LIST l)
{
	int count = 0;
	for (NODE*p = l.pHead; p; p = p->pNext)
	{
		int value = p->Data;
		if (checkperfectnum(value)) count++;
	}
	return count;
}
void main()
{
	LIST l;
	Input(l);
    Output(l);
	cout << "\nAmount of prime numbers: " << countprime(l);
	cout << "\nAmount of perfect numbers: " << countperfectnum(l);
	system("pause");
}
