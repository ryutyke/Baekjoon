#include <iostream>
using namespace std;

bool notprime[1000001];

void Eratos(int n)
{
	notprime[1] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if(!notprime[i])
			for(int j = i * i; j <= n; j+=i)
				if(!notprime[j]) notprime[j] = true;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	Eratos(b);

	for (int i = a; i <= b; i++)
	{
		if (!notprime[i]) cout << i << "\n";
	}

	return 0;
}