// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
typedef pair<int, int> pi;
class Solution {
   public:
    bool check(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    void bfs(vector<vector<int>> &hospital, int &ans, int &un) {
        if (un == 0) return;
        int n = hospital.size();
        int m = hospital[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < hospital[i].size(); j++)
                if (hospital[i][j] == 2) q.push({i, j});

        while (!q.empty()) {
            int qn = q.size();
            ans++;
            while (qn--) {
                auto x = q.front();
                q.pop();
                if (check(x.first, x.second, n, m)) {
                    if (hospital[x.first][x.second] == 1) un--;

                    if (un == 0) return;
                    // cout<<x.first<<" "<<x.second<<" : "<<un<<endl;
                    hospital[x.first][x.second] = 2;
                    if (check(x.first - 1, x.second, n, m) && hospital[x.first - 1][x.second] == 1) q.push({x.first - 1, x.second});
                    if (check(x.first + 1, x.second, n, m) && hospital[x.first + 1][x.second] == 1) q.push({x.first + 1, x.second});
                    if (check(x.first, x.second - 1, n, m) && hospital[x.first][x.second - 1] == 1) q.push({x.first, x.second - 1});
                    if (check(x.first, x.second + 1, n, m) && hospital[x.first][x.second + 1] == 1) q.push({x.first, x.second + 1});
                }
            };
        }
    }
    int helpaterp(vector<vector<int>> hospital) {
        int ans = 0;
        int un = 0;
        for (auto vi : hospital)
            for (int i : vi) un += i == 1;

        bfs(hospital, ans, un);
        return un ? -1 : ans - 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R;
        int C;

        cin >> R >> C;
        vector<vector<int>> hospital;
        int i, j;
        for (i = 0; i < R; i++) {
            vector<int> temp;
            for (j = 0; j < C; j++) {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
        }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}   // } Driver Code Ends