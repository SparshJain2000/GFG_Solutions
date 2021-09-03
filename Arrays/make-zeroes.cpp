// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int check(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    void MakeZeros(vector<vector<int>>& matrix) {
        // Code here
        vector<vector<int>> util;
        util = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    int temp = 0;
                    if (check(i - 1, j, matrix.size(), matrix[i].size()))
                        temp += matrix[i - 1][j], util[i - 1][j] = 0;
                    if (check(i, j + 1, matrix.size(), matrix[i].size()))
                        temp += matrix[i][j + 1], util[i][j + 1] = 0;
                    if (check(i + 1, j, matrix.size(), matrix[i].size()))
                        temp += matrix[i + 1][j], util[i + 1][j] = 0;
                    if (check(i, j - 1, matrix.size(), matrix[i].size()))
                        temp += matrix[i][j - 1], util[i][j - 1] = 0;

                    util[i][j] = temp;
                }
            }
        }
        matrix = util;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution ob;
        ob.MakeZeros(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}   // } Driver Code Ends