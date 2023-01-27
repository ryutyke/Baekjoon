#include<iostream>
#include<string>
using namespace std;

string temp[20000];

void merge(string* ary, int left, int mid, int right)
{
	int l, m, t;
	l = left;
	m = mid + 1;
	t = left;

	while (l <= mid && m <= right)
	{
		if (ary[l] == ary[m])
		{
			ary[l] = "";
			temp[t++] = ary[l++];
			temp[t++] = ary[m++];
		}
		else
		{
			if (ary[l].length() == ary[m].length())
			{
				if (ary[l] < ary[m]) temp[t++] = ary[l++];
				else temp[t++] = ary[m++];
			}
			else
			{
				if (ary[l].length() < ary[m].length()) temp[t++] = ary[l++];
				else temp[t++] = ary[m++];
			}
		}	
	}
	while (l <= mid)
	{
		temp[t++] = ary[l++];
	}
	while (m <= right)
	{
		temp[t++] = ary[m++];
	}
	while (left <= right)
	{
		ary[left] = temp[left];
		left++;
	}
	return;
}

void merge_sort(string* ary, int left, int right)
{
	int mid = (left + right) / 2;

	if (left >= right) return;

	merge_sort(ary, left, mid);
	merge_sort(ary, mid + 1, right);
	merge(ary, left, mid, right);

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string* strary = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> strary[i];
	}

	merge_sort(strary, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		if (strary[i] != "")
			cout << strary[i] << "\n";
	}

	return 0;
}