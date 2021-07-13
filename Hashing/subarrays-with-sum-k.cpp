// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int findSubArraySum(int arr[], int N, int k) {
        // code here
        unordered_map<int, int> m;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (sum == k) ans++;
            // =m[0]?m[0]:1;
            if (m.find(sum - k) != m.end()) ans += m[sum - k];
            m[sum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.findSubArraySum(Arr, N, k) << endl;
    }
    return 0;
}   // } Driver Code Ends