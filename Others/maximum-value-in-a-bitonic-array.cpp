// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
   public:
    int findMaximum(int arr[], int n) {
        // code here
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid <= 0)
                l = mid + 1;
            else if (mid >= n - 1)
                r = mid - 1;
            else {
                if (arr[mid] < arr[mid - 1])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ans = max(ans, arr[mid]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends