// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int getCount(int N) {
        int n = 2, ans = 0;
        while (n * n - n - 2 * N < 0) {
            if ((2 * N + n - n * n) % (2 * n) == 0) ans++;
            n++;
        }
        return ans;
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
        cout << ob.getCount(N) << endl;
    }
    return 0;
}   // } Driver Code Ends