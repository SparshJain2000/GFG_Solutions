// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int A[], int n, int f) {
        int m = INT_MIN;
        int sum = 0;
        if (!f)
            for (int i = 0; i < n; i++)
                A[i] = -A[i];
        for (int k = 0; k < n; k++) {
            sum += A[k];
            // cout << sum << " ";
            if (sum < 0)
                sum = 0;
            m = max(m, sum);
        }

        return (m == 0) ? (*max_element(A, A + n)) : m;
    }
    int circularSubarraySum(int A[], int n) {
        if (n == 1) return A[0];
        int m = kadane(A, n, 1);
        int mw = accumulate(A, A + n, 0) + kadane(A, n, 0);
        for (int i = 0; i < n; i++)
            A[i] = -A[i];
        if (max(mw, m) == 0) return *max_element(A, A + n);
        return max(mw, m);
    }
};

// { Driver Code Starts.

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
        //calling function
        cout << ob.circularSubarraySum(arr, num) << endl;
    }

    return 0;
}   // } Driver Code Ends