#include <iostream>
#include <vector>
using namespace std;
void input(vector<int> &); //Nhap
void output(vector<int>); //Xuat
void erase(vector<int> &); //Xoa phan tu theo vi tri
void findmaxpos(vector<int>); //Xuat cac vi tri max
void findminpos(vector<int>); //Xuat cac vi tri min
void max_neg(vector<int>); //Xuat so am lon nhat
void min_pos(vector<int>);//Xuat so duong nho nhat
bool check_availabilty(vector<int> a, int k); //Check ton tai mot gia tri trong mang
int count(vector<int> , int ); //Dem phan tu k trong a
void selection_sort(vector<int>&);
void interchange_sort(vector<int>&);
bool checksort(vector<int>a); //Kiem tra xem da sort hay chua
void binarysearch(vector<int>&a); 
void neg_element(vector<int> a);

int main()
{
	vector<int> a;
	cout << "==INITIALIZE YOUR 2D ARRAY=\n";
	input(a);
	int choose;
	cout << "MENU OF SELECTIONS:\n1.Output the array\n2.Remove an element at a specific position\n3.List greatest elements\n4.List smallest elements\n5.Count negative elements\n6.Greatest negative element\n7.Smallest positive element\n8.Check availability of an element with X value\n9.Count elements with X value\n10.Sort array ascendantly\n11.Binary search\n12.Exit\n";
	while (1)
	{
		cout << "Select: "; cin >> choose;
		switch (choose)
		{
		case 1: output(a);
			break;
		case 2: 
			erase(a);
			break;
		case 3:
			findmaxpos(a);
			break;
		case 4:
			findminpos(a);
			break;
		case 5:
			neg_element(a);
			break;
		case 6:
			max_neg(a);
			break;
		case 7:
			min_pos(a);
			break;
		case 8:
			int lookup; cout << "Enter number you'd like to find: "; cin >> lookup;
			if (check_availabilty(a, lookup)) cout << "Available!\n";
			else cout << "Non-Available!\n";
			break;
		case 9:
			int lookup2; cout << "Enter value you'd like to count: "; cin >> lookup2;
			if (count(a, lookup2)) cout << "Counting result: " << count(a, lookup2);
			else cout << "Cannot find the value " << lookup2 << " in the array!\n";
			break;
		case 10:
			selection_sort(a);
			break;
		case 11:
			binarysearch(a);
			break;
		case 12:
			return 0;
		}
	}
	
	
	system("pause");
}
void input(vector<int> &a)
{
	int n;
	cout << "Numbers of element :";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		int k;
		cin >> k;
		a.push_back(k);
	}
}
void output(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
void erase(vector<int> &a)
{
	cout << "Enter position you want to remove";
	int pos; cin >> pos;
	a.erase(a.begin() + pos);
	cout << "Removed!\n";
}
void findmaxpos(vector<int> a)
{
	int flag=a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] > flag)
		{
			flag = a[i];
	    }
	}
	cout << "Position max:";
	for (int i = 0; i < a.size(); i++)
	{
		;
		if (a[i] == flag)
		{
			cout << i << " ";
		}
	}
	cout << "\n";
	
}
void findminpos(vector<int> a)
{
	int flag = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] < flag)
		{
			flag = a[i];
		}
	}
	cout << "Position min:";
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == flag)
		{
			cout << i << " ";
		}
	}
	cout << "\n";
}
void neg_element(vector<int> a)
{
	int count=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < 0) count++;
	}
	cout << "Amount of negative numbers: " << count << endl;
}
void max_neg(vector<int> a)
{
	int flag, check = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < 0)
		{
			flag = a[i];
			check = 1;
			break;
		}
	}
	if (check)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] < 0 && a[i]>flag)
			{
				flag = a[i];
			}
		}
		cout << "greatest negative value: " << flag << "\n";
	}
	else cout << "No negative numbers in array\n";

}
void min_pos(vector<int> a)
{
	int flag, check = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > 0)
		{
			flag = a[i];
			check = 1;
			break;
		}
	}
	if (check)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > 0 && a[i] < flag)
			{
				flag = a[i];
			}
		}
	}
	else cout << "No positive numbers in array\n";

}
bool check_availabilty(vector<int> a, int k)
{
	int check = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == k)
		{
			check = 1;
			break;
		}
	}
	if (check) return true;
	else return false;
}
int count(vector<int> a, int k)
{
	int count = 0;
	if (check_availabilty(a, k))
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == k) count++;
		}
	}
	else cout << "non-available\n" << endl;
	return count;
}

void selection_sort(vector<int>&a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		int min = i;
		for (int j = i; j < a.size(); j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
	cout << "Sorted!" << endl;
}
void interchange_sort(vector<int>&a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[i] > a[j]) swap(a[i],a[j]);
		}
	}
	cout << "Sorted!" << endl;
}
bool checksort(vector<int>a)
{
	for (int i = 0; i < a.size()-1; i++)
	{
		if (a[i] > a[i+1]) return false;
	}
	return true;
}
void binarysearch(vector<int>&a)
{
	if (checksort(a))
	{
		int desire;
		cout << "Enter value X you'd like to find: "; cin >> desire;
		if (desire <= a[a.size() - 1] && desire >= a[0])
		{
			int target = a.size() / 2 - 1; int range = a.size() / 2;
			int check = 0;
			while (range != 1)
			{
				if (a[target] == desire)
				{
					cout << "Desired value is at " << target << "th position\n";
					check = 1;
					break;
				}
				else if (a[target] < desire)
				{
					target += range / 2;
					range = range / 2 + 1;
				}
				else
				{
					target -= range / 2;
					range = range / 2 + 1;
				}
			}
		}
		else cout << "Cant find!";
	}
	else cout << "You need to sort the array first!\n";
}