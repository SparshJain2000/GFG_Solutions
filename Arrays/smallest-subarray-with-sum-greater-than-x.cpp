// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int sb(int arr[], int n, int x) {
        int ans = INT_MAX;
        int l = 0;
        int sum = arr[l];
        if (sum > x) return 1;
        for (int i = 1; i < n; i++) {
            sum += arr[i];
            while (sum > x && l <= i) {
                ans = min(ans, i - l + 1);
                sum -= arr[l++];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
}   // } Driver Code Ends