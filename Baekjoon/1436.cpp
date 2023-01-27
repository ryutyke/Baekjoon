#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int cnt = 0;
	int now = 665;
	int temp;

	while (cnt != n)
	{
		now++;
		temp = now;
		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			temp /= 10;
		}
	}
	cout << now;

	return 0;
}