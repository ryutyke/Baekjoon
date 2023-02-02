#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n, s;
	cin >> n >> s;

	int* ary = new int[n];
	for (int i = 0; i < n; i++) { cin >> ary[i]; }

	int left = 0;
	int right = 1;
	int sum = ary[0];
	int best = 1000000;
	if (sum >= s) { cout << 1; return 0; }
	while (!(left == n && right == n))
	{
		if (sum >= s)
		{
			if (left == right) { cout << 1; return 0; }
			if (best > right - left) { best = right - left; }
			sum -= ary[left++];
		}
		else
		{
			if (right < n) { sum += ary[right++]; }
			else { break; }
		}
	}

	if (best == 1000000) { cout << 0; }
	else { cout << best; }

	return 0;
}