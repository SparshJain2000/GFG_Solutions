// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    void print(list<int> l) {
        for (auto i : l) cout << i << " ";
        cout << endl;
    }
    int pageFaults(int N, int C, int pages[]) {
        // code here
        unordered_map<int, list<int>::iterator> m;
        list<int> cache;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (m.find(pages[i]) != m.end())
                cache.erase(m[pages[i]]);
            else if (C)
                ans++, C--;
            else {
                m.erase(cache.front());
                cache.pop_front();
                ans++;
            }
            cache.push_back(pages[i]);
            m[pages[i]] = --cache.end();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, C;
        cin >> N;
        int pages[N];
        for (int i = 0; i < N; i++)
            cin >> pages[i];
        cin >> C;

        Solution ob;
        cout << ob.pageFaults(N, C, pages) << "\n";
    }
    return 0;
}   // } Driver Code Ends