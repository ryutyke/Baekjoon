#include<iostream>
using namespace std;

int chess[50][50];

int check(int a, int b)
{
	int cnt1 = 0;
	int cnt2 = 0;

	for(int i = a; i < a+8; i++)
		for (int j = b; j < b + 8; j++)
		{
			if ((i + j) % 2 == chess[i][j]) cnt1++;
			if ((i + j + 1) % 2 == chess[i][j]) cnt2++;
		}
	return (cnt1 < cnt2 ? cnt1 : cnt2);
}

int main()
{
	int a, b;
	char c;
	cin >> a >> b;

	for(int i = 0 ; i < a; i++)
		for (int j = 0; j < b; j++)
		{
			cin >> c;
			if (c == 'W') chess[i][j] = 0;
			else chess[i][j] = 1;
		}

	int temp;
	int minimum = 2500;
	for(int i = 0; i <= a-8; i++)
		for (int j = 0; j <= b - 8; j++)
		{
			temp = check(i,j);
			if (minimum > temp) minimum = temp;
		}

	cout << minimum;

	return 0;
}