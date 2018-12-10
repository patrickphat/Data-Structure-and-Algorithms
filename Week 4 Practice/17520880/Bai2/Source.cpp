#include <iostream>
using namespace std;
struct Node 
{
	int Data;
	Node *pNext;
};
struct List
{
	Node* pHead=NULL;
	Node* pTail=NULL;
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
void BuildBinaryList(List&l)
{
	int n;
	cout << "Dec -> Bin: "; cin >> n;
	while (n)
	{
		Node*p = NewNode(n%2);
		AddHead(l, p);
		n /= 2;
	}
}
void Output(List l)
{
	for (Node*p = l.pHead; p; p = p->pNext) cout << p->Data;
}
void main()
{
	List l;
	BuildBinaryList(l);
	Output(l);
	getchar();
	getchar();
}