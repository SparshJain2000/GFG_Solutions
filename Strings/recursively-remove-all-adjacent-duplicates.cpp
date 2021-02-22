
//Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.
#include <bits/stdc++.h>
using namespace std;
bool isDist(string s) {
    if (!s.length()) return true;
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == s[i + 1]) return false;
    return true;
}
string rem(string s) {
    while (!isDist(s)) {
        int i = 0;
        while (i < s.length()) {
            int j = i + 1;
            while (s[i] == s[j]) j++;
            bool q = false;
            if (j - i > 1) {
                s.erase(i, j - i);
            } else
                i++;
            if (i < 0) i = 0;
        }
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        string str;
        cin >> str;
        cout << rem(str) << endl;
    }
}