// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void sort012(int[], int);

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort012(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}

void sort012(int a[], int n) {
    int count[3] = {0};
    for (int i = 0; i < n; i++) count[a[i]]++;
    int i = 0;
    while (count[0]--) a[i++] = 0;
    while (count[1]--) a[i++] = 1;
    while (count[2]--) a[i++] = 2;
}
/*
1
5
2 2 1 0 1
*/