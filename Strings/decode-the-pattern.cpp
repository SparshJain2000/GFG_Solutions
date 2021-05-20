// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    string lookandsay(int n) {
        // code here
        string ans = "1";
        if (n-- == 1) return ans;
        while (n--) {
            vector<pair<char, int>> m;
            int i = 0;
            while (i < ans.size()) {
                char c = ans[i];
                int j = i + 1;
                while (j < ans.size() && ans[j] == ans[i]) j++;
                m.push_back({c, j - i});
                i = j;
            }
            ans = "";
            for (auto p : m)
                ans = ans + (char)(p.second + '0') + p.first;
        }
        return ans;
    }
};
/*
1
11
21
1211
111221
312211
13112221
*/
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.lookandsay(n) << endl;
    }
    return 0;
}   // } Driver Code Ends