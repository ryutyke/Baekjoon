#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int* ary = new int[n];

	for (int i = 0; i < n; i++)
		cin >> ary[i];
	vector<bool> result;
	stack<int> s;
	int temp;
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		temp = ary[i];
		while (true)
		{
			if (num <= temp)
			{
				s.push(num);
				num++;
				result.push_back(0);
			}
			else
			{
				if (s.top() == temp)
				{
					s.pop();
					result.push_back(1);
					break;
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
		}	
	}
	for (auto b : result)
	{
		if (b == 0) cout << "+\n";
		else cout << "-\n";
	}
	return 0;
}