#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<short int> a;
	int n,index=0;cout << "Thap phan -> Nhi phan: "; cin >> n;
	while (n)
	{
		short int insert = n % 2;
		a.push_back(insert);
		n /= 2;
		index++;
	}
	cout << "Ket qua:" ;
	for (int i = index - 1; i >= 0; i--)
	{
		cout << a[i];


	}
	system("pause");
	return 0;

}