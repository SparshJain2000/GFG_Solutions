#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> m;
        for (int &i : v) cin >> i;
        for (int i : v) m[i]++;
        sort(v.begin(), v.end(), [&m](const int &a, const int &b) {
            return ((m[a] == m[b]) ? (a < b) : (m[a] > m[b]));
        });
        for (int i : v) cout << i << " ";
        cout << "\n";
    }
    return 0;
}