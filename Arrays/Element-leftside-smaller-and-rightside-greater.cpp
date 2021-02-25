#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> pre;
        vector<int> post;
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_ele = max(max_ele, arr[i]);
            pre.push_back(max_ele);
        }
        for (int i = n - 1; i >= 0; i--) {
            min_ele = min(min_ele, arr[i]);
            post.push_back(min_ele);
        }
        int ans = -1;
        for (int i = 1; i < n - 1; i++) {
            if (pre[i] == post[n - i - 1]) {
                ans = pre[i];
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
/*
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9
*/