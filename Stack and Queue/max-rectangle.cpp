// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
   public:
    int util(int arr[], int n) {
        stack<int> s;
        int max_area = 0;
        int tp;
        int temp_area;
        int i = 0;
        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i])
                s.push(i++);
            else {
                tp = s.top();
                s.pop();
                temp_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if (max_area < temp_area)
                    max_area = temp_area;
            }
        }
        while (s.empty() == false) {
            tp = s.top();
            s.pop();
            temp_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < temp_area)
                max_area = temp_area;
        }

        return max_area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) M[i][j] += M[i - 1][j];
            }
            ans = max(ans, util(M[i], m));
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends