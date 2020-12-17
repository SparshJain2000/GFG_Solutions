#include <bits/stdc++.h>
using namespace std;
//User function template for C++
class Solution {
   public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n) {
        // code here
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) arr[i] *= arr[i];
        for (int i = n - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] == arr[i]) return true;
                arr[l] + arr[r] < arr[i] ? l++ : r--;
            }
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
