#include <iostream>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false); cin.tie(0);

	long long M = 1234567891, result = 0, r = 1;
	int n;
	string str;
	cin >> n >> str;

	for (int i = 0; i < n; i++) 
	{
		result += ((str[i] - 'a' + 1) * r) % M;
		r = (r * 31) % M;
	}
	
	cout << result % M;

	return 0;
}