# This repository Contain
**Data Structure and algorithm** 


**This repository Contain :** 
+ an Example of Recursive Function 
+ Bubble Sort ([see more in Wiki](https://github.com/amirrezatav/DataStucture/wiki/Bubble-sort))
+ simple implementation of polynomial 
    - sum +
    - multiply *
    - Tostring
    - Calculate(cal Function)
# Compare String
#### CPP CODE
```cpp
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
    	return true;

    }
```

#### C# Code
```csharp
bool compare(string x, string y)
    {
		int min(int a, int b) => ((a > b) ? b : a);
		x = x.ToLower();
		y = y.ToLower();
		for (int i = 0; i < min(x.Length, y.Length); i++)
		{
			if (x[i] == y[i])
				continue;
			else if (x[i] > y[i])
				return true;
			else
				return false;
		}
		return true;
	}
```
