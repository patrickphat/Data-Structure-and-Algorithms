//Please enable funtions by removing "//" in void main();
#include <iostream>
using namespace std;
struct Node
{
	int Data;
	Node *pNext;
};
struct List
{
	Node* pHead = NULL;
	Node* pTail = NULL;
};
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
	if (l.pHead = NULL) l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
int CountList(List l)
{
	int dem = 0;
	for (Node*p = l.pHead; p; p = p->pNext) dem++;
	return dem;
}
Node*GetNodeValueX(List l, int X)
{
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data == X) return p;
	}
	return NULL;
}
Node* PrevNode(List l, Node *k)
{
	Node*p = l.pHead;
	for (; p->pNext != k; p = p->pNext);
		return p;
	return NULL;
}
void DeleteHead(List&l)
{
	if (l.pHead == NULL) return;
	if (l.pHead == l.pTail)
	{
		Node*p = l.pHead;
		l.pHead = l.pTail = NULL;
		delete l.pHead;
		return;
	}
	Node*p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void DeleteTail(List&l)
{
	if (l.pHead == NULL) return;
	if (l.pHead == l.pTail)
	{
		Node*p = l.pHead;
		l.pHead = l.pTail = NULL;
		delete l.pHead;
		return;
	}
	Node*p = l.pTail;
	PrevNode(l, l.pTail)->pNext = NULL;;
	l.pTail = PrevNode(l, l.pTail);
	delete p;
}

void Input(List&l)
{
	int n;
	cout << "Nhap so phan tu cua danh sach:"; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int k; cout << "N[" << i - 1 << "]"; cin >> k;
		Node*p = NewNode(k);
		AddTail(l, p);
	}
}
void Output(List l)
{
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		cout << p->Data << " ";
	}
}
int DeleteValueX(List&l, int X)
{
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data == X)
		{
			if (p == l.pHead)
			{
				l.pHead = p->pNext;
				delete p;
				return 1;
			}
			if (p == l.pTail)
			{
				l.pTail = PrevNode(l, p);
				l.pTail->pNext = NULL;
				delete p;
				return 1;
			}
			PrevNode(l, p)->pNext = p->pNext;
			delete p;
			return 1;
		}
	}
	return 0;
}
void InterchangeSort(List&l)
{
	for (Node*p = l.pHead; p->pNext; p = p->pNext)
	{
		for (Node*k = p->pNext; k; k = k->pNext)
		{
			if (p->Data > k->Data) swap(p->Data, k->Data);
		}
	}
}
void InsertX(List&l, int X)
{
	Node*k = NewNode(X);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = k;
		return;
	}
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data >= X)
		{
			if (p == l.pHead)
			{
				l.pHead = k;
				k->pNext = p;
				return;
			}
			k->pNext = p;
			PrevNode(l, p)->pNext = k;
			return;
		}
	}
	l.pTail->pNext = k;
	l.pTail = k;
	return;
}
void MergeSort(List a, List b, List &c)
{
	Node*p = a.pHead;
	Node*k = b.pHead;
	while (p || k)
	{
		if (p&&k)
		{
			if (p->Data < k->Data)
			{
				Node*temp = NewNode(p->Data);
				AddTail(c, temp);
				p=p->pNext;
			}
			else
			{

				Node*temp = NewNode(k->Data);
				AddTail(c, temp);
				k=k->pNext;
			}
		}
		else
		{
			    if (p)
				{
					while (p)
					{
						Node*temp = NewNode(p->Data);
						AddTail(c, temp);
						p=p->pNext;
					}
				}
				else
				{
					while (k)
					{
						Node*temp = NewNode(k->Data);
						AddTail(c, temp);
						k=k->pNext;
					}
				}
		
		}
	}
}
void main()
{
	List a,b,c;
	Input(a); Input(b);
	MergeSort(a, b, c);
	Output(c);
	getchar();
	getchar();
}