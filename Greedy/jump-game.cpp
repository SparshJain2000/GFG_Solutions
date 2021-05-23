// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int canReach(int A[], int N) {
        int i = 0;
        while (i < N) {
            int me = i + A[i];
            int k = i;
            for (int j = i + 1; j <= min(i + A[i], N - 1); j++) {
                if (me < j + A[j]) {
                    me = j + A[j];
                    k = j;
                }
            }
            if (me >= N - 1) return 1;
            if (k == i) return 0;
            i = k;
        }
        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.canReach(A, N) << endl;
    }
    return 0;
}   // } Driver Code Ends