// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    string longestCommonPrefix(string arr[], int N) {
        // your code here
        string pre = "";
        for (int j = 0; j < arr[0].length(); j++) {
            char temp = arr[0][j];
            for (int i = 1; i < N; i++) {
                if (j >= arr[i].length() || arr[i][j] != temp)
                    return (pre == "" ? "-1" : pre);
            }
            pre += temp;
        }
        return (pre == "" ? "-1" : pre);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends