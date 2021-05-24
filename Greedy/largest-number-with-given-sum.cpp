// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return Largest Number

class Solution {
   public:
    string largestNumber(int n, int sum) {
        string ans = "";
        while (n && sum) {
            if (sum < 9) {
                ans += (char)(sum + '0');
                sum = 0;
            } else {
                ans += '9';
                sum -= 9;
            }
            n--;
        }
        if (sum && !n) return "-1";
        while (n--) ans += "0";
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    //taking testcases
    int t;
    cin >> t;

    while (t--) {
        //taking n and sum
        int n, sum;
        cin >> n >> sum;

        Solution obj;
        //function call
        cout << obj.largestNumber(n, sum) << endl;
    }
    return 0;
}   // } Driver Code Ends