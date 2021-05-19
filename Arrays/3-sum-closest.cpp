// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int N, int X)
    {
        // code here
        int ans=INT_MAX;
        sort(arr,arr+N);
        for(int i=0;i<N-2;i++){
            int j=i+1;
            int k=N-1;
            
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==X) return X;
                if(abs(sum-X)==abs(ans-X)) ans=max(ans,sum);
                if(abs(sum-X)<abs(ans-X)) ans=sum;
                if(sum<X) j++;
                else k--;
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends