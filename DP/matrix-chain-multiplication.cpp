#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int util(int arr[], int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            ans = min(ans, (arr[i - 1] * arr[k] * arr[j]) + util(arr, i, k) + util(arr, k + 1, j));
        }
        return dp[i][j] = ans;
    }
    vector<vector<int>> dp;
    int matrixMultiplication(int N, int arr[]) {
        dp = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
        return util(arr, 1, N - 1);
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}