// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        long long int ans=0;
        priority_queue<long long int, vector<long long int>, greater<long long int> >q;
        for(int i=0;i<n;i++) q.push(arr[i]);
        while(q.size()!=1){
            long long int x=q.top();
            q.pop();
            long long int y=q.top();
            q.pop();
            q.push(x+y);
            ans+=x+y;
        }
        return ans;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends