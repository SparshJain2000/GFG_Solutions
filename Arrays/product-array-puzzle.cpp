// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
   public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> temp(n);
        if (n == 1) return vector<long long int>({1});
        temp[0] = nums[0];

        for (int i = 1; i < n; i++) temp[i] = temp[i - 1] * nums[i];
        // for(int i=0;i<n;i++) cout<<temp[i]<<" ";
        // cout<<endl;

        vector<long long int> temp2(n);
        temp2[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) temp2[i] = temp2[i + 1] * nums[i];
        // for(int i=0;i<n;i++) cout<<temp2[i]<<" ";
        // cout<<endl;
        nums[0] = temp2[1];
        nums[n - 1] = temp[n - 2];
        for (int i = 1; i < n - 1; i++) nums[i] = temp[i - 1] * temp2[i + 1];
        return nums;
    }
};

// { Driver Code Starts.
int main() {
    int t;   // number of test cases
    cin >> t;
    while (t--) {
        int n;   // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++)   // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n);   // function call

        for (int i = 0; i < n; i++)   // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}   // } Driver Code Ends