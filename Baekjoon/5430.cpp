#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int testcase;
	cin >> testcase;
	for (int u = 0; u < testcase; u++)
	{
		bool error = false;
		bool reverse = false;
		deque<int> dq;
		string cmd;
		cin >> cmd;
		int num; string ary;
		cin >> num >> ary;

		string tempNum = "";
		int index = 0;
		while (true) 
		{
			if (ary[index] == '[' || ary[index] == ']' || ary[index] == ',') 
			{
				if (tempNum.length() != 0) 
				{
					dq.push_back(stoi(tempNum));
					tempNum = "";
				}
			}
			else 
			{
				tempNum += ary[index];
			}
			if (ary[index] == ']') { break; }
			index++;
		}


		for (size_t i = 0; i < cmd.size(); i++)
		{
			if (cmd[i] == 'R')
			{
				reverse = !reverse;
			}
			else if (cmd[i] == 'D')
			{
				if (dq.size() == 0)
				{
					cout << "error\n";
					error = true;
					break;
				}
				else
				{
					if (reverse) { dq.pop_back(); }
					else { dq.pop_front(); }
				}
			}
		}
		if (!error)
		{
			cout << "[";
			int dq_size = (int)dq.size();
			for (int i = 0; i < dq_size - 1; i++)
			{
				if (reverse) 
				{
					cout << dq.back() << ",";
					dq.pop_back(); 
				}
				else 
				{
					cout << dq.front() << ",";
					dq.pop_front(); 
				}
			}
			if (dq.size() != 0) { cout << dq.front(); }
			cout << "]\n";
		}
	}

	return 0;
}