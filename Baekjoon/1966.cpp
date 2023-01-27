#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, temp;
		cin >> a >> b;
		queue<int> q;
		queue<bool> target;
		int* array = new int[a];
		for (int j = 0; j < a; j++)
		{
			cin >> temp;
			q.push(temp);
			array[j] = temp;
			(j == b) ? target.push(true) : target.push(false);
		}
		sort(array, array + a);
		int cnt = 1;
		while (true)
		{
			if (q.front() == array[a - 1])
			{
				if (target.front() == true)
				{
					cout << cnt << "\n";
					break;
				}
				q.pop();
				target.pop();
				
				cnt++;
				a--;
			}
			else
			{
				q.push(q.front());
				q.pop();
				target.push(target.front());
				target.pop();
			}
		}
	}

	return 0;
}