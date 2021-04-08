// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp(20, 0);
        for (int i : a) temp[i]++;
        for (int i : b) temp[i]++;
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < p; i++) m[a[i]] = {b[i], d[i]};
        for (int i = 1; i <= 20; i++) {
            if (temp[i] == 1 && m.find(i) != m.end()) {
                int x = i;
                int dia = INT_MAX;
                while (m.find(x) != m.end()) {
                    dia = min(dia, m[x].second);
                    x = m[x].first;
                    m[i] = {x, dia};
                }
                ans.push_back({i, m[i].first, m[i].second});
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t, n, p;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++) {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer) {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
}   // } Driver Code Ends