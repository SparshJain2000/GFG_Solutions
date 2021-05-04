// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int ans=0;
    sort(arr,arr+n);
    int k=ceil(n/2);
    int t=0;
    for(int i=0;i<k;i++){
        ans+=abs(arr[n-1-t]-arr[i]);
        ans+=abs(arr[n-1-t]-arr[(i+1)%k]);
        t++;
    }
    return ans;
}