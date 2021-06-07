// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    //Function to detect cycle in an undirected graph.
    bool util(int v, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (visited[i] && i != parent) return true;
            if (!visited[i] && util(i, adj, visited, v)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V + 1, false);
        for (int i = 0; i < V; i++)
            if (!visited[i] && util(i, adj, visited, -1)) return true;
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}   // } Driver Code Ends