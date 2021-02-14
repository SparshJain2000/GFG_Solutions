#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n) {
    vector<int> ans;
    int leader = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= leader) leader = arr[i], ans.push_back(leader);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        int a[n];
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> v = leaders(a, n);
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}
/*
1
5
1 2 3 4 0
*/