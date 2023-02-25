#include <iostream>
using namespace std;

int ary[1025][1025];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                cin >> ary[i][j];
            }
            else if (i == 1)
            {
                int temp;
                cin >> temp;
                ary[i][j] = ary[i][j - 1] + temp;
            }
            else if (j == 1)
            {
                int temp;
                cin >> temp;
                ary[i][j] = ary[i - 1][j] + temp;
            }
            else
            {
                int temp;
                cin >> temp;
                ary[i][j] = ary[i - 1][j] + ary[i][j - 1] + temp - ary[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = ary[x2][y2];
        if (x1 > 1)
        {
            result -= ary[x1 - 1][y2];
        }
        if (y1 > 1)
        {
            result -= ary[x2][y1 - 1];
        }
        if (x1 > 1 && y1 > 1)
        {
            result += ary[x1 - 1][y1 - 1];
        }
        cout << result << "\n";
    }

    return 0;
}