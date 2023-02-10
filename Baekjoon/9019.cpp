#include<iostream>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

bool check[10000];
queue<pair<int, string>> q;
int a, b;

int D(int a)
{
	return (a * 2) % 10000;
}

int S(int a)
{
	if (a == 0) { return 9999; }
	else { return a - 1; }
}

int L(int a)
{
	return (a % 1000) * 10 + a / 1000;
}

int R(int a)
{
	return (a / 10) + (a % 10) * 1000;
}

void bfs()
{
	while (!q.empty())
	{
		int qsize = (int)q.size();
		for (int i = 0; i < qsize; i++)
		{
			pair<int, string> temp = q.front(); q.pop();
			if (temp.first == b)
			{
				int tempsize = (int)q.size();
				for (int j = 0; j < tempsize; j++)
				{
					q.pop();
				}
				cout << temp.second << "\n";
				return;
			}
			else
			{
				int d = D(temp.first);
				if (check[d] == false) 
				{
					check[d] = true;
					q.push(make_pair(d, temp.second + 'D'));
				}
				int s = S(temp.first);
				if (check[s] == false)
				{
					check[s] = true;
					q.push(make_pair(s, temp.second + 'S'));
				}
				int l = L(temp.first);
				if (check[l] == false)
				{
					check[l] = true;
					q.push(make_pair(l, temp.second + 'L'));
				}
				int r = R(temp.first);
				if (check[r] == false)
				{
					check[r] = true;
					q.push(make_pair(r, temp.second + 'R'));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	for (; t--;)
	{
		for (int i = 0; i < 10000; i++)
		{
			check[i] = false;
		}

		cin >> a >> b;
		string s = "";
		check[a] = true;
		q.push(make_pair(a, s));
		bfs();
	}
	return 0;
}