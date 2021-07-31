#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
   public:
    void util(int n, int from, int to, int aux, long long int& ans) {
        //Your code here
        if (n == 1) {
            cout << "move disk 1 from rod " << from << " to rod " << to << endl;
            ans++;
            return;
        }
        util(n - 1, from, aux, to, ans);
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        ans++;
        util(n - 1, aux, to, from, ans);
    }

    long long toh(int n, int from, int to, int aux) {
        long long int ans = 0;
        util(n, from, to, aux, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;   //testcases
    while (T--) {
        int N;
        cin >> N;   //taking input N

        //calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

//Position this line where user code will be pasted.  // } Driver Code Ends