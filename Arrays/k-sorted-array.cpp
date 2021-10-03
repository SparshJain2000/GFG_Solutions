// Given an array of n distinct elements. 
// Check whether the given array is a k sorted array or not. 
// A k sorted array is an array where each element is at most 
// k distance away from its target position in the sorted array.
// { Driver Code Starts

// 6
// 3 2 1 5 6 4 
// 2

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
string isKSortedArray(int arr[], int n, int k)
{
    // 1st method not optimized
    // int a[n];
    // for(int i=0; i<n; i++)
    // {
    //     a[i]= arr[i];
    // }
    // sort(a,a+n);
    // for(int i=0; i<n; i++)
    // {
    //    for(int j=0; j<n;j++)
    //     {
    //         if(arr[i]==a[j])
    //             {
    //                if(k<(abs(i-j))) 
    //                {
    //                    return "No";
    //                    break;
    //                }
    //                break;
    //             }
    //     }
    // }
    // return "yes";

    //2nd using map
  
    map<int,int> mp;
    for (size_t i = 0; i < n; i++) mp[arr[i]] = i;
    int i = 0;
    for(auto p: mp)
        {
        if(abs(p.second - i++)>k)
        return "No";
        }
    
   return "Yes";
}
};

// { Driver Code Starts.
int main()
{
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>k;
    Solution ob;
cout <<ob.isKSortedArray(arr, n, k)<<endl;
}
return 0;	 
}  // } Driver Code Ends    
