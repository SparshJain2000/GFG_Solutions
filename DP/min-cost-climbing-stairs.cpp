// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost, int n) {
        //Write your code here
        int a = 0;
        if (n == 1) return a;
        int b = min(cost[1], cost[0]);
        if (n == 2) return b;
        for (int i = 2; i < n; i++) {
            int temp = b;
            b = min(b + cost[i], a + cost[i - 1]);
            a = temp;
        }
        return b;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> cost(N);

        for (int i = 0; i < N; i++) {
            cin >> cost[i];
        }

        Solution ob;
        cout << ob.minCostClimbingStairs(cost, N);
        cout << "\n";
    }
    return 0;
}   // } Driver Code Ends