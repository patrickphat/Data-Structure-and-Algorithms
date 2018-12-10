// Dem phep so sanh va phep gan
#include <iostream>
#include <vector>
using namespace std;
void nhap(vector<int>&a)
{
	int n; cout << "Nhap so phan tu: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		int k; cin >> k;
		a.push_back(k);
	}
}
void xuat(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void BubbleSort(vector<int>&a, int&pg, int&pss)
{
	pg++;
	for (int i = a.size() - 1; i > 0; i--)
	{
		pss++;
		pg+=2;
		for (int j = 0; j < i; j++)
		{
			pg++;
			pss+=2;
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				pg++;
			}
		}
	}
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ShakerSort(vector<int>& a, int&pg, int&pss)
{
	int n = a.size(); pg++;
	int i, j, k;
	pg++;
	for (i = 0; i < n;)
	{
		pss++;
		pg++;
		for (j = i + 1; j < n; j++)
		{
			pss+=2;
			pg++;
			
			if (a[j] < a[j - 1])
			{
				swap(&a[j], &a[j - 1]);
				pg += 3;
			}
		}

		n--;


		for (k = n - 1; k > i; k--)
		{
			if (a[k] < a[k - 1])
				swap(&a[k], &a[k - 1]);
		}

		i++;
	}
}
void heapify(vector<int>& arr, int i, int&pg, int&pss)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	pg += 3;
	pss++;
	if (l < arr.size() && arr[l] > arr[largest])
	{
		largest = l;
		pg++;
	}

	pss++;
	if (r < arr.size() && arr[r] > arr[largest])
	{
		largest = r;
		pg++;
	}


	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		pg += 3;
		heapify(arr, largest,pg,pss);
	}
}

// main function to do heap sort
void heapSort(vector<int>&arr, int&pg, int&pss)
{

	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify(arr, i,pg,pss);

	pg++;
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		pss++;
		pg++;
		swap(arr[0], arr[i]);
		pg += 3;
		heapify(arr, 0,pg,pss);

	}
}
void ShellSort(vector<int>& a, int&pg, int&pss)
{
	int i, j, k, temp;
	pg += 1;
	for (i = a.size() / 2; i > 0; i = i / 2)
	{
		pss++;
		pg+=2;
		for (j = i; j <a.size(); j++)
		{
			pss++;
			pg += 2;
			for (k = j - i; k >= 0; k = k - i)
			{
				pss++;
				pg++;

				if (a[k + i] >= a[k]) {
					break;
					pss++;
				}
				else
				{
					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
					pg += 3;
				}
			}
		}
	}
}
int main()
{
	vector<int> a;
	int phepgan=0;
	int phepsosanh=0;
	nhap(a);
	// Lua chon sort ma ban muon (only 1 thoi nha!)
	// BubbleSort(a,phepgan,phepsosanh);
	// ShakerSort(a,phepgan,phepsosanh);
	// heapSort(a,phepgan,phepsosanh);
	ShellSort(a,phepgan,phepsosanh);
	// Enjoy!
	xuat(a);
	cout << "\n So phep gan cua thuat toan: " << phepgan;
	cout << "\n So phep so sanh cua thuat toan: " << phepsosanh;
	system("pause");
	return 0;
}
