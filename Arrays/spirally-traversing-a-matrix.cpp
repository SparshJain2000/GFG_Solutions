#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        int r1 = 0, r2 = r - 1, c1 = c - 1, c2 = 0;
        vector<int> ans;
        while (r1 <= r2 && c1 >= c2) {
            if (r1 == r2)
                for (int i = c2; i <= c1; i++) ans.push_back(matrix[r1][i]);
            if (r1 != r2)
                for (int i = c2; i <= c1; i++) ans.push_back(matrix[r1][i]);
            if (c1 == c2)
                for (int i = r1 + 1; i <= r2 - 1; i++) ans.push_back(matrix[i][c1]);
            if (c1 != c2)
                for (int i = r1 + 1; i <= r2 - 1; i++) ans.push_back(matrix[i][c1]);
            if (r1 != r2)
                for (int i = c1; i >= c2; i--) ans.push_back(matrix[r2][i]);
            if (c1 != c2)
                for (int i = r2 - 1; i >= r1 + 1; i--) ans.push_back(matrix[i][c2]);

            r1++, r2--, c1--, c2++;
        }

        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int> > matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
                cin >> matrix[i][j];
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
/*
1
3 3
1 2 3 
5 6 7 
9 10 11
13 14 15 16
*/
// 29 9 13
// 10 12 4
// 6 20 19
// 25 1 28