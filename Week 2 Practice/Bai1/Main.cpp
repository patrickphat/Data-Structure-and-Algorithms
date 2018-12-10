//Mang nhap tu ban phim
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
void BubbleSort(vector<int>&a)
{
	for (int i = a.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
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

void ShakerSort(vector<int>& a)
{
	int n = a.size();
	int i, j, k;
	for (i = 0; i < n;)
	{
		
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[j - 1])
				swap(&a[j], &a[j - 1]);
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
void heapify(vector<int>& arr, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < arr.size() && arr[l] > arr[largest])
		largest = l;


	if (r < arr.size() && arr[r] > arr[largest])
		largest = r;


	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, largest);
	}
}

// main function to do heap sort
void heapSort(vector<int>&arr)
{

	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify(arr, i);


	for (int i = arr.size() - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, 0);
	}
}
void ShellSort(vector<int>& a)
{
	int i, j, k, temp;
	
	for (i = a.size() / 2; i > 0; i = i / 2)
	{
		for (j = i; j <a.size(); j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				
				if (a[k + i] >= a[k])
					break;
				else
				{
					temp = a[k];
					a[k] = a[k + i];
					a[k + i] = temp;
				}
			}
		}
	}
}
int main()
{
	vector<int> a;
	nhap(a);
	// Lua chon sort ma ban muon (only 1 thoi nha!)
	// BubbleSort(a);
	// ShakerSort(a);
	// heapSort(a);
	// ShellSort(a);
	// Enjoy!
	xuat(a);
	system("pause");
	return 0;
}
