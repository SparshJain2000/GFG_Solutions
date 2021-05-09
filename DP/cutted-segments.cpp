// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    //taking testcases
    int t;
    cin >> t;
    while (t--) {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;

        //calling function maximizeTheCuts()
        cout << maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
}   // } Driver Code Ends

//Complete this function
//Recursive
int maximizeTheCuts(int n, int x, int y, int z) {
    if (n == 0) return 0;
    int ans = -1;
    if (x <= n) ans = max(ans, maximizeTheCuts(n - x, x, y, z));
    if (y <= n) ans = max(ans, maximizeTheCuts(n - y, x, y, z));
    if (z <= n) ans = max(ans, maximizeTheCuts(n - z, x, y, z));
    return ans + 1;
}
//recursive with memo
vector<int> dp;
int util(int n, int x, int y, int z) {
    if (n == 0) return 0;
    // if(n<0) return -2;
    int ans = -1;
    if (dp[n] != -1) return dp[n];
    if (x <= n) ans = max(ans, util(n - x, x, y, z));
    if (y <= n) ans = max(ans, util(n - y, x, y, z));
    if (z <= n) ans = max(ans, util(n - z, x, y, z));
    dp[n] = ans == -1 ? INT_MIN : ans + 1;
    return dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z) {
    dp = vector<int>(n, -1);
    int ans = util(n, x, y, z);
    return ans < 0 ? 0 : ans;
}
//iterative
int maximizeTheCuts(int n, int x, int y, int z) {
    dp = vector<int>(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (x <= i) dp[i] = max(dp[i], dp[i - x]);
        if (y <= i) dp[i] = max(dp[i], dp[i - y]);
        if (z <= i) dp[i] = max(dp[i], dp[i - z]);
        if (dp[i] != -1) dp[i]++;
    }
    return dp[n] == -1 ? 0 : dp[n];
}
