// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    long long int maximizeSum(long long int a[], int n, int k) {
        sort(a, a + n);
        long long int ans = accumulate(a, a + n, 0LL);
        long long int mi = INT_MAX;
        int i = 0;
        while (k--) {
            if (a[i] < 0) {
                mi = min(mi, a[i] * -1);
                ans -= 2 * a[i++];
            } else {
                mi = min(a[i], mi);
                ans -= 2 * mi;
                mi *= -1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
}   // } Driver Code Ends