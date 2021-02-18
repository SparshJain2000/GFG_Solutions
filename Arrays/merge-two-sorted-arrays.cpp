#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    //O(n*m) time O(1) space
    /*
        int i = 0, j = 0;
        for (i = m - 1; i >= 0; i--) {
            int k = upper_bound(arr1, arr1 + n, arr2[i]) - arr1;
            if (k < n) {
                int temp = arr1[n - 1];
                for (j = n - 1; j > k; j--) arr1[j] = arr1[j - 1];
                arr1[k] = arr2[i];
                arr2[i] = temp;
            }
        }
    */

    //O(nlogn + mlogm)
    for (int i = 0; i < min(n, m); i++)
        if (arr1[n - i - 1] > arr2[i]) swap(arr1[n - i - 1], arr2[i]);
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);
        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);

        cout << endl;
    }
    return 0;
}

/*
1
4 5
1 3 5 7
0 2 6 8 9
*/