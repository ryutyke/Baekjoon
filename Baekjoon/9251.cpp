#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int result[1001][1001];
string a, b;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				result[i + 1][j + 1] = result[i][j] + 1;
			}
			else
			{
				result[i + 1][j + 1] = max(result[i + 1][j], result[i][j + 1]);
			}
		}
	}
	cout << result[(int)a.size()][(int)b.size()];

	return 0;
}