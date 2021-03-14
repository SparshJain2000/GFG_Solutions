// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}   // } Driver Code Ends

// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required

vector<vector<int>> fourSum(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int reqd = k - arr[i] - arr[j];
            int l = j + 1, r = n - 1;
            while (l < r) {
                if (arr[l] + arr[r] == reqd) ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                if (arr[l] + arr[r] < reqd)
                    l++;
                else
                    r--;
            }
        }
    }
    set<vector<int>> s(ans.begin(), ans.end());
    return vector<vector<int>>(s.begin(), s.end());
}