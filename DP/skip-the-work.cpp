// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int minAmount(int A[], int N) {
        //code here.

        int a = 0;
        if (N == 0) return a;
        int b = A[0];
        if (N == 1) return b;
        for (int i = 2; i <= N; i++) {
            int temp = b;
            // if(a==b) b=min(b+A[i-1],b+A[i]);
            // else
            b = min(b, a) + A[i - 1];
            a = temp;
        }
        return min(b, a);
    }
};
/*
4
10 5 7 10
0 -> 10
1 -> 5
2 -> 

*/
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minAmount(arr, n) << endl;
    }
}   // } Driver Code Ends