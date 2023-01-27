#include<iostream>
using namespace std;

int main()
{
	int best = 1000;
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	if (best > x) best = x;
	if (best > y) best = y;
	if (best > w - x) best = w - x;
	if (best > h - y) best = h - y;
	cout << best;

	return 0;
}