// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k) {
        vector<int> ans(k, 0);
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < n; i++) {
            p.push(arr[i]);
            if (k-- <= 0) p.pop();
        }

        int i = ans.size() - 1;
        while (!p.empty()) ans[i--] = p.top(), p.pop();
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}