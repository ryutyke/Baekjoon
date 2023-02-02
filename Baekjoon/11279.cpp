#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	priority_queue<int, vector<int>> pq;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 0)
		{
			if (pq.size() == 0) { cout << "0\n"; }
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(cmd);
		}
	}

	return 0;
}