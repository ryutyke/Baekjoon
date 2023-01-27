#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	vector<int> v;
	bool removed[1001] = { false , };

	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cnt++;
			if (cnt > n) cnt %= n;
			while (removed[cnt])
			{
				cnt++;
				if (cnt > n) cnt %= n;
			}
		}
		v.push_back(cnt);
		removed[cnt] = true;
	}

	cout << "<";
	int a = v.size();
	for (int i = 0; i < a - 1; i++)
		cout << v[i] << ", ";
	cout << v[a-1] << ">";

	return 0;
}