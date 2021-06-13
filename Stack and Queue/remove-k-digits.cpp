// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    string removeKdigits(string S, int k) {
        stack<char> st;
        for (char c : S) {
            while (!st.empty() && k && c < st.top()) {
                k--;
                st.pop();
            }
            st.push(c);
        }
        while (k) st.pop(), k--;
        string ans = "";
        while (!st.empty()) ans = st.top() + ans, st.pop();
        int i = 0;
        while (ans[i] == '0') i++;
        ans = string(ans.begin() + i, ans.end());
        return ans == "" ? "0" : ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends