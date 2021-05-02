// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n) {
        // your code here
        int mod = 1000000007;
        int a = 1, b = 2, c = 4;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        for (int i = 4; i <= n; i++) {
            int temp = c;
            c = ((long long int)c + a + b) % mod;
            int temp2 = b;
            b = temp;
            a = temp2;
        }
        return c;
    }
};
/*
1 = 1
2= f(1)+1 =2
3= f(1)*f(2) + f(1)*f(2) +f(3) =4
4= f(2)*f(2) + f(1)*f(3)  =7
5= 13
*/
// { Driver Code Starts.
int main() {
    //taking testcases
    int t;
    cin >> t;

    while (t--) {
        //taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        //calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}
// } Driver Code Ends