// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans=0;
        vector<vector<int>> dp(N+1,vector<int>(N+2,0));
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]))+Matrix[i-1][j-1];
                // cout<<dp[i][j]<<endl;
                if(i==N) ans=max(ans,dp[N][j]);
            }
        }
        return ans;
    }
   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends