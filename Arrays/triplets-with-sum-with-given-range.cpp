// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    int countTriplets(int arr[], int n, int L, int R) {
        // code here
        sort(arr, arr + n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum <= R) ans += (k - j);
                if (sum > R)
                    k--;
                else
                    j++;
            }
        }

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < L) ans -= (k - j);
                if (sum >= L)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
// 2 3 5 8
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}   // } Driver Code Ends