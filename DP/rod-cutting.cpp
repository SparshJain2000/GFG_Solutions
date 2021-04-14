#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << cutRod(a, n) << endl;
    }
    return 0;
}
int cutRod(int price[], int n) {
    vector<int> arr(n, 0);
    arr[0] = price[0];
    for (int i = 1; i < n; i++) {
        int temp = price[i];
        for (int j = 0; j <= (i / 2); j++)
            temp = max(temp, arr[j] + arr[i - j - 1]);
        arr[i] = temp;
    }
    return arr[n - 1];
}
// X(1)=1;
// x(2)=MAX(2*X(1),L(2));
// X(3)=max(X(2)+X(1),L(3));
// X(4)=max(X(2)+x(2),X(3)+X(1),L(4));
// X(5)=max(X(3)+x(2),X(4)+X(1),L(5));
// X(6)=max(X(3)+x(3),X(4)+X(2),X(5)+X(1),L(6));