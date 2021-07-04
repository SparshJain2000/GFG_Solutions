// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
typedef pair<int, int> pi;
class Solution {
   public:
    int min_sprinklers(int gallery[], int n) {
        vector<pi> range;
        for (int i = 0; i < n; i++)
            if (gallery[i] != -1) range.push_back({max(i - gallery[i], 0), min(n - 1, i + gallery[i])});
        sort(range.begin(), range.end(), [](const pi &a, const pi &b) { return a.first < b.first; });

        int ans = 0;
        int j = 0, i = 0;

        while (i < n) {
            int e = -1;
            while (j < range.size() && range[j].first <= i) {
                if (range[j].second > e) e = range[j].second;
                j++;
            }
            if (e == -1) return -1;
            ans++;
            i = e + 1;
        }
        return ans;
    }
};

/*
0-3
0-4
4
5
*/
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int gallery[n];
        for (int i = 0; i < n; i++)
            cin >> gallery[i];
        Solution obj;
        cout << obj.min_sprinklers(gallery, n) << endl;
    }
    return 1;
}
// } Driver Code Ends