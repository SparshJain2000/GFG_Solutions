// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    for(int i=0;i<=V;i++) dp[0][i]=INT_MAX-1;
	    for(int i=0;i<=M;i++) dp[i][0]=0;
	    for(int i=1;i<=V;i++) dp[1][i]=(i%coins[0]==0)?(i/coins[0]):INT_MAX-1;
	    for(int i=2;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            if(coins[i-1]<=j)  dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    return dp[M][V]==INT_MAX-1?-1:dp[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends