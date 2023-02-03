#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int n, m;
vector<int> broken;
pair<bool, int> can_click(int i);

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int brokenNum;
        cin >> brokenNum;
        broken.push_back(brokenNum);
    }

    int ans = 500000;
    for (int i = 0; i < 1000000; i++) {
        if (i == 100) {
            ans = min(ans, abs(100 - n));
        }
        else {
            pair<bool, int> p = can_click(i);
            bool can = p.first;
            int digit = p.second;
            
            if (can) {
                ans = min(ans, digit + abs(i - n));
            }
        }

    }
    cout << ans << endl;

    return 0;
}

pair<bool, int> can_click(int i) {
    bool can = true;
    if (i == 0) {
        for (auto bn : broken) {
            if (i == bn) {
                return make_pair(false, 1);
            }
        }
        return make_pair(true, 1);
    }
    else {
        int pow = 0;
        int j = i;
        while (j > 0) {
            pow += 1;
            int mod = j % 10;
            bool temp = true;
            for (auto bn : broken) {
                if (mod == bn) {
                    temp = false;
                    break;
                }
            }
            if (!temp) {
                can = false;
                break;
            }
            j /= 10;
        }
        return make_pair(can, pow);
    }
}