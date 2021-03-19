// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (v[i].first > prev) {
                ans++;
                prev = v[i].second;
            }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;

    //testcases
    cin >> t;
    while (t--) {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}