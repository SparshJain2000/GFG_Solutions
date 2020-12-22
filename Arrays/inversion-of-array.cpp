#include <bits/stdc++.h>
using namespace std;
long long int ans = 0;
// Function to find inversion count in the array
// arr[]: Input Array
// N : Size of the Array arr[]
void merge(long long arr[], long long l, long long mid, long long r) {
    vector<int> v;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            v.push_back(arr[i++]);
        else
            v.push_back(arr[j++]), ans += mid - i + 1;
    }
    while (i <= mid) v.push_back(arr[i++]);
    while (j <= r) v.push_back(arr[j++]);
    for (int i = l; i <= r; i++) arr[i] = v[i - l];
}
void mergeSort(long long arr[], long long l, long long r) {
    if (l >= r) return;
    int mid = (l + r - 1) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

long long int inversionCount(long long arr[], long long N) {
    // Your Code Here
    ans = 0;
    mergeSort(arr, 0, N - 1);
    return ans;
}
int main() {
    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;
        long long A[N];
        for (long long i = 0; i < N; i++)
            cin >> A[i];
        cout << inversionCount(A, N) << endl;
    }
    return 0;
}
/*
1
5
2 3 4 5 6
*/