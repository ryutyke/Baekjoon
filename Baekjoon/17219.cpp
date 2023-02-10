#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	unordered_map<string, string> um;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string address, pw;
		cin >> address >> pw;
		um[address] = pw;
	}

	for (int i = 0; i < m; i++)
	{
		string address;
		cin >> address;
		cout << um[address] << "\n";
	}

	return 0;
}