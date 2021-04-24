//In the Name of God, the Merciful, the Compassionate
//bubbleSort
//telegram.me/amirrezatav
// C++ implementation of the approach
#include <iostream>
#include <vector>
using namespace std;


bool compare(string x, string y)
{
	char first;
	char second;
	for (size_t i = 0; i < min(x.length() , y.length()); i++)
	{
		first = tolower(x[i]);
		second = tolower(y[i]);
		if (first == second)
			continue;
		else if (first > second)
			return true;
		else
			return false;
	}
}

void stringbubble_sort(string  arr[], int length)
{
	bool flag = true;
	for (size_t i = 0; i < length - 1 && flag; i++)
	{
		flag = false;
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (compare(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
	}
}
template<class T>
void Nonstringbubble_sort(T  arr[], int length)
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

template<class T>
void bubble_sort(int Nonstring_arraylength = 0 , T Nonstringarray[] = NULL 
	,  int string_arraylength = 0, string stringarray[] = NULL)
{
	
	bool flag = true;
	if (stringarray != NULL)
	{
		stringbubble_sort(stringarray, string_arraylength);
	}
	else if (Nonstringarray != NULL)
	{
		Nonstringbubble_sort<T>(Nonstringarray, Nonstring_arraylength);
	}

}

// Driver code
int main()
{
	string v[] = { "Amirreza", "Ali", "Hasan",
					"Erfan", "Fatemeh", "Zahra", "Zeynab" };
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	bubble_sort<int>(sizeof(a) / sizeof(int), a , 7 , v);

	// Print the strings after sorting
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	for (auto x : a)
		cout << x << " ";
	return 0;
}
