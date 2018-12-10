// Nhap phan tu random
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void nhap(vector<int>&a)
{
	int n; cout << "Nhap so phan tu: "; cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		cout << "\na[" << i << "]: ";
		int k; k = rand() % 100 + 1;
		a.push_back(k);
		cout << k << " ";
	}
	cout << endl;
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

// A function implementing shaker sort.
void ShakerSort(vector<int>& a)
{
	int n = a.size();
	int i, j, k;
	for (i = 0; i < n;)
	{
		// First phase for ascending highest value to the highest unsorted index.
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[j - 1])
				swap(&a[j], &a[j - 1]);
		}
		// Decrementing highest index. 
		n--;

		// Second phase for descending lowest value to the lowest unsorted index.
		for (k = n - 1; k > i; k--)
		{
			if (a[k] < a[k - 1])
				swap(&a[k], &a[k - 1]);
		}
		// Incrementing lowest index.
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
	// Build heap (rearrange array)
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify(arr, i);

	// One by one extract an element from heap
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, 0);
	}
}
void ShellSort(vector<int>& a)
{
	int i, j, k, temp;
	// Gap 'i' between index of the element to be compared, initially n/2.
	for (i = a.size() / 2; i > 0; i = i / 2)
	{
		for (j = i; j <a.size(); j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				// If value at higher index is greater, then break the loop.
				if (a[k + i] >= a[k])
					break;
				// Switch the values otherwise.
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
