#include <iostream>
using namespace std;

int main()
{
	int a, b;
	a = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> b;
		a += b * b;
	}
	
	cout << a % 10;

	return 0;
}