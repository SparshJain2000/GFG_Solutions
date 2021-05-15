// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int> arr, int sum) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int x = arr[i] + arr[j] + arr[k];
                if (abs(x - sum) == abs(ans - sum)) ans = max(ans, x);
                if (abs(x - sum) < abs(ans - sum)) ans = x;
                if (x == sum) return sum;
                if (x < sum)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;

        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}