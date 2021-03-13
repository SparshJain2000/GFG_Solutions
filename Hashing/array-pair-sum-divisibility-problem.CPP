#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> m;
        if (nums.size() & 1) return false;
        for (int &i : nums) i = i % k;
        for (int i : nums) m[i]++;
        for (int i : nums) {
            if (m[i] && m[(k - i) % k]) {
                m[i]--, m[(k - i) % k]--;
                if (m[i] < 0 || m[(k - i) % k] < 0) return false;
            } else if (m[i] && !m[(k - i) % k])
                return false;
            else if (!m[i] && m[(k - i) % k])
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}   // } Driver Code Ends