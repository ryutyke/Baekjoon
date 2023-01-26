#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
	int length = 0;
	int size = 0;
	int* stack = nullptr;
public:
	void MakeStack(int _size)
	{
		size = _size;
		stack = new int[size];
		length = 0;
	}
	void Push(int elem)
	{
		if (stack == nullptr)
		{
			cout << "make stack first";
			return;
		}
		if (length < size)
		{
			stack[length] = elem;
			length++;
		}
	}
	void Pop()
	{
		if (stack == nullptr)
		{
			cout << "make stack first";
			return;
		}

		if (length < 1)
			cout << "-1\n";
		else
		{
			length--;
			cout << stack[length] << "\n";
		}
	}
	void Size()
	{
		cout << length << "\n";
	}

	void Empty()
	{
		if (length == 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
	void Top()
	{
		if (length == 0)
			cout << "-1\n";
		else
			cout << stack[length - 1] << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	Stack s;
	s.MakeStack(n);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int j; cin >> j;
			s.Push(j);
		}
		else if (str == "pop")
			s.Pop();
		else if (str == "size")
			s.Size();
		else if (str == "empty")
			s.Empty();
		else if (str == "top")
			s.Top();
	}

	return 0;
}