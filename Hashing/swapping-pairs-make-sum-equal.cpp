#include <bits/stdc++.h>
using namespace std;
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    sort(A,A+n);
	    sort(B,B+m);
	    int sum1=accumulate(A,A+n,0);
	    int sum2=accumulate(B,B+m,0);
	    int i=0,j=0;
	    int pre=INT_MIN;
	    while(i<n && j<m){
	        int s1=sum1-A[i]+B[j];
	        int s2=sum2+A[i]-B[j];
	        if(s1==s2) return 1;
	        if(s1-s2 > pre) j++,pre=s1-s2;
	        else j=0,pre=INT_MIN,i++;
	    }
	    return -1;
	    
	}
};
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        
        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}