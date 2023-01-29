#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	short* s = new short[n];

	for (int i = 0; i < n; i++)
		cin >> s[i];

	make_heap(s, s + n, greater<>());

	for (int i = n; i >= 1; i--)
	{
		pop_heap(s, s + i, greater<>());
		cout << s[i - 1] << "\n";
	}
	

	return 0;
}