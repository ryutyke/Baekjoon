#include<iostream>
#include<algorithm>
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

	int target;
	cin >> target;

	int result = 0;
	while (left != right)
	{
		int sum = ary[left] + ary[right];
		if (sum == target)
		{
			result++;
			left++;
		}
		else if (sum < target)
		{
			left++;
		}
		else { right--; }
	}
	cout << result;

	return 0;
}