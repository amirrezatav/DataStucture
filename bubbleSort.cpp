//In the Name of God, the Merciful, the Compassionate
//bubbleSort
//telegram.me/amirrezatav
#include <iostream> 
using namespace std; 
template<class T>
void swap(T *xp, T *yp) 
{ 
	T temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// A function to implement bubble sort (Ascending)
template<class T>
void bubbleSort_Ascending(T arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	{
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
    }
} 
// A function to implement bubble sort (Descending)
template<class T>
void bubbleSort_Descending(T arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	{
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] < arr[j+1]) 
			swap<double>(&arr[j], &arr[j+1]); 
    }
} 
/* Function to print an array */
template<class T>
void print(T arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	
	int arri[] = {64, 34, 25, 12, 22, 11, 90}; 
	int arrisize = sizeof(arri)/sizeof(arri[0]); 
	bubbleSort_Ascending(arri, arrisize); 
	cout<<"Ascending Sorted int array: \n"; 
	print(arri, arrisize); 
	
  	double arrd[] = {64.2, -34.88, 2.5, 7.12, 28.82, -1.91, 9.0}; 
	int arrdsize = sizeof(arrd)/sizeof(arrd[0]); 
	bubbleSort_Descending<double>(arrd, arrdsize); 
	cout<<"Descending Sorted double array: \n"; 
	print<double>(arrd, arrdsize); 
	
	return 0; 
} 
