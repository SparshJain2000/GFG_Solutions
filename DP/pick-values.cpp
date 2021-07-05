// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    int pickValues(int arr[], int n) {
        // code here

        // int x=*min_element(arr,arr+4);
        // if(n<=4) return x;
        if (n < 4) return *min_element(arr, arr + n);
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[2];
        dp[3] = arr[3];
        for (int i = 4; i < n; i++) {
            // dp[i]=min(dp[i-4],arr[i]+((i-4<0)?0:dp[i-4]));
            // dp[i]=min(arr[i]+dp[i-4],dp[i-1]);
            // min(arr[i]+dp[i-4], arr[i-1]+dp[] )
            dp[i] = arr[i] + min(min(dp[i - 1], dp[i - 2]), min(dp[i - 3], dp[i - 4]));
            // dp[i]=min(
            //     min(arr[i]+((i-4<0)?0:dp[i-4]),dp[i-1]),
            //     min(dp[i-2],dp[i-3])
            // );
            // dp[i]=min(
            // min(arr[i]+((i-4<0)?0:dp[i-4]),
            //     arr[i-1]+((i-4<0)?0:dp[i-4])),
            // min(arr[i-2]+((i-4<0)?0:dp[i-4]),
            //     arr[i-3]+((i-4<0)?0:dp[i-4])));
            // cout<<dp[i]<<endl;
        }
        return *min_element(dp.begin() + n - 4, dp.end());
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.pickValues(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends