// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    string findLargest(int N, int S) {
        if (S == 0) return N == 1 ? "0" : "-1";
        string ans = "";
        while (N--) {
            if (S == 0)
                ans += '0';
            else if (S > 9)
                S -= 9, ans += '9';
            else {
                ans += (char)(S + '0');
                S = 0;
            }
        }
        return S ? "-1" : ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}   // } Driver Code Ends