// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
	public:
    	long long findNth(long long N)
    {
        if(N<=0) return 0;
        string ans="";
        while(N){
            ans=(char)((N%9)+'0')+ans;
            N/=9;
        }
        long long res=0;
        for(char c:ans) res*=10,res+=(c-'0');
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}

  // } Driver Code Ends