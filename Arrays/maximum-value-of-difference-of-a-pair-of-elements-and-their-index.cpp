// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int maxValue(int arr[], int n) {
        // code here
        // arr[i] – arr[j] + i – j;     => arr[i]+i - (arr[j]+j)
        // - arr[i] + arr[j] + i – j;   => -arr[i]+i - (-arr[j]+j)
        // arr[i] – arr[j] + j – i;     => arr[i]-i - (arr[j]-j)
        // - arr[i] + arr[j] + j – i;   => -(arr[i]+i) + (arr[j]+j)

        int max_e = INT_MIN;
        int min_e = INT_MAX;
        int max_e2 = INT_MIN;
        int min_e2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            max_e = max(max_e, arr[i] + i);
            min_e = min(min_e, arr[i] + i);

            max_e2 = max(max_e2, arr[i] - i);
            min_e2 = min(min_e2, arr[i] - i);
        }

        return max(max_e - min_e, max_e2 - min_e2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxValue(arr, N) << endl;
    }
    return 0;
}   // } Driver Code Ends