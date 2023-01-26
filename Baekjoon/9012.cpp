#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				cnt++;
			else if (s[i] == ')')
				cnt--;
			
			if (cnt < 0)
			{
				break;
			}
		}
		if (cnt == 0)
			cout << "YES\n";
		else
			cout << "NO\n";	
	}
	return 0;
}