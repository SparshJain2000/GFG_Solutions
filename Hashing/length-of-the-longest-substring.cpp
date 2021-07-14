// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int longestUniqueSubsttr(string s) {
        //code
        vector<int> mp(27, 0);
        int n = s.length();
        if (n == 1) return 1;
        int i = 0, j = 0;
        mp[s[i] - 'a']++;
        int ans = 0;
        while (i < n && j + 1 < n) {
            if (mp[s[j + 1] - 'a'] >= 1)
                mp[s[i++] - 'a']--;
            else
                mp[s[++j] - 'a']++, ans = max(ans, j - i + 1);
            // ,cout<<s.substr(i,j-i+1)<<endl;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}   // } Driver Code Ends