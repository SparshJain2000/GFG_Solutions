#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool check(vector<ll>, vector<ll>, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n, 0), brr(n, 0);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        for (ll i = 0; i < n; i++)
            cin >> brr[i];

        cout << check(arr, brr, n) << "\n";
    }
    return 0;
}
bool check(vector<ll> arr, vector<ll> brr, int n) {
    unordered_map<ll, int> m1;
    for (int i : arr) m1[i]++;
    for (int i : brr) m1[i]--;
    for (auto x : m1)
        if (x.second != 0) return false;
    return true;
}