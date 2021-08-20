// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    string longestPalindrome(string s) {
        // code here
        int i = 0;
        int n = s.length();
        string res = "";
        int ans = 0;

        while (i < n) {
            int j = i + 1;
            int k = i - 1;
            int temp = 1;
            string ts;
            ts += s[i];
            while (k > -1 && j < n && s[j] == s[k]) {
                ts = (s[k] + ts + s[j]);
                temp += 2;
                k--;
                j++;
            }
            if (temp > ans) ans = temp, res = ts;
            i++;
        }

        int j = 1;
        i = 0;
        while (i < n - 1 && j < n) {
            int k = j;
            int l = i;
            int temp = 0;
            string ts = "";
            while (k < n && l > -1 && s[k] == s[l]) {
                ts = (s[l] + ts + s[k]);
                k++, l--;
                temp += 2;
            }
            if (temp > ans) ans = temp, res = ts;
            i++;
            j++;
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.longestPalindrome(S) << endl;
    }
    return 0;
}
// } Driver Code Ends