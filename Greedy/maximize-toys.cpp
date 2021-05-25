// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int toyCount(int N, int k, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int ans = 0, i = 0;
        while (i < N && k - arr[i] >= 0) {
            k -= arr[i++];
            ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.toyCount(N, K, arr) << endl;
    }
    return 0;
}   // } Driver Code Ends