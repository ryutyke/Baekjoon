#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int* ary = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}

	sort(ary, ary + n);

	int left = 0;
	int right = n - 1;

	int best = 2000000001;
	pair<int, int> result;
	while (left != right)
	{
		int sum = ary[left] + ary[right];
		if (best > abs(sum))
		{
			best = abs(sum);
			result.first = ary[left];
			result.second = ary[right];
		}
		if (sum == 0) { break; }
		else if (sum < 0) { left++; }
		else { right--; }
	}
	cout << result.first << " " << result.second;

	return 0;
}