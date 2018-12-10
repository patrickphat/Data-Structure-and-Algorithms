// Only works with positive number
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int Data;
	Node *pNext;
};
struct List
{
	int size = 0;
	Node* pHead = NULL;
	Node* pTail = NULL;
};
Node* NewNode(int n);
void AddTail(List&l, Node*p);
void BuildList(List&l, string a);
void AddHead(List&l, Node*p);
void Output(List l);
void BuildSumList(List&sum, List a, List B);
void AddZeros(List&, List&);
void main()
{
	string a,b;
	cout << "Enter A and B:\n";
	cin >> a >> b;
	List A;
	List B;
	BuildList(A, a);
	BuildList(B, b);
	List Sum;
	BuildSumList(Sum, A, B);
	cout << "Sum of A & B: ";
	Output(Sum);
	getchar();
	getchar();
}

Node* NewNode(int n)
{
	Node*p = new Node;
	if (p == NULL) return NULL;
	p->Data = n;
	p->pNext = NULL;
	return p;
}
void AddTail(List&l, Node*p)
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
void AddHead(List&l, Node*p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void BuildList(List&l, string a)
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		int temp = a[i] - '0';
		Node*p = NewNode(temp);
		AddHead(l, p);
		l.size++;
	}
}
void AddZeros(List&A, List&B)
{
	if (A.size > B.size)
	{
		for (int i = 1; i <= A.size - B.size; i++)
		{
			Node*p = NewNode(0);
			AddTail(B, p);
		}
	}
	else
	{ 
			for (int i = 1; i <= B.size - A.size; i++)
			{
				Node*p = NewNode(0);
				AddTail(A, p);
			}
	}
}
void BuildSumList(List&sum, List A, List B)
{
	AddZeros(A, B);
	int temp = 0;
	Node*p = A.pHead;
	Node*k = B.pHead;
	while (p)
	{
		temp += p->Data + k->Data;
		if (temp >= 10)
		{
			Node*p = NewNode(temp%10);
			AddHead(sum, p);
			temp /= 10;
		}
		else
		{
			Node*p = NewNode(temp);
			AddHead(sum, p);
			temp = 0;
		}
		p = p->pNext;
		k = k->pNext;
	}
	if (temp == 1)
	{
		Node* temp1 = NewNode(temp);
		AddHead(sum, temp1);
	}
}
void Output(List l)
{
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		cout << p->Data;
	}
}