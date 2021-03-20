// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
   public:
    void matchPairs(char nuts[], char bolts[], int n) {
        // code here
        string s = "!#$%&*@^~";
        unordered_map<char, int> m;
        int i = 0;
        for (char c : s) m[c] = i++;
        sort(nuts, nuts + n, [&m](const char &a, const char &b) {
            return m[a] < m[b];
        });
        sort(bolts, bolts + n, [&m](const char &a, const char &b) {
            return m[a] < m[b];
        });
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends