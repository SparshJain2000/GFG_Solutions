// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int nthStair(int n) {
        //  Code here
        /*        
            int ans = 1;
            for (int i = 1; i <= n; i++)
            if (!(i & 1)) ans++;
            return ans;
        */
        return (n / 2) + 1;
    }
};
/*
1 = 1
2 = 2
3 = 2
4 = 3
5 = 3
6 = 4
7 = 4
8 = 5
*/
// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
}   // } Driver Code Ends