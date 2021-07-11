// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
    // Function to find the trapped water between the blocks.
   public:
    int trappingWater(int arr[], int n) {
        vector<int> ma1(n + 1, 0);   //left max
        vector<int> ma2(n + 1, 0);   //right max
        ma1[0] = arr[0];
        ma2[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) ma1[i] = max(ma1[i - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) ma2[i] = max(ma2[i + 1], arr[i]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += min(ma1[i], ma2[i]) - arr[i];

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}   // } Driver Code Ends