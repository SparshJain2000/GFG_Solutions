// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    int util(int N, vector<int> cost[], int ind) {
        // code here
        if (N == 0) return 0;
        int c = INT_MAX;
        for (int i = 0; i < 3; i++)
            if (ind != i)
                c = min(c, util(N - 1, cost, i) + cost[N - 1][i]);

        return c;
    }
    int minCost(int N, vector<int> cost[]) {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(3, 0));

        for (int i = 1; i <= N; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = cost[i - 1][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);

        return *min_element(dp[N].begin(), dp[N].end());
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> cost[N];
        int x, y, z;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }

        Solution ob;
        cout << ob.minCost(N, cost) << "\n";
    }
    return 0;
}   // } Driver Code Ends