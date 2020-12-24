#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string printLargest(vector<string> &arr) {
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            // int i = 0;
            // for (; i < min(a.length(), b.length()); i++)
            //     if (a[i] != b[i]) return a[i] < b[i];

            // if (i == a.length()) return (a[0] < b[i]);
            // if (i == b.length()) return (a[i] < b[0]);
            // return false;
            return a + b < b + a;
        });
        string ans = "";
        for (auto s = arr.rbegin(); s != arr.rend(); s++) ans += *s;
        return ans;
    }
};

//787
//78
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }

    return 0;
}
/*
1
4
54 546 548 60
*/