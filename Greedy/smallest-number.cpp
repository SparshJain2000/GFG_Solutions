// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    string smallestNumber(int S, int D) {
        string ans = "";
        while (D--) {
            if (S > 9)
                S -= 9, ans = "9" + ans;
            else {
                if (D)
                    ans = (char)(S - 1 + '0') + ans, S = 1;
                else
                    ans = (char)(S + '0') + ans, S = 0;
            }
        }
        return (S != 0) ? "-1" : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S, D) << endl;
    }
    return 0;
}   // } Driver Code Ends