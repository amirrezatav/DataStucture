#include <iostream>
using namespace std;

int shellSort(int arr[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int key = arr[i];

			int j = i - gap;

			while (j >= gap &&  arr[j] > key)
        	{
            arr[j + gap] = arr[j];
            j -= gap;
        	}	

			arr[j + gap] = key;
		}
	}
	return 0;
}


int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Array before sorting: \n";
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";

	shellSort(arr, n);

	cout << "\nArray after sorting: \n";
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
		
	return 0;
}
