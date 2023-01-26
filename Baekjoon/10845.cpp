#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
	int size;
	int length;
	int* queue = nullptr;
	int temp;
public:
	void MakeQueue(int _size)
	{
		size = _size;
		queue = new int[size];
		length = 0;
	}
	void Push()
	{
		if (queue == nullptr)
			return;

		if (length < size)
		{
				cin >> temp;
				queue[length] = temp;
				length++;
		}
	}
	void Pop()
	{
		if (length < 1)
			cout << "-1\n";
		else
		{
			cout << queue[0] << "\n";
			for (int i = 0; i < length - 1; i++)
				queue[i] = queue[i + 1];
			length--;
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
	void Front()
	{
		if (length == 0)
			cout << "-1\n";
		else 
			cout << queue[0] << "\n";
	}
	void Back()
	{
		if (length == 0)
			cout << "-1\n";
		else 
			cout << queue[length-1] << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a; cin >> a;
	
	Queue q;
	q.MakeQueue(a);

	for (int i = 0; i < a; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
			q.Push();
		else if (str == "pop")
			q.Pop();
		else if (str == "size")
			q.Size();
		else if (str == "empty")
			q.Empty();
		else if (str == "front")
			q.Front();
		else if (str == "back")
			q.Back();
	}

	return 0;
}