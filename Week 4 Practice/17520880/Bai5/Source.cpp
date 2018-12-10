#include <iostream>
using namespace std;
struct Student
{
	char Name[30];
	char ID[10];
	int GPA;
	void Input()
	{
		cin.ignore(1);
		cout << "Name: "; cin.getline(Name, 30);
		cout << "ID: "; cin.getline(ID, 10);
		cout << "GPA: "; cin >> GPA;
	}
	void Output()
	{
		cout << "Name: "; puts(Name);
		cout << "ID: "; puts(ID);
		cout << "GPA: "; cout << GPA << endl;
	}
};
struct Node
{
	Student Data;
	Node* pNext;
};
struct List
{
	Node *pHead=NULL,*pTail = NULL;
};
Node* NewNode(Student a)
{
	Node*p = new Node;
	if (p == NULL) return NULL;
	strcpy_s(p->Data.Name, a.Name);
	strcpy_s(p->Data.ID, a.ID);
	p->Data.GPA = a.GPA;
	p->pNext = NULL;
	return p;
}
void AddTail(List&l, Node*p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		return;
	};
	l.pTail->pNext = p;
	l.pTail = p;
}
void Input(List&l)
{
	int n;
	cout << "Enter the number of students: "; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Student #" << i << endl;
		Student a;
		a.Input();
		Node*p = NewNode(a);
		AddTail(l,p);
	}
}
void OutputHighestGPA(List l)
{
	int flag = l.pHead->Data.GPA;
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.GPA > flag) flag = p->Data.GPA;
	}
	cout << "Students that has greatest GPA:\n";
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.GPA == flag) p->Data.Output();
	}
}
int GreaterThan5(List l)
{
	int count=0;
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.GPA >= 5) count++;
	}
	return count;
}
int FindStudent(List l)
{
	char Find[30];
	cout << "Enter name you'd like to find: "; cin.ignore(1); cin.getline(Find, 30);
	cout << "Finding result: \n";
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (strcmp(p->Data.Name, Find) == 0)
		{
			p->Data.Output();
			return 1;
		}
	}
	cout << "There are no student with that particular name!\n";
}
void Output(List l)
{
	cout << "\nLIST OF STUDENTS\n";
	int dem = 1;
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		cout << "Student #" << dem << endl;
		p->Data.Output();
		dem++;
	}
}
Node* PrevNode(List l, Node*a)
{
	Node*p = l.pHead;
	for (; p->pNext != a; p = p->pNext);
	return p;
}
void DeleteStudentID(List&l)
{
	char MSSV[10];
	cin.ignore(1); 
	cout << "Enter ID of the student you'd like to delete: ";
	cin.getline(MSSV, 10);

	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (strcmp(p->Data.ID, MSSV) == 0)
		{
			
			cout << "Deleted!";
			if (l.pHead == l.pTail)
			{
				l.pHead = NULL;
				l.pTail = NULL;
				delete p;
				return;
			}
			if (p == l.pHead)
			{
				l.pHead = p->pNext;
				delete p;
				return;
			}
			if (p == l.pTail)
			{
				l.pTail = PrevNode(l, p);
				l.pTail->pNext = NULL;
				delete p;
				return;
			}
			PrevNode(l, p)->pNext = p->pNext;
			delete p;
			return;
		}
	}
	cout << "There are no students with that ID!";
}
void InterchangeSort(List l)
{
	for (Node*p = l.pHead; p->pNext; p = p->pNext)
	{
		for (Node*k = p->pNext; k; k = k->pNext)
		{
			if (p->Data.GPA > k->Data.GPA) swap(p->Data.GPA, k->Data.GPA);
		}
	}
	cout << "Sorted!\n";
}
void InsertStudent(List &l)
{
	Student a;
	cout << "Insert Student:\n";
	a.Input();
	Node*k = NewNode(a);
	for (Node*p = l.pHead; p; p = p->pNext)
	{
		if (p->Data.GPA > a.GPA)
		{
			if (p == l.pHead)
			{
				k->pNext = l.pHead;
				l.pHead = k;
				return;
			}
			k->pNext = p;
			PrevNode(l, p)->pNext = k;
			return;
		}
	}
	l.pTail->pNext = k;
	l.pTail = k;
}
void main()
{
	List l;
	Input(l);
	// OutputHighestGPA(l);
	// FindStudent(l);
	// DeleteStudentID(l);
	// InterchangeSort(l);
	// InsertStudent(l);
	Output(l);

	getchar(); 
	getchar();
}