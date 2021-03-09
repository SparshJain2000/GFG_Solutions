#include <bits/stdc++.h>
using namespace std;
/*
    Given two lists V1 and V2 of sizes n and m respectively. 
    Return the list of elements common to both the lists and return the list in sorted order. Duplicates may be there in the output list.
*/

vector<int> common_element(vector<int> v1, vector<int> v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    auto lit = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v1.begin());
    return vector<int>(v1.begin(), lit);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v1(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        int m;
        cin >> m;
        vector<int> v2(m, 0);
        for (int i = 0; i < m; i++) {
            cin >> v2[i];
        }
        vector<int> result;
        result = common_element(v1, v2);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;
    }
}   // } Driver Code Ends