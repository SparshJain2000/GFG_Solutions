#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n) {
    int sum = 0, max_sum = 0, max_ele = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) sum = 0;
        max_sum = max(sum, max_sum);
        max_ele = max(max_ele, arr[i]);
    }
    return max_sum ? max_sum : max_ele;
}

int main() {
    int t, n;

    cin >> t;     //input testcases
    while (t--)   //while testcases exist
    {
        cin >> n;   //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];   //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends