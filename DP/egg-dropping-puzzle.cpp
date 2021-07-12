// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int util(int i, int j, int e) {
        if (j - i + 1 == 0 || j - i + 1 == 1) return j - i + 1;
        if (e == 1) return j - i + 1;
        if (e == 0) return 0;
        // if(i==j) return i;
        if (dp[e][j - i + 1] != -1) return dp[e][j - i + 1];
        int ans = INT_MAX;
        for (int k = i; k <= j; k++) {
            ans = min(ans, 1 + max(util(i, k - 1, e - 1), util(k + 1, j, e)));
        }
        return dp[e][j - i + 1] = ans;
    }
    int dp[202][202];
    int eggDrop(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return util(1, k, n);
    }
};

// { Driver Code Starts.
int main() {
    //taking total testcases
    int t;
    cin >> t;
    while (t--) {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        //calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends