// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int maxCalories(int arr[], int n) {
        // Your code goes here
        //O(N) space O(N) time
        // vector<int> sum(n + 1, 0);
        // sum[0] = arr[0];
        // sum[1] = arr[0] + arr[1];
        // sum[2] = max(arr[0] + arr[1], max(arr[0] + arr[2], arr[2] + arr[1]));
        // for (int i = 3; i < n; i++)
        // for (int i = 2; i < n; i++)
        //     sum[i] = max(sum[i - 1], max(sum[i - 2] + arr[i], sum[i - 3] + arr[i] + arr[i - 1]));
        // return sum[n - 1];

        //O(1) space O(N) time
        int a = arr[0];
        if (n == 1) return a;
        int b = arr[0] + arr[1];
        if (n == 2) return b;
        int c = max(arr[0] + arr[1], max(arr[0] + arr[2], arr[2] + arr[1]));
        if (n == 3) return c;
        for (int i = 3; i < n; i++) {
            int temp = c;
            c = max(c, max(b + arr[i], a + arr[i] + arr[i - 1]));
            a = b;
            b = temp;
        }
        return c;
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