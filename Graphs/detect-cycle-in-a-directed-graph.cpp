// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    bool util(int v, vector<int> adj[], vector<bool> visited, vector<bool> done) {
        visited[v] = true;
        done[v] = true;

        for (int i : adj[v]) {
            if (!visited[i] && util(i, adj, visited, done)) {
                return true;
            } else if (done[i])
                return true;
        }
        done[v] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> done(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i] && util(i, adj, visited, done)) return true;
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends