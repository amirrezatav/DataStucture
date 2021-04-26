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
