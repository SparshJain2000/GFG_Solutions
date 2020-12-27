#include <bits/stdc++.h>
using namespace std;
void permute(string s, int l, int r, set<string> &ans) {
    if (l == r) {
        ans.insert(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[i], s[l]);
        permute(s, l + 1, r, ans);
        swap(s[i], s[l]);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<string> ans;
        permute(s, 0, s.length() - 1, ans);
        for (string str : ans) cout << str << " ";
        cout << endl;
    }
}
/*
2
ABC
ABSG
*/