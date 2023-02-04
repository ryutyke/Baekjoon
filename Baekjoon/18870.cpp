#include<iostream>
#include<algorithm>
using namespace std;

int ary[1000000];
int sort_ary[1000000];
int result[1000000];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		ary[i] = temp;
		sort_ary[i] = temp;
	}

	sort(sort_ary, sort_ary + n);
	
	int result_size = 0;
	result[0] = sort_ary[0];
	result_size++;
	for (int i = 1; i < n; i++)
	{
		if (sort_ary[i] != sort_ary[i - 1])
		{
			result[result_size++] = sort_ary[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(result, result + result_size, ary[i]) - result << " ";
	}


	return 0;
}