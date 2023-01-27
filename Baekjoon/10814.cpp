#include<iostream>
#include<string>
#include<utility>
using namespace std;

pair<int, string> temp[100000];

void merge(pair<int, string>* user, int first, int mid, int last)
{
	int f = first, m = mid+1, l = last, t = first;

	while (f <= mid && m <= l)
	{
		if (user[f].first <= user[m].first) temp[t++] = user[f++];
		else temp[t++] = user[m++];
	}
	while (f <= mid)
		temp[t++] = user[f++];
	while (m <= l)
		temp[t++] = user[m++];

	for (int i = first; i < t; i++)
		user[i] = temp[i];

	return;
}

void merge_sort(pair<int, string>* user, int first, int last)
{
	if (first >= last)
		return;
	int mid = (first + last) / 2;

	merge_sort(user, first, mid);
	merge_sort(user, mid + 1, last);
	merge(user, first, mid, last);

	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	pair<int, string>* user;

	int n;
	int age;
	string name;
	cin >> n;

	user = new pair<int, string>[n];

	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		user[i].first = age;
		user[i].second = name;
	}
	merge_sort(user, 0, n - 1);

	for (int i = 0 ; i < n; i++)
	{
		cout << user[i].first << " " << user[i].second << "\n";
	}
	return 0;
}