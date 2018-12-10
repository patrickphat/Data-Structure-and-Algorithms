#include <iostream>
#pragma warning(disable:4996)
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
void AddTail(LIST&l,NODE *p)
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
	int sum=0;
	for (int i = 1; i <= a/2; i++)
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
	LIST a;
	InPut(a);
	OutPut(a);
	cout << "\nAmount of prime numbers: " << countprime(a);
	cout << "\nAmount of perfect numbers: " << countperfectnum(a);
	system("pause");
}