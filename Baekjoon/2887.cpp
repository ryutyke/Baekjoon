#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<tuple>
using namespace std;

int PlanetNum;

vector<pair<int,int>> XAry;
vector<pair<int, int>> YAry;
vector<pair<int, int>> ZAry;

vector<tuple<int, int, int>> Tunnel;

int Parent[100000];

int GetParent(int a)
{
	if (Parent[a] == a) { return a; }
	else
	{
		return Parent[a] = GetParent(Parent[a]);
	}
}

void Union(int a, int b)
{
	int AParent = GetParent(a);
	int BParent = GetParent(b);

	if (AParent < BParent)
	{
		Parent[BParent] = AParent;
	}
	else
	{
		Parent[AParent] = BParent;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> PlanetNum;
	for (int i = 0; i < PlanetNum; i++)
	{
		Parent[i] = i;
		int a, b, c;
		cin >> a >> b >> c;
		XAry.push_back(make_pair(a, i));
		YAry.push_back(make_pair(b, i));
		ZAry.push_back(make_pair(c, i));
	}

	sort(XAry.begin(), XAry.end());
	sort(YAry.begin(), YAry.end());
	sort(ZAry.begin(), ZAry.end());
	
	for (int i = 0; i < PlanetNum - 1; i++)
	{
		int From = XAry[i].second;
		int To = XAry[i + 1].second;
		int Dist = XAry[i + 1].first - XAry[i].first;
		Tunnel.push_back(make_tuple(Dist, From, To));
	}
	for (int i = 0; i < PlanetNum - 1; i++)
	{
		int From = YAry[i].second;
		int To = YAry[i + 1].second;
		int Dist = YAry[i + 1].first - YAry[i].first;
		Tunnel.push_back(make_tuple(Dist, From, To));
	}
	for (int i = 0; i < PlanetNum - 1; i++)
	{
		int From = ZAry[i].second;
		int To = ZAry[i + 1].second;
		int Dist = ZAry[i + 1].first - ZAry[i].first;
		Tunnel.push_back(make_tuple(Dist, From, To));
	}
	
	sort(Tunnel.begin(), Tunnel.end());
	
	int Result = 0;
	for (size_t i = 0; i < Tunnel.size(); i++)
	{
		int Dist = get<0>(Tunnel[i]);
		int From = get<1>(Tunnel[i]);
		int To = get<2>(Tunnel[i]);

		if (GetParent(From) != GetParent(To))
		{
			Result += Dist;
			Union(From, To);
		}
	}

	cout << Result;

	return 0;
}