#include <bits/stdc++.h>
using namespace std;

// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input arrau
// m, n: size of arrays X[] and Y[] respectively
long long countPairs(int X[], int Y[], int m, int n) {
    //Bruteforce O(n*m)
    /*
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            int x = X[i];
            for (int j = 0; j < n; j++) {
                int y = Y[j];
                if (pow(x, y) > pow(y, x)) ans++;
            }
        }
        return ans;
    */
    /*
        If x = 0, then the count of pairs for this x is 0.
        If x = 1, then the count of pairs for this x is equal to count of 0s in Y[].
        x smaller than y means x^y is greater than y^x.
            x = 2, y = 3 or 4
            x = 3, y = 2
    */
    //x^y > y^x if y>x
    long long ans = 0;
    int Ycounts[5];
    sort(Y, Y + n);
    for (int i = 0; i < n; i++)
        if (Y[i] < 5) Ycounts[Y[i]]++;

    for (int i = 0; i < m; i++) {
        int x = X[i];
        if (x == 0) continue;
        if (x == 1) {
            ans += Ycounts[0];
            continue;
        }
        ans += (Y + n) - upper_bound(Y, Y + n, x);
        ans += Ycounts[0] + Ycounts[1];
        if (x == 2) ans -= (Ycounts[3] + Ycounts[4]);
        if (x == 3) ans += Ycounts[2];
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        int i, a[M], b[N];
        for (i = 0; i < M; i++)
            cin >> a[i];
        for (i = 0; i < N; i++)
            cin >> b[i];

        cout << countPairs(a, b, M, N) << endl;
    }
}