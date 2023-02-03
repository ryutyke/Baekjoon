#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<string, bool> d;
vector<string> b;
vector<string> answer;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		d[s] = true;
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		b.push_back(s);
	}
	sort(b.begin(), b.end());
	for (string s : b)
	{
		if (d[s] == true) { answer.push_back(s); }
	}
	cout << answer.size() <<"\n";
	for (string s : answer)
	{
		cout << s << "\n";
	}
	return 0;
}