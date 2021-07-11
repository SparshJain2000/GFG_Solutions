// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int N, int k) {
        int l = 0, h = N - 1;
        while (l <= h) {
            int p1 = l + (h - l) / 3;
            int p2 = h - (h - l) / 3;
            if (arr[p1] == k) return 1;
            if (arr[p2] == k) return 1;
            if (arr[p1] > k)
                h = p1 - 1;
            else if (arr[p2] < k)
                l = p2 + 1;
            else
                l = p1 + 1, h = p2 - 1;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        int arr[N];

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.ternarySearch(arr, N, K) << endl;
    }

    return 0;
}
// } Driver Code Ends