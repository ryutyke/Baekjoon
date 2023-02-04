#include<iostream>
#include<set>
using namespace std;

void func() 
{
    int n;
    cin >> n;
    multiset<int> ms;

    while (n--) 
    {
        char c;
        int b;
        cin >> c >> b;
        if (c == 'I') 
        {
            ms.insert(b);
        }
        else 
        {
            if (ms.size()) 
            {
                if (b == 1) 
                {
                    ms.erase(--ms.end());
                }
                else 
                {
                    ms.erase(ms.begin());
                }
            }
        }
    }
    if (ms.size()) 
    {
        cout << *--ms.end() << " " << *ms.begin() << "\n";
    }
    else 
    {
        cout << "EMPTY\n";
    }
}
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc;
    cin >> tc;

    while (tc--) 
    {
        func();
    }

    return 0;
}