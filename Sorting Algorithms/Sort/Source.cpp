#include <iostream>
using namespace std;
void interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j]) swap(a[i], a[j]);
		}
	}
}
void bubblesort(int a[], int n)
{
	for (int i = n - 1; i > 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}
void selectionsort(int a[], int n)
{
	int flag;
	for (int i = n - 1; i > 0; i--)
	{
		flag = 0;
		for (int j = 1; j <= i; j++)
		{
			if (a[j] > a[flag]) flag = j;
		}
		swap(a[i], a[flag]);
	}
}
void heapify(int a[], int n, int pos)
{
	int largest = pos;
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;
	if (left < n&&a[left] > a[largest]) largest = left;
	if (right <n&&a[right]>a[largest]) largest = right;
	if (largest != pos)
	{
		swap(a[largest], a[pos]);
		heapify(a, n, largest);
	}
}
void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n - 1; i >=0 ;i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
void quickSort(int arr[], int left, int right) {

	int i = left, j = right;

	int tmp;

	int pivot = arr[(left + right) / 2];



	/* partition */

	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j)

		quickSort(arr, left, j);

	if (i < right)

		quickSort(arr, i, right);

}
void insertionSort(int arr[], int length)
{

	int i, j, tmp;

	for (i = 1; i < length; i++) {

		j = i;

		while (j > 0 && arr[j - 1] > arr[j]) {

			tmp = arr[j];

			arr[j] = arr[j - 1];

			arr[j - 1] = tmp;

			j--;

		}

	}
}
void shellsort(int a[], int n)
{
	int i, j, k, temp;
	// Gap 'i' between index of the element to be compared, initially n/2.
	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
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
void main()
{
	int a[] = { 5,9,6,4,3,5,11,45,23,4 };
	int size = 10;
	// Lua chon sort :
	// interchangesort(a, size);
	// bubblesort(a, size);
	// selectionsort(a, size);
	 HeapSort(a, size);
	// quickSort(a, 0, size - 1);
	// insertionSort(a, size);
	// shellsort(a, size);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	getchar();

}