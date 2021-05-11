// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    //DP approach
    int minOperationRec(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (n & 1) return 1 + minOperationRec(n - 1);
        return 1 + min(minOperationRec(n - 1), minOperationRec(n / 2));
    }
    //Greedy
    int minOperation(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0;
        while (n) {
            if (n & 1)
                n -= 1;
            else
                n /= 2;
            a++;
        }
        return a;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
}   // } Driver Code Ends