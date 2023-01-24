#include <iostream>
using namespace std;

int main()
{
	int num, temp;
	cin >> num;

	if (num == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			temp = num + 1;
			cin >> num;
			if (temp != num)
				break;
			if (i == 6)
			{
				cout << "ascending";
				return 0;
			}
		}
	}

	else if (num == 8)
	{
		for (int i = 0; i < 7; i++)
		{
			temp = num - 1;
			cin >> num;
			if (temp != num)
				break;
			if (i == 6)
			{
				cout << "descending";
				return 0;
			}
		}
	}

	cout << "mixed";

	return 0;
}