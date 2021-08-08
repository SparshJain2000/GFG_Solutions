// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int makeProductOne(int arr[], int N) {
        // code here
        int one = 0;
        int one_min = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] != 0) {
                ans += abs(arr[i]) - 1;
                if (arr[i] < 0)
                    one_min++;
                else
                    one++;
            }
        }
        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                if (one_min & 1)
                    one_min++;
                else
                    one++;
                ans++;
            }
        }
        if (!(one_min & 1)) return ans;
        return ans + 2;
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
        cout << ob.makeProductOne(arr, N) << endl;
    }
    return 0;
}   // } Driver Code Ends