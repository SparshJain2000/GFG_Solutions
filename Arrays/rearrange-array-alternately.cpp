
#include <bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n) {
    //O(N) time O(N) space
    /*
        vector<int> v(n, 0);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            v[i] = i & 1 ? arr[l++] : arr[r--];
        }
        for (int i = 0; i < n; i++) arr[i] = v[i];
    */
    //O(N) time O(1) space
    long long max_ele = *max_element(arr, arr + n) + 1;
    int r = n - 1, l = 0;
    for (int i = 0; i < n; i++) {
        arr[i] += i & 1 ? (arr[l++] % max_ele) * max_ele : (arr[r--] % max_ele) * max_ele;
    }
    for (int i = 0; i < n; i++) arr[i] /= max_ele;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;   //size of array
        cin >> n;

        long long arr[n];   //adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        rearrange(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
