// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

//recursive with memo
vector<vector<vector<int>>> dp;
int util(string s1, string s2, string s3, int x, int y, int z) {
    if (x > s1.length() || y > s2.length() || z > s3.length()) return 0;
    if (dp[x][y][z] != -1) return dp[x][y][z];
    if (s1[x - 1] == s2[y - 1] && s2[y - 1] == s3[z - 1])
        dp[x][y][z] = 1 + util(s1, s2, s3, x + 1, y + 1, z + 1);
    else
        dp[x][y][z] = max(util(s1, s2, s3, x, y, z + 1), max(util(s1, s2, s3, x, y + 1, z), util(s1, s2, s3, x + 1, y, z)));
    return dp[x][y][z];
}
int LCSof3(string s1, string s2, string s3, int x, int y, int z) {
    // your code here
    dp = vector<vector<vector<int>>>(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, -1)));
    return util(s1, s2, s3, 1, 1, 1);
}
//iterative
int LCSof3(string s1, string s2, string s3, int x, int y, int z) {
    // your code here
    vector<vector<vector<int>>> dp(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, -1)));
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            for (int k = 0; k <= z; k++)
                if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 0;

    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            for (int k = 1; k <= z; k++) {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else {
                    if (s1[i - 1] == s2[j - 1]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                    if (s1[i - 1] == s3[k - 1]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    if (s3[k - 1] == s2[j - 1]) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                }
            }
    return dp[x][y][z] == -1 ? 0 : dp[x][y][z];
}