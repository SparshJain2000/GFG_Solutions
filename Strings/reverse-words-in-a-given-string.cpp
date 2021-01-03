#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << reverseWords(s) << endl;
    }
}
string reverseWords(string S) {
    if (S == "") return S;
    string ans = "";
    int i = 0, j = 0;
    while (i < S.length() && j < S.length()) {
        while (j < S.length() && S[j++] != '.')
            ;
        ans = S.substr(i, j == S.length() ? j - i : j - 1 - i) + "." + ans;
        i = j;
    }
    return ans.substr(0, S.length());
}