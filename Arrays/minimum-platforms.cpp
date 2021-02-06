// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int findPlatform(int arr[], int dep[], int n) {
    // Your code here
    vector<pi> v;
    for (int i = 0; i < n; i++) v.push_back(pi(arr[i], dep[i]));
    sort(
        v.begin(), v.end(), [](const pi& a, const pi& b) {
            return a.second < b.second;
        });
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = 1;
        for (int j = i + 1; j < n; j++) {
            if (v[j].first <= v[i].second) temp++;
        }
        ans = max(ans, temp);
        if (ans == n - 1) return ans;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        cout << findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
/*
1
6
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000

1
3
0900 1100 1235
1000 1200 1240
*/