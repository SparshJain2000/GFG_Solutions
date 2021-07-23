// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X) {
        //Your Code Here
        sort(A, A + n);
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            int sum = X - A[i];
            while (j < k) {
                if (A[j] + A[k] == sum) return true;
                if (A[j] + A[k] < sum)
                    j++;
                else
                    k--;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends