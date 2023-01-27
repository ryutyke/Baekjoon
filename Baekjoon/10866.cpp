#include<iostream>
#include<string>
using namespace std;

class Deque
{
private:
	int* array;
	int size;
public:
	Deque(int n) { array = new int[n]; size = 0; }

	void push_front()
	{
		int n;
		cin >> n;
		for (int i = size-1; 0 <= i ; i--)
			array[i + 1] = array[i];
		array[0] = n;
		size++;
	}
	void push_back()
	{
		int n;
		cin >> n;
		array[size] = n;
		size++;
	}
	void pop_front()
	{
		if (size == 0)
			cout << "-1\n";
		else
		{
			cout << array[0] << "\n";
			for (int i = 1; i < size; i++)
				array[i -1] = array[i];
			size--;
		}
	}
	void pop_back()
	{
		if (size == 0)
			cout << "-1\n";
		else
		{
			cout << array[size-1] << "\n";
			size--;
		}
	}
	void Size()
	{
		cout << size << "\n";
	}
	void empty()
	{
		size == 0 ? cout << "1\n" : cout << "0\n";
	}
	void front()
	{
		if (size == 0)
			cout << "-1\n";
		else
		{
			cout << array[0] << "\n";
		}
	}
	void back()
	{
		if (size == 0)
			cout << "-1\n";
		else
		{
			cout << array[size - 1] << "\n";
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	Deque dq = Deque(n);
	string command;
	for (int i = 0; i < n; i++)
	{
		cin >> command;

		if (command == "push_front")
			dq.push_front();
		else if (command == "push_back")
			dq.push_back();
		else if (command == "pop_front")
			dq.pop_front();
		else if (command == "pop_back")
			dq.pop_back();
		else if (command == "size")
			dq.Size();
		else if (command == "empty")
			dq.empty();
		else if (command == "front")
			dq.front();
		else if (command == "back")
			dq.back();
	}

	return 0;
}