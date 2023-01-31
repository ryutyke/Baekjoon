#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[50];
bool visited[50];
int root;
int cnt = 0;

void count_leaf(int root)
{
	if (visited[root]) { return; }
	visited[root] = true;
	bool isLeaf = true;
	for (size_t i = 0; i < tree[root].size(); i++)
	{
		int nextNode = tree[root][i];
		if (!visited[nextNode])
		{
			isLeaf = false;
			count_leaf(nextNode);
		}
	}
	if (isLeaf) { cnt++; }
	return;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent == -1) { root = i; }
		else { tree[parent].push_back(i); }
	}

	int deleteNodeNum;
	cin >> deleteNodeNum;
	visited[deleteNodeNum] = true;

	count_leaf(root);

	cout << cnt;

	return 0;
}