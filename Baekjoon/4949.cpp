#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false); cin.tie(0);

	int small = 0, big = 0;
	string str = "";
	stack<char> s;
	s.push(' ');

	while (true) 
	{
		getline(cin, str);
		if (str == ".") { break; }
		small = big = 0;

		for (int j = 0; j < str.length(); j++) 
		{
			if (str[j] == '(') 
			{
				s.push('(');
				small++;
			}
			else if (str[j] == ')') 
			{
				small--;
				if (s.top() != '(') { break; }
				s.pop();
			}
			else if (str[j] == '[') 
			{
				s.push('[');
				big++;
			}
			else if (str[j] == ']') 
			{
				big--;
				if (s.top() != '[') { break; }
				s.pop();
			}

			if (small < 0 || big < 0) { break; }
		}

		if (small == 0 && big == 0) { cout << "yes\n"; }
		else { cout << "no\n"; }
	}

	return 0;
}