// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    // A1[] : the input array-1
    // A2[] : the input array-2;
    vector<int> sortA1ByA2(vector<int> a, int N, vector<int> b, int M) {
        //using unordered map and then sorting
        /*
            unordered_map<int, int> m;
            for (int i = 0; i < b.size(); i++)
                m[b[i]] = i;
            sort(a.begin(), a.end(), [m](const int &x, const int &y) {
                auto a = m.find(x);
                auto b = m.find(y);
                if (a == m.end() && b == m.end()) return x < y;
                if (a == m.end()) return false;
                if (b == m.end()) return true;
                return a->second < b->second;
            });
        */
        //using map(store in sorted order) and kind of counting sort
        map<int, int> m;
        int k = 0;
        for (int i : a) m[i]++;
        for (int i : b) {
            int n = m[i];
            while (n--) a[k++] = (i);
            m[i] = 0;
        }
        for (auto p : m)
            while (p.second--)
                a[k++] = (p.first);
        return a;
    }
};
int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a1(n);
        vector<int> a2(m);
        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }
        Solution ob;
        a1 = ob.sortA1ByA2(a1, n, a2, m);
        for (int i = 0; i < n; i++)
            cout << a1[i] << " ";
        cout << endl;
    }
    return 0;
}