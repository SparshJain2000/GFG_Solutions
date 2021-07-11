// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

int mod = 1e9 + 7;
class Solution {
   public:
    vector<long long> factorial(vector<long long> a, int n) {
        int m = *max_element(a.begin(), a.end());
        vector<long long> facts(m + 1, 1);
        long long int prod = 1;
        for (int i = 1; i <= m; i++) prod = (prod * i) % mod, facts[i] = prod;
        for (int i = 0; i < n; i++) a[i] = facts[a[i]];
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends