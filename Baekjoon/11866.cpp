#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) 
	{
		q.push(i);
	}

	cout << "<";
	for (int i = 0; i < n; i++) 
	{
		for (int j = 1; j < k; j++) 
		{
			q.push(q.front());
			q.pop();
		}
		(i != n - 1) ? cout << q.front() << ", " : cout << q.front();
		q.pop();
	}
	cout << ">";

	return 0;
}