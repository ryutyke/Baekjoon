#include<iostream>
#include<string>
using namespace std;

class set
{
public:
	int ary[20];
	int size = 0;

	void add(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (ary[i] == x) { return; }
		}
		ary[size++] = x;
	}

	void remove(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (ary[i] == x) 
			{ 
				ary[i] = ary[--size];
				return;
			}
		}
	}

	void check(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (ary[i] == x)
			{
				cout << "1\n";
				return;
			}
		}
		cout << "0\n";
	}

	void toggle(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (ary[i] == x)
			{
				ary[i] = ary[--size];
				return;
			}
		}
		ary[size++] = x;
	}

	void all()
	{
		for (int i = 0; i < 20; i++)
		{
			ary[i] = i + 1;
		}
		size = 20;
	}

	void empty()
	{
		size = 0;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int a;
	cin >> a;
	set s;
	for (int i = 0; i < a; i++)
	{
		string cmd;
		int x;
		cin >> cmd;
		if (!(cmd == "all" || cmd == "empty")) { cin >> x; }

		if (cmd == "add") { s.add(x); }
		else if (cmd == "remove") { s.remove(x); }
		else if (cmd == "check") { s.check(x); }
		else if (cmd == "toggle") { s.toggle(x); }
		else if (cmd == "all") { s.all(); }
		else if (cmd == "empty") { s.empty(); }
	}

	return 0;
}