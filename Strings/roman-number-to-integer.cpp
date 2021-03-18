// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}   // } Driver Code Ends

int romanToDecimal(string &str) {
    // code here
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
        ans += (i == str.length() - 1 || m[str[i]] >= m[str[i + 1]]) ? m[str[i]] : -m[str[i]];

    return ans;
}
//IXVIII