// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
   public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int l = 0, r = 0;
        int c0 = 0;
        int mi = 0;
        while (r < n) {
            c0 += arr[r] == 0;
            if (c0 <= m) mi = max(mi, r - l + 1);
            while (c0 > m) {
                l++;
                c0 -= (arr[l - 1] == 0);
                mi = max(mi, r - l + 1);
            }
            r++;
        }
        return mi;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}   // } Driver Code Ends