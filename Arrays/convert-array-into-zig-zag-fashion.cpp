#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution {
   public:
    void zigZag(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (i & 1) {
                if (arr[i + 1] > arr[i])
                    swap(arr[i], arr[i + 1]);
            } else if (arr[i + 1] < arr[i])
                swap(arr[i], arr[i + 1]);
        }
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        ob.zigZag(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    return 0;
}
/*
1
7
4 3 7 8 6 2 1
*/