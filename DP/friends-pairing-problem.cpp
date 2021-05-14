// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    long long mod = 1e9 + 7;

   public:
    int countFriendsPairings(int n) {
        // code here
        long long pre1 = 1;
        long long pre2 = 2;
        for (int i = 3; i <= n; i++) {
            long long temp = pre2;
            pre2 = (pre2 % mod + (pre1 * (i - 1)) % mod) % mod;
            pre1 = temp;
        }
        return n == 1 ? 1 : pre2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends