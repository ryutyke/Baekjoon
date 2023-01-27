#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    int age;
    string name;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector <string> q[201];
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        q[age].push_back(name);
    }
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < q[i].size(); j++) {
            cout << i << " " << q[i][j] << "\n";
        }
    }
}