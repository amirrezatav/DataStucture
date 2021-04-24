#include <iostream>
#include <math.h>
#include <chrono>
#include <unistd.h>

using namespace std;

// Merge Sort 
void merge(int arr[], int low, int mid, int up)
{
	int lenL = mid - low + 1;
	int lenR = up - mid;

	int L[lenL], R[lenR];

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
void mergeSort(int arr[],int low,int up){
	if(up<=low)
		return;
	int mid =(up+low)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,up);
	merge(arr,low,mid,up);
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Bitonic Sort
void compAndSwap(int a[], int i, int j, int dir)
{
	if (dir==(a[i]>a[j]))
		swap(a[i],a[j]);
}
void bitonicMerge(int a[], int low, int cnt, int dir)
{
	if (cnt>1)
	{
		int k = cnt/2;
		for (int i=low; i<low+k; i++)
			compAndSwap(a, i, i+k, dir);
		bitonicMerge(a, low, k, dir);
		bitonicMerge(a, low+k, k, dir);
	}
}
void bitonicSort(int a[],int low, int cnt, int dir)
{
	if (cnt>1)
	{
		int k = cnt/2;
		bitonicSort(a, low, k, 1);
		bitonicSort(a, low+k, k, 0);
		bitonicMerge(a,low, cnt, dir);
	}
}

// Bubble Sort
void Nonstringbubble_sort(int  arr[], int length)
{
	bool flag = true;
	for (size_t i = 0; i < length - 1 && flag; i++)
	{
		flag = false;
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
	}
}

// Selection Sort
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(arr[min_idx], arr[i]); 
    }
}

// Shell Sort
int shellSort(int arr[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

           	int j = i - gap;
			while (j >= 0  && arr[j] > temp)
			{
				arr[j + gap] = arr[j];
				j = j - gap;
			}
			arr[j + gap] = temp;
        }
    }
	return 0;
}

template<class T>
void CopyTo(T source , T Destination , int sourceLen)
{
	for (size_t i = 0; i < sourceLen; i++)
	{
		Destination[i] = source[i];
	}
	
}

void printArray(int A[], int size , string title)
{
	cout << title << " : ";
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	const int arraylen = pow(2,12);
	int arr[arraylen] ;
	for (size_t i = 0; i < arraylen; i++)
		arr[i] = rand()%10+10;

	int arrMerge[arraylen] ;
	int arrInsertion[arraylen] ;
	int arrBubble[arraylen] ;
	int arrSelection[arraylen] ;
	int arrShell[arraylen] ;
	int arrBitonic[arraylen] ;

	CopyTo(arr, arrMerge, arraylen);
	CopyTo(arr, arrInsertion, arraylen);
	CopyTo(arr, arrBubble, arraylen);
	CopyTo(arr, arrSelection, arraylen);
	CopyTo(arr, arrShell, arraylen);
	CopyTo(arr, arrBitonic, arraylen);


	auto start = chrono::steady_clock::now();
	mergeSort(arrMerge,0,arraylen-1);
	auto end = chrono::steady_clock::now();
	auto MergeTimens= chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	start = chrono::steady_clock::now();
	insertionSort(arrInsertion,arraylen);
	end = chrono::steady_clock::now();
	auto InsertionTimens= chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	start = chrono::steady_clock::now();
	bitonicSort(arrBitonic,0,arraylen,1);
	end = chrono::steady_clock::now();
	auto bitonicTimens= chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	start = chrono::steady_clock::now();
	Nonstringbubble_sort(arrBubble,arraylen);
	end = chrono::steady_clock::now();
	auto BubbleTimens= chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	start = chrono::steady_clock::now();
	selectionSort(arrSelection,arraylen);
	end = chrono::steady_clock::now();
	auto SelectionTimens= chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	start = chrono::steady_clock::now();
	shellSort(arrShell,arraylen);
	end = chrono::steady_clock::now();
	auto ShellTimens= chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  	


	// printArray(arr ,arraylen,          "UnSorted Array       " );
	// printArray(arrMerge ,arraylen,     "Sorted whit Merge    " );
	// printArray(arrInsertion ,arraylen, "Sorted whit Insertion" );
	// printArray(arrBubble ,arraylen,    "Sorted whit Bubble   " );
	// printArray(arrSelection ,arraylen, "Sorted whit Selection" );
	// printArray(arrShell ,arraylen,     "Sorted whit Shell    " );
	// printArray(arrBitonic ,arraylen,   "Sorted whit Bitonic  " );

	
	cout << ">> Merge Time Elapsed     : " << MergeTimens << " ns" << endl;
	cout << ">> Insertion Time Elapsed : " << InsertionTimens << " ns" << endl;
	cout << ">> Bitonic Time Elapsed   : " << bitonicTimens << " ns" << endl;
	cout << ">> Bubble Time Elapsed    : " << BubbleTimens << " ns" << endl;
	cout << ">> Selection Time Elapsed : " << SelectionTimens << " ns" << endl;
	cout << ">> Shell Time Elapsed     : " << ShellTimens << " ns" << endl;

	return 0;
}
