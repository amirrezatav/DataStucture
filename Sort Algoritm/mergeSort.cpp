#include <iostream>
using namespace std;


void merge(int arr[], int low, int mid, int up)
{
	int lenL = mid - low + 1;
	int lenR = up - mid ;

	int *L, *R;
    
    L = new int[lenL];
    R = new int[lenR];

	for (int i = 0; i < lenL; i++)
		L[i] = arr[low + i];
	for (int j = 0; j < lenR; j++)
		R[j] = arr[mid + 1 + j];


	int i = 0;

	int j = 0;

	int k = low;

	while (i < lenL && j < lenR) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < lenL) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < lenR) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	int arr[] = { 13, 15, 28, 12, 79, 28 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}
