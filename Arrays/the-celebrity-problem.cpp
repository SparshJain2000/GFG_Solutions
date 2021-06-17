// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        // code here

        // for(int j=0;j<M[0].size();j++){
        //     int sum=0;
        //     for(int i=0;i<n;i++)
        //         sum+=M[i][j];

        //     if(sum==n-1){
        //         int i=0;
        //         for(i=0;i<n;i++)
        //             if(M[i][j]==0) break;
        //         for(int k=0;k<M[0].size();k++)
        //             if(M[i][k]==1) return -1;
        //         return i;
        //     }
        // }
        // return -1;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (M[i][j] && !M[j][i])
                i++;
            else if (M[j][i] && !M[i][j])
                j--;
            else
                i++, j--;
        }
        for (int k = 0; k < M[0].size(); k++)
            if (i != k && (M[i][k] == 1 || M[k][i] == 0)) return -1;
        return i;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends