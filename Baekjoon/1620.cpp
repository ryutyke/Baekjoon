#include<iostream>
#include<string>
#include<map>
using namespace std;

map<int, string> is;
map<string, int> si;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		is[i] = s;
		si[s] = i;
	}

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if ((int)s[0] < 58) 
		{
			cout << is[stoi(s)] << "\n";
		}
		else
		{
			cout << si[s] << "\n";
		}
	}

	return 0;
}