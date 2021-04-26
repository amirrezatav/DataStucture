using System;

class BubbleSort
{

    static bool compare(string x, string y)
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
    static void bubbleSort(string[] arr)
    {
        int n = arr.Length;
        bool flag = true;
        for (int i = 0; i < n - 1 && flag; i++)
        {
            flag = false;
            for (int j = 0; j < n - i - 1; j++)
                if (compare(arr[j] , arr[j + 1]))
                {
                    flag = true;
                    string temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        }
    }
    static void bubbleSort(int[] arr)
    {
        int n = arr.Length;
        bool flag = true;
        for (int i = 0; i < n - 1 && flag; i++)
        {
            flag = false;
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                {
                    flag = true;
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        }
    }

    public static void Main()
    {
        int[] arr = { 64, 34, 25, 12, 22, 11, 90 };
        bubbleSort(arr);
        Console.WriteLine("Sorted array : ");
        for (int i = 0; i < arr.Length; ++i)
            Console.Write(arr[i] + " ");

        Console.WriteLine("\nSorted List : ");

        string[] str = { "Amirreza", "Ali", "Hasan","Erfan", "Fatemeh", "Zahra", "Zeynab" };
        bubbleSort(str);
        for (int i = 0; i < str.Length; ++i)
            Console.Write(str[i] + " ");

        Console.ReadKey();
    }

}
