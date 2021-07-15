// { Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    string Reduced_String(int k, string s) {
        string ans = "";
        if (k == 1) return ans;
        stack<pair<char, int>> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top().first == s[i]) {
                count = st.top().second + 1;
                st.push({s[i], count});
                if (count == k) {
                    while (count > 0) {
                        count--;
                        st.pop();
                    }
                }
            } else {
                count = 1;
                st.push({s[i], count});
            }
        }
        while (!st.empty()) ans += st.top().first, st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        Solution obj;
        cout << obj.Reduced_String(k, s) << "\n";
    }

    return 0;
}   // } Driver Code Ends