#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> dir{1, 0, -1, 0, 1};
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pii> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    q.push(pii(i, j));
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int ans = 0;
        if (!fresh) return ans;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto f = q.front();
                for (int i = 0; i < dir.size() - 1; i++) {
                    int x = f.first + dir[i];
                    int y = f.second + dir[i + 1];
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push(pii(x, y));
                        fresh--;
                    }
                }
            }
            ans++;
            if (!fresh) return ans;
        }
        return fresh ? -1 : ans;
    }
};
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}