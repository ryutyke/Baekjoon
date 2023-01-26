#include <iostream>
using namespace std;

int main()
{
    int* zero = new int[41];
    int* one = new int[41];
    
    zero[0] = 1; zero[1] = 0;
    one[0] = 0; one[1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cout << zero[m] << " " << one[m] << "\n";
    }

    return 0;
}