// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // C(n, r) = C(n-1, r-1) + C(n-1, r)
    // C(n, 0) = C(n, n) = 1
    int mod=1e9+7;
    vector<long long int>facts;
    long long int fact(int n){
        if(n==0) return 1;
        if(facts[n]!=-1) return facts[n];
        return facts[n]=(fact(n-1)*n);
    }
    int util(int n,int r){
        if(r==0 || n==r) return dp[n][r]=1;
        if(dp[n][r]!=-1) return dp[n][r];
        return dp[n][r]=(util(n-1,r-1)+util(n-1,r))%mod;
    }
    vector<vector<int>>dp;
    int nCr(int n, int r){
        /*
        Naīve method : 
        if(r>n) return 0;
        else if(r==n) return 1;
        facts=vector<long long int>(n+1,-1);
        int x=max(r,n-r);
        int y=min(r,n-r);
        long long int z=1;
        for(int i=n;i>x;i--) z*=i;
        return (int)(z/fact(y))%mod;
        */
        if(r>n) return 0;
        else if(r==n) return 1;
        dp=vector<vector<int>>(n+1,vector<int>(r+1,-1));
        return util(n,r);
    }
};
//nCr= n!/r!*(n-r)!
// 15C3 = 14
// 5c3=4c2+4c3;
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends