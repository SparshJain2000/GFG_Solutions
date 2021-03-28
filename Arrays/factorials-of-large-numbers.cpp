// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    vector<int> factorial(int N) {
        vector<int> ans({1});
        for (int i = 2; i <= N; i++) {
            int carry = 0;
            for (int &j : ans) {
                long long int x = j * i + carry;
                j = x % 10;
                carry = x / 10;
            }
            string s = to_string(carry);
            reverse(s.begin(), s.end());
            for (char c : s) ans.push_back(c - '0');
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == 0) i++;
        return vector<int>(ans.begin() + i, ans.end());
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}   // } Driver Code Ends