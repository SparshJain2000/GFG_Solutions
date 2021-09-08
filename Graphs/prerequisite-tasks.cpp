// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[N];
        vector<int> deg(N, 0);

        for (auto p : prerequisites) {
            int u = p.second;
            int v = p.first;
            adj[u].push_back(v);
            deg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
            if (deg[i] == 0)
                q.push(i);

        int temp = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                deg[v]--;

                if (deg[v] == 0) q.push(v);
            }

            temp++;
        }
        return temp == N;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}   // } Driver Code Ends