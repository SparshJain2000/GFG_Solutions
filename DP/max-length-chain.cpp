// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val {
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}   // } Driver Code Ends

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

int maxChainLen(struct val p[], int n) {
    sort(p, p + n, [](struct val &a, struct val &b) {
        return a.second < b.second;
    });
    vector<int> dp(n + 1, 1);
    dp[0] = 0;
    int pre = INT_MIN;
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (p[i - 1].first > p[j - 1].second)
                dp[i] = max(dp[i], dp[j] + 1);
        ;
        ans = max(ans, dp[i]);
    }
    return ans;
}