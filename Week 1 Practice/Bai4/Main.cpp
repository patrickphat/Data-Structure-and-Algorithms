#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<short int> a;
	int n, index = 0; cout << "Thap phan -> Thap phan: "; cin >> n;
	while (n)
	{
		short int insert = n % 16;
		a.push_back(insert);
		n /= 16;
		index++;
	}
	cout << "Ket qua:";
	for (int i = index-1; i >=0; i--)
	{
		if (a[i] >= 0 && a[i] <= 9) cout << a[i];
		else
		{
			switch (a[i])
			{
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
	system("pause");
	return 0;
}