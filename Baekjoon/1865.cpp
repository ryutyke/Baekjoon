#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<int, int>> edges[501];
int MinDist[501];
bool SayYes;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TestCase;
	cin >> TestCase;

	for (; TestCase--;)
	{
		SayYes = false;
		for (int i = 1; i < 501; i++)
		{
			edges[i].clear();
			MinDist[i] = 0;
		}

		int Node, Road, Wormhole;
		cin >> Node >> Road >> Wormhole;

		int From, To, Dist;
		for (int i = 0; i < Road; i++)
		{
			cin >> From >> To >> Dist;
			edges[From].push_back(make_pair(To, Dist));
			edges[To].push_back(make_pair(From, Dist));
		}
		for (int i = 0; i < Wormhole; i++)
		{
			cin >> From >> To >> Dist;
			edges[From].push_back(make_pair(To, -Dist));
		}

		for (int j = 1; j <= Node; j++)
		{
			for (int i = 1; i <= Node; i++)
			{
				for (auto& elem : edges[i])
				{
					From = i;
					To = elem.first;
					Dist = elem.second;

					if (MinDist[To] > MinDist[From] + Dist)
					{
						if (j == Node)
						{
							SayYes = true;
						}
						MinDist[To] = MinDist[From] + Dist;
					}
				}
			}
		}

		if (SayYes) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}
	return 0;
}