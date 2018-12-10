#include <iostream>
using namespace std;
struct Node
{
	int value;
	int pos;
	Node*pNext;	
	void Input()
	{
		cout << "Value: "; cin >> value;
		cout << "Pos: "; cin >> pos;
	}
	void Output()
	{
		cout << "(" << value << ";" << pos << ")\n";
	}
};
struct Mat
{
	int size=0;
	Node* pHead = NULL;
	Node* pTail = NULL;
};
Node* NewNode(int value, int pos)
{
	Node*p = new Node;
	if (p == NULL) return NULL;
	p->pos = pos;
	p->value = value;
	p->pNext = NULL;
	return p;
}
void AddTail(Mat&m, Node*p)
{
	if (m.pHead == NULL) m.pHead = m.pTail = p;
	else
	{
		m.pTail->pNext = p;
		m.pTail = p;
	}
}
void InputMat(Mat&m)
{
	int n;
	cout << "How many entries? "; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		Node*p = NewNode(0,0);
		p->Input();
		AddTail(m, p);
		m.size++;
	}
}
void OutputMat(Mat&m)
{
	for (Node*p = m.pHead; p; p = p->pNext)
	{
		p->Output();
	}
}

Mat Sum(Mat A, Mat B)
{
	Mat C;
	for (Node*p = A.pHead; p; p = p->pNext)
	{
		int check = 0;
		for (Node*k = B.pHead; k; k = k->pNext)
		{
			if (p->pos == k->pos)
			{
				Node* Temp = NewNode(p->value+k->value, p->pos);
				AddTail(C, Temp);
				check = 1;
			}
		}
		if (check == 0)
		{
			Node*Temp = NewNode(p->value, p->pos);
			AddTail(C, Temp);
		}
	}
	for (Node*p = B.pHead; p; p = p->pNext)
	{
		int flag = 0;
		for (Node*k = A.pHead; k; k = k->pNext)
		{
			if (p->pos == k->pos)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			Node* Temp = NewNode(p->value, p->pos);
			AddTail(C, Temp);
		}
	}
	return C;
}
Mat Subtraction(Mat A, Mat B)
{
	Mat C;
	for (Node*p = A.pHead; p; p = p->pNext)
	{
		int check = 0;
		for (Node*k = B.pHead; k; k = k->pNext)
		{
			if (p->pos == k->pos)
			{
				Node* Temp = NewNode(p->value - k->value, p->pos);
				AddTail(C, Temp);
				check = 1;
			}
		}
		if (check == 0)
		{
			Node*Temp = NewNode(p->value, p->pos);
			AddTail(C, Temp);
		}
	}
	for (Node*p = B.pHead; p; p = p->pNext)
	{
		int flag = 0;
		for (Node*k = A.pHead; k; k = k->pNext)
		{
			if (p->pos == k->pos)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			Node* Temp = NewNode(-p->value, p->pos);
			AddTail(C, Temp);
		}
	}
	return C;
}
int GetPosValue(Mat A, int n)
{
	for (Node*p = A.pHead; p; p = p->pNext)
	{
		if (p->pos == n) return p->value;
	}
	return 0;
}
void OutputVisualizedMatrix(Mat A, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (GetPosValue(A, j+col*i)) cout << GetPosValue(A, j+col*i) << " ";
			else cout << "0 ";
		}
		cout << endl;
	}
}
void main()
{
	int Row,Col;
	cout << "Matrix RowxCol. \nEnter Row:"; cin >> Row;
	cout << "Enter Col:"; cin >> Col;
	cout << "Mat A Input:\n";
	Mat A;
	InputMat(A);
	OutputMat(A);
	cout << "Mat B Input:\n";
	Mat B;
	InputMat(B);
	OutputMat(B);
	
	cout << "\nSum Mat:\n"; //Tong 2 ma tran 
	Mat C = Sum(A, B);
	OutputVisualizedMatrix(C, Row, Col);
    
	cout << "\nSubtraction Mat:\n"; //Hieu 2 ma tran
	C = Subtraction(A, B);
	OutputVisualizedMatrix(C, Row, Col);
	
	getchar();
	getchar();
}