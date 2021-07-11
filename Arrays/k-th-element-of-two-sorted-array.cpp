// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        //O(nlogn + mlogm) time O(1) space
        for (int i = 0; i < min(n, m); i++)
            if (arr1[n - i - 1] > arr2[i]) swap(arr1[n - i - 1], arr2[i]);
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
        if (k <= n) return arr1[k - 1];
        return arr2[k - n - 1];

        //O(k) time O(1) space
        int i = 0, j = 0;
        int ans = 0;
        while (i < n && j < m && --k) {
            if (arr1[i] < arr2[j])
                i++;
            else
                j++;
            ans = min(arr1[i], arr2[j]);
        }
        while (k--) {
            if (i < n) ans = arr1[i++];
            if (j < m) ans = arr2[j++];
        }

        return ans;
    }
};

// { Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
}   // } Driver Code Ends