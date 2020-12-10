// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int countTriplet(int arr[], int n)
    {
        // Your code goes here
        //using O(N) space
        /*
            int ans = 0;
            unordered_map<int, int> m;
            for (int i = 0; i < n - 1; i++)
                for (int j = i + 1; j < n; j++)
                    if (m[arr[i] + arr[j]])
                        ans++;
            return ans;
        */
        //Using O(1) space
        sort(arr, arr + n);
        int ans = 0;
        for (int k = n - 1; k >= 2; k--)
        {
            int l = 0, r = k - 1;
            while (l < r)
            {
                if (arr[l] + arr[r] == arr[k])
                    ans++;
                arr[l] + arr[r] < arr[k] ? l++ : r--;
            }
        }
        return ans;
    }
};
//1 2 3 4 5
// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";
    }

    return 0;
} // } Driver Code Ends