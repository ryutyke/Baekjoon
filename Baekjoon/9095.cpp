#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a;
	cin >> a;

	int* num = new int[11];
	
	num[0] = 0; num[1] = 1; num[2] = 2; num[3] = 4;

	for (int i = 4; i <= 10; i++)
		num[i] = num[i - 3] + num[i - 2] + num[i - 1];

	int* array = new int[a];
	for (int i = 0; i < a; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < a; i++)
	{
		cout << num[array[i]] << "\n";
	}

	return 0;
}