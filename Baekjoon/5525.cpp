#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	int result = 0;


	bool ing = false;
	bool io = false;  // i = true, o = false
	int Ocnt = 0;
	
	for (int i = 0; i < m; i++)
	{
		bool isI = (s[i] == 'I' ? true : false);

		if (ing == false)
		{
			if (isI == true)
			{
				ing = true;
				io = true;
				Ocnt = 0;
			}
		}
		else
		{
			if (isI == io)
			{
				if (isI == true)
				{
					Ocnt = 0;
				}
				else
				{
					ing = false;
				}
			}
			else
			{
				if (isI == true)
				{
					io = true;
					if (n == Ocnt)
					{
						result++;
						Ocnt--;
					}
				}
				else
				{
					io = false;
					Ocnt++;
				}
			}
		}
	}

	cout << result;

	return 0;
}