// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
   public:
    int catchThieves(char arr[], int n, int k) {   //Using O(N) space and O(N) time
        vector<int> T;
        for (int i = 0; i < n; i++)
            if (arr[i] == 'T')
                T.push_back(i);

        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j >= T.size()) break;
            if (arr[i] == 'P') {
                if (abs(T[j] - i) <= k)
                    ans++, j++;
                else if (T[j] + k < i)
                    j++, i--;
            }
        }
        return ans;
        //Using O(N^2) time and O(1) space
        /*
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='P'){
                for(int j=i-k;j<=i+k;j++){
                    if(j>=0 && j<n){
                        if(arr[j]=='T') {
                            ans++;
                            arr[j]='-';
                            break;
                        }
                    }
                }
                arr[i]='-';
            }
        }
        return ans;
        */
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        char arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.catchThieves(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends