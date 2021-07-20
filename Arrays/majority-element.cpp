// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    //BOYER MOORE VOTING ALGORITHM
    int majorityElement(int a[], int size) {
        if (size == 1) return a[0];
        int major = a[0];
        int count = 1;
        for (int i = 1; i < size; i++) {
            if (a[i] == major)
                count++;
            else
                count--;

            if (count == 0) major = a[i], count = 1;
        }
        count = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] == major) count++;
            if (count > size / 2) return major;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends