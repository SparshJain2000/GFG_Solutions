// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int maxCalories(int arr[], int n) {
        // Your code goes here
        vector<int> sum(n + 1, 0);
        sum[0] = arr[0];
        sum[1] = arr[0] + arr[1];
        for (int i = 2; i < n; i++)
            sum[i] = max(sum[i - 1], max(sum[i - 2] + arr[i], sum[i - 3] + arr[i] + arr[i - 1]));
        return sum[n - 1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxCalories(a, n) << "\n";
    }
    return 0;
}   // } Driver Code Ends