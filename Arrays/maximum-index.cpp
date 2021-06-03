// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) {
        vector<int> mi(n, -1);
        vector<int> ma(n, -1);
        mi[0] = arr[0];
        ma[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) {
            mi[i] = min(arr[i], mi[i - 1]);
            ma[n - i - 1] = max(arr[n - i - 1], ma[n - i]);
        }

        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n && i < n) {
            if (ma[j] >= mi[i]) {
                ans = max(ans, j - i);
                j++;
            }
            if (ma[j] < mi[i]) i++;
        }
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test above functions */
int main() {
    int T;
    //testcases
    cin >> T;
    while (T--) {
        int num;
        //size of array
        cin >> num;
        int arr[num];

        //inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        //calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}   // } Driver Code Ends