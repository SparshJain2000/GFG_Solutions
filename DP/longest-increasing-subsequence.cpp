// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    // return length of longest strictly increasing subsequence

    int longestSubsequence(int n, int a[]) {
        vector<int> ans({a[0]});
        for (int i = 1; i < n; i++) {
            int ind = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            if (ind == ans.size())
                ans.push_back(a[i]);
            else
                ans[ind] = a[i];
        }
        return ans.size();

        /*
        vector<int>dp(n+1,1);
        vector<int>prev(a,a+n);
        sort(prev.begin(),prev.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[a[i]]=i;
        for(int i=1;i<n;i++){
            int m=INT_MIN;
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    m=max(m,dp[j]);
                    break;
                }
            }
            dp[i]=(m==INT_MIN)?1:m+1;
        }
        cout<<endl;
        for(int i:dp) cout<<i<<" ";
        return *max_element(dp.begin(),dp.end());
        */
    }
};

// { Driver Code Starts.
int main() {
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--) {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends