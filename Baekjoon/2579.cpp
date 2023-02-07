#include <iostream>
using namespace std;

int step[300];
int memo[300];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> step[i];

	memo[0] = step[0];
	memo[1] = step[0] + step[1];
	memo[2] = step[2] + max(step[0], step[1]);

	for (int i = 3; i < N; i++) {
		memo[i] = step[i] + max(memo[i - 3] + step[i - 1], memo[i - 2]);
	}

	cout << memo[N - 1];
}