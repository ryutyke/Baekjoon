#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int* array = new int[n + 1];
	array[0] = 0; 
	array[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		int minimum = array[i - 1] + 1;

		if(i%2 == 0)
			minimum = min(minimum, (array[i / 2] + 1));
		if(i%3 == 0)
			minimum = min(minimum, (array[i / 3] + 1));

		array[i] = minimum;
	}

	cout << array[n];

	return 0;
}