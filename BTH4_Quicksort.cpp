
#include <iostream>
using namespace std;

int partition(int a[], int left, int right)
{

	int pivot = a[left];

	int count = 0;
	for (int i = left + 1; i <= right; i++)
	{
		if (a[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = left + count;
	swap(a[pivotIndex], a[left]);

	// Sorting left and right parts of the pivot element
	int i = left, j = right;

	while (i < pivotIndex && j > pivotIndex)
	{

		while (a[i] <= pivot)
		{
			i++;
		}

		while (a[j] > pivot)
		{
			j--;
		}

		if (i < pivotIndex && j > pivotIndex)
		{
			swap(a[i++], a[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int a[], int left, int right)
{

	// base case
	if (left >= right)
		return;

	// partitioning the aay
	int p = partition(a, left, right);

	// Sorting the left part
	quickSort(a, left, p - 1);

	// Sorting the right part
	quickSort(a, p + 1, right);
}

int main()
{

	int a[] = {50, 90, 40, 10, 60, 20, 30};
	int n = 7;

	quickSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}
