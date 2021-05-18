// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(str1.length()+1,vector<int>(str2.length()+1,0));
	    for(int i=1;i<=str1.length();i++){
	        for(int j=1;j<=str2.length();j++){
	            if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	        }
	    }
	   // for(auto v:dp){
	   //     for(int i:v) cout<<i<<" ";
	   //     cout<<endl;
	   // }
	    int n= dp[str1.length()][str2.length()];
	    return str1.length()-n + str2.length()-n;
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends