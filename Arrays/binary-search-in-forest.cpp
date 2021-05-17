// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int find_height(int tree[], int n, int k) {
        // code here
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
            pq.push(tree[i]);

        int min = 0;
        int max = pq.top();

        while (min <= max) {
            int mid = (min + max) / 2;
            int res = 0;
            for (int i = 0; i < n; i++)
                if (tree[i] > mid)
                    res += tree[i] - mid;

            if (res == k)
                return mid;

            if (res > k)
                min = mid + 1;
            else
                max = mid - 1;
        }

        return -1;
    }
};
//13 36 38 65 69 81

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;

        int tree[n];
        for (int i = 0; i < n; i++)
            cin >> tree[i];
        cin >> k;
        Solution ob;
        cout << ob.find_height(tree, n, k) << endl;
    }
    return 1;
}   // } Driver Code Ends