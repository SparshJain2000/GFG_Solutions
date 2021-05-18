// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
   public:
    int maxSubstring(string S) {
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < S.length(); i++) {
            curr = max(curr + (S[i] == '1' ? -1 : 1), 0);
            ans = max(ans, curr);
        }
        return ans == 0 ? -1 : ans;
    }
};

// { Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends