#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;
	int* array = new int[n];
	int length = 0;


	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (a != 0)
		{
			array[length] = a;
			length++;
		}
		else
			length--;
	}

	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += array[i];

	cout << sum;

	return 0;
}