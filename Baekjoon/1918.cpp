#include<iostream>
#include<stack>
using namespace std;

string str;
stack<char> st;

int main()
{
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cout << str[i];
		}

		else if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!st.empty() && st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
	}
	
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

	return 0;
}