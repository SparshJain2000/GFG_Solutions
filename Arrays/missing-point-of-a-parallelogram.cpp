// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    vector<double>min(vector<double>a,vector<double>b){
        if(a[0]!=b[0]) return (a[0]<b[0])?a:b;
        return (a[1]<b[1])?a:b;
    }
    vector<double> findPoint(int A[], int B[], int C[])
    {
        // your code here
        //AB - diagonal
        vector<double>a({A[0]+B[0]-C[0],A[1]+B[1]-C[1]});
        //AC - diagonal
        vector<double>b({A[0]-B[0]+C[0],A[1]-B[1]+C[1]});
        //BC - diagonal
        vector<double>c({-A[0]+B[0]+C[0],-A[1]+B[1]+C[1]});
        
        // cout<<a[0]<<" "<<a[1]<<endl;
        // cout<<b[0]<<" "<<b[1]<<endl;
        // cout<<c[0]<<" "<<c[1]<<endl;
        return min(a,min(c,b));
    } 
};

// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int A[2];
		int B[2];
		int C[2];
		cin >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1];
		Solution ob;
		vector<double> ans = ob.findPoint(A,B,C);
		printf("%0.6f %0.6f\n",ans[0],ans[1]);
	}
}
  // } Driver Code Ends