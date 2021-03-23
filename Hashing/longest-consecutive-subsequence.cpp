// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
*/
class Solution {
   public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        //Your code here
        unordered_map<int, int> m;
        int max_ele = INT_MIN;
        int min_ele = INT_MAX;
        for (int i = 0; i < N; i++) m[arr[i]]++, max_ele = max(max_ele, arr[i]), min_ele = min(min_ele, arr[i]);
        int ans = 0;
        int i = min_ele;
        while (i < max_ele) {
            int j = 0;
            while (i++ <= max_ele && m[i] && m[i - 1]) j++;
            ans = max(ans, j);
        }
        return ans + 1;
    }
};
int main() {
    int t, n, i, a[100001];
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}   // } Driver Code Ends