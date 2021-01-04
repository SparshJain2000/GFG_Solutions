#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = -1;
        for (int i = s.length() - 1; i >= 0; i--)
            if (s[i] == '1') {
                ans = i;
                break;
            }
        cout << ans << endl;
    }

    return 0;
}
/*
2
00001
0
*/