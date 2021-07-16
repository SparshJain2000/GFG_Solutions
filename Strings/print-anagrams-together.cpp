// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
vector<vector<string>> Anagrams(vector<string>& string_list);

// } Driver Code Ends
//User function Template for C++

vector<vector<string>> Anagrams(vector<string>& string_list) {
    unordered_map<string, vector<string>> m;
    for (auto s : string_list) {
        string w = s;
        sort(s.begin(), s.end());
        m[s].push_back(w);
    }
    vector<vector<string>> ans;
    for (auto x : m) ans.push_back(x.second);

    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        vector<vector<string>> result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends