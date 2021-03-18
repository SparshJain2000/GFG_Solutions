#include <bits/stdc++.h>
using namespace std;

int strstr(string, string);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a;
        cin >> b;
        cout << strstr(a, b) << endl;
    }
}

int strstr(string str, string sub) {
    int l = sub.length();
    if (str == sub) return 0;
    if (l > str.length()) return -1;
    for (int i = 0; i <= str.length() - l; i++)
        if (str.substr(i, l) == sub)
            return i;
    return -1;
}