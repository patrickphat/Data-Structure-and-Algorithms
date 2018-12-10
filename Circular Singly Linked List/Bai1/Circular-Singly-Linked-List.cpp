#include <iostream>
#include <fstream>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int Data;
	struct node *pNext;
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
		l.pTail = p;
		l.pTail->pNext = l.pHead;
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
	NODE *p = l.pHead;
	do
	{
		int value = p->Data;
		if (isPrime(value)) count++;
		p = p->pNext;
	} while (p != l.pHead);
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
	NODE *p = l.pHead;
	do
	{
		int value = p->Data;
		if (checkperfectnum(value)) count++;
		p = p->pNext;
	} while (p != l.pHead);
	return count;
}
void main()
{
	LIST l; int n; cout << "Nhap so phan tu: "; cin >> n;
	Random_File(n);
	List_Input(l, n);
    Output(l);
	cout << "\nAmount of prime numbers: " << countprime(l);
	cout << "\nAmount of perfect numbers: " << countperfectnum(l);
	system("pause");
}
