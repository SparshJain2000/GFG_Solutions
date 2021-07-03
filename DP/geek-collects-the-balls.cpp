// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    int maxBalls(int N, int M, int a[], int b[]) {
        // code here
        int i = 0, j = 0;

        int ans = 0;
        while (i < N && j < M) {
            int x = 0, y = 0;
            while (i < N && j < M && a[i] != b[j]) {
                if (a[i] > b[j])
                    y += b[j++];
                else
                    x += a[i++];
            }
            if (a[i] != b[j]) {
                while (i < N) x += a[i++];
                while (j < M) y += b[j++];
            } else {
                int temp = a[i];
                while (i < N && a[i] == temp) x += a[i++];
                while (j < M && b[j] == temp) y += b[j++];
            }
            ans += max(x, y);
        }
        while (i < N) ans += a[i++];
        while (j < M) ans += b[j++];
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxBalls(N, M, a, b) << "\n";
    }
    return 0;
}   // } Driver Code Ends