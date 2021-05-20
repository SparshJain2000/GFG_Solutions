// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution {
   public:
    ll FindMaxSum(ll arr[], ll n) {
        ll a = arr[0];
        if (n == 1) return a;
        ll b = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++) {
            ll temp = b;
            b = max(arr[i] + a, b);
            a = temp;
        }
        return b;
    }
};

// { Driver Code Starts.
int main() {
    //taking total testcases
    int t;
    cin >> t;
    while (t--) {
        //taking number of houses
        ll n;
        cin >> n;
        ll a[n];

        //inserting money of each house in the array
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        //calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends