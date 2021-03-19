#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}