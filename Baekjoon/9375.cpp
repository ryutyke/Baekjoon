#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int CaseCnt;
	cin >> CaseCnt;

	for (; CaseCnt--;)
	{
		map<string, int> m;
		int n;
		cin >> n;
		for (; n--;)
		{
			string ItemName, ItemType;
			cin >> ItemName >> ItemType;
			m[ItemType]++;
		}
		int result = 1;
		for (auto& elem : m)
		{
			result *= (elem.second + 1);
		}
		cout << result - 1 << "\n";
	}

	return 0;
}