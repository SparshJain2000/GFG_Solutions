// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    int rightmostNonZeroDigit(int n, int a[]) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            while (a[i] > 0 && !(a[i] % 5)) cnt++, a[i] /= 5;

        for (int i = 0; i < n; i++) {
            if (!cnt) break;
            while (cnt && a[i] > 0 && !(a[i] % 2)) cnt--, a[i] /= 2;
        }
        long long int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = ((ans % 10) * (a[i] % 10)) % 10;
        }
        if (!ans) return -1;
        if (cnt) return 5;
        return ans % 10;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.rightmostNonZeroDigit(n, A) << endl;
    }
    return 0;
}   // } Driver Code Ends