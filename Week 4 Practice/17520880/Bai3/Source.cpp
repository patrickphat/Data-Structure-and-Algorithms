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
void AddHead(List&l, Node*p)
{
	if (l.pHead == NULL) l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
Node* NewNode(int x)
{
	Node*p = new Node;
	if (p == NULL) return NULL;
	p->Data = x;
	p->pNext = NULL;
	return p;

}
void BuildHexList(List&l)
{
	int n;
	cout << "Dec -> Hex: "; cin >> n;
	while (n)
	{
		Node*p = NewNode(n % 16);
		AddHead(l, p);
		n /= 16;
	}
}
void Output(List l)
{
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		switch (p->Data)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			cout << p->Data;
			break;
		case 10:
			cout << "A";
			break;
		case 11:
			cout << "B";
			break;
		case 12:
			cout << "C";
			break;
		case 13:
			cout << "D";
			break;
		case 14:
			cout << "E";
			break;
		case 15:
			cout << "F";
			break;
		}
	}
}
void main()
{
	List l;
	BuildHexList(l);
	Output(l);
	getchar();
	getchar();
}