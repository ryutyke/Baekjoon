#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, int> friendCnt;
map<string, string> top;

string findTop(string name)
{
	if (name == top[name]) return name;
	return top[name] = findTop(top[name]);
}

void unionTop(string n1, string n2)
{
	string top_n1 = findTop(n1);
	string top_n2 = findTop(n2);
	if (top_n1 < top_n2)
	{
		friendCnt[top_n1] += friendCnt[top_n2];
		top[top_n2] = top_n1;
	}
	else if(top_n1 > top_n2)
	{
		friendCnt[top_n2] += friendCnt[top_n1];
		top[top_n1] = top_n2;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int testcase; cin >> testcase;
	for (int u = 0; u < testcase; u++)
	{
		int friends;
		cin >> friends;
		for (int i = 0; i < friends; i++)
		{
			string a, b;
			cin >> a >> b;
			if (top.count(a) == 0)
			{
				friendCnt[a] = 1;
				top[a] = a;
			}
			if (top.count(b) == 0)
			{
				friendCnt[b] = 1;
				top[b] = b;
			}
			unionTop(a, b);
			cout << friendCnt[findTop(a)] << "\n";
		}
		top.clear();
		friendCnt.clear();
	}

	return 0;
}