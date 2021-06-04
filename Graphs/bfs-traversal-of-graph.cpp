// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void bfs(int s, vector<int> g[], vector<bool> &vis, int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        vector<bool> vis(N, false);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bfs(0, adj, vis, N);
        cout << endl;
    }
}   // } Driver Code Ends

/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {
    queue<int> q;
    q.push(s);
    // vis[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < g[x].size(); i++) {
            if (!vis[g[x][i]]) {
                q.push(g[x][i]);
                vis[g[x][i]] = true;
            }
        }
    }
}