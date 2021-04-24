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
