// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int getSize(unordered_map<char, int>& m) {
        int ans = 0;
        for (auto p : m)
            if (p.second) ans++;
        return ans;
    }
    int longestKSubstr(string s, int k) {
        // your code here
        int n = s.length();
        int i = 0, j = 1;
        int ans = 0;
        unordered_map<char, int> mp;
        mp[s[0]]++;
        mp[s[1]]++;
        while (i < n && j < n) {
            if (mp.size() <= k) {
                if (mp.size() == k) ans = max(ans, j - i + 1);
                mp[s[++j]]++;

            } else if (mp.size() > k) {
                int x = mp[s[i]]--;
                if (x == 1) mp.erase(s[i]);
                i++;
            }
        }
        return ans == 0 ? -1 : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
// } Driver Code Ends