// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int countWays(int n) {
        int mod = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int temp = b;
            b = (b + a) % mod;
            a = temp;
        }
        return b % mod;
    }
};

/*
f(1)=1
f(2)=f(1)+1;
f(3)=f(2)+f(1)
f(4)=f(3)+f(2)
*/

// { Driver Code Starts.
int main() {
    //taking total testcases
    int t;
    cin >> t;
    while (t--) {
        //taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;   // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends