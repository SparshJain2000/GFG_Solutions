// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], vector<bool> &vis);

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, g, vis);

        cout << endl;
    }
}   // } Driver Code Ends
void dfs(int s, vector<int> g[], bool vis[]) {
    if (vis[s]) return;
    cout << s << " ";
    vis[s] = true;
    for (int i = 0; i < g[s].size(); i++) {
        if (!vis[g[s][i]])
            dfs(g[s][i], g, vis);
    }
}