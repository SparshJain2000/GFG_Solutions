// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    pair<long, long> indexes(vector<long long> v, long long x) {
        int l = 0;
        int h = v.size();
        int a1 = -1, a2 = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (v[mid] == x)
                a1 = mid, h = mid - 1;
            else if (v[mid] < x)
                l = mid + 1;
            else
                h = mid - 1;
        }

        l = 0;
        h = v.size();
        while (l <= h) {
            int mid = (l + h) / 2;
            if (v[mid] == x)
                a2 = mid, l = mid + 1;
            else if (v[mid] < x)
                l = mid + 1;
            else
                h = mid - 1;
        }

        if (a1 >= v.size()) return pair<long, long>({-1, -1});
        a2 = min((int)v.size() - 1, a2);
        return pair<long, long>({a1, a2});
    }
};

// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        vector<long long> v;
        cin >> n;
        for (long long i = 0; i < n; i++) {
            cin >> k;
            v.push_back(k);
        }
        long long x;
        cin >> x;
        Solution obj;
        pair<long, long> pair = obj.indexes(v, x);

        if (pair.first == pair.second and pair.first == -1)
            cout << -1 << endl;
        else
            cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}
// } Driver Code Ends