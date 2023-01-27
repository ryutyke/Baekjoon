#include<iostream>
using namespace std;

int temp[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, n, cnt, best = 0;
	cin >> a >> n;
	for (int i = 0; i < a; i++)
		cin >> temp[i];

	for (int i = 0; i < a - 2; i++)
		for(int j = i+1; j < a-1; j++)
			for (int k = j + 1; k < a; k++)
			{
				cnt = 0;
				cnt = temp[i] + temp[j] + temp[k];
				if (cnt <= n) 
					if(cnt > best) best = cnt;
			}

	cout << best;

	return 0;
}