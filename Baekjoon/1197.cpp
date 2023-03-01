#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int Parent[10001];
vector<pair<pair<int, int>, int>> Edges;

bool Compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}

int GetParent(int index)
{
	if (Parent[index] == index)
	{
		return index;
	}
	return Parent[index] = GetParent(Parent[index]);
}

void UnionParent(int a, int b)
{
	if (a < b)
	{
		Parent[GetParent(b)] = GetParent(a);
	}
	else
	{
		Parent[GetParent(a)] = GetParent(b);
	}
}

bool CompareParent(int a, int b)
{
	if (GetParent(a) == GetParent(b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < E; i++)
	{
		int From, To, Dist;
		cin >> From >> To >> Dist;
		Edges.push_back(make_pair(make_pair(From, To), Dist));
	}

	sort(Edges.begin(), Edges.end(), Compare);

	int Cnt = 0;
	long long Result = 0;

	for (auto& elem : Edges)
	{
		if (Cnt == V - 1)
		{
			break;
		}

		int From = elem.first.first;
		int To = elem.first.second;
		int Dist = elem.second;

		if (!CompareParent(From, To))
		{
			Result += Dist;
			Cnt++;
			UnionParent(From, To);
		}
	}

	cout << Result;

	return 0;
}