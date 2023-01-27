#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> a;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) a.push(i);
	while (a.size() != 1)
	{
		a.pop();
		int temp = a.front();
		a.pop();
		a.push(temp);
	}
	cout << a.front();
	return 0;
}