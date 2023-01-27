#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
	int left = 0;
	int right = s.length() - 1;

	while (left < right)
	{
		if (s[left++] == s[right--]) continue;
		else return false;
	}
	return true;
}

int main()
{
	string temp;
	while (true)
	{
		cin >> temp;
		if (temp == "0") break;
		else
			(check(temp) == true ? cout << "yes\n" : cout << "no\n");
	}
	return 0;
}