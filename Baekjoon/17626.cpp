#include<iostream>
using namespace std;

int temp[50001];

int main()
{
	for (int i = 1; i <= 50000; i++)
	{
		temp[i] = 0;
	}

	for (int i = 1; i <= 223; i++)
	{
		temp[i * i] = 1;
	}

	for (int m = 2; m <= 4; m++)
	{
		for (int i = 1; i <= 50000; i++)
		{
			if (temp[i] == (m-1))
			{
				for (int j = 1; j <= 223; j++)
				{
					int a = i + j * j;
					if (a <= 50000)
					{
						if (temp[a] == 0) { temp[a] = m; }
					}
				}
			}
		}
	}
	
	int num;
	cin >> num;
	cout << temp[num];

	return 0;
}