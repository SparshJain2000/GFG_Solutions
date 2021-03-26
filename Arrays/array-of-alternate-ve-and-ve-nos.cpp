// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
   public:
    void rearrange(int arr[], int n) {
        // code here
        // int p = 0, neg = 1;
        // for (int i = 0; i < n; i++) {
        //     // cout << arr[i] << " ";
        //     int j = i;
        //     if (i & 1 && arr[i] >= 0)
        //         for (; j < n; j++) {
        //             if (arr[j] < 0 && !(j & 1)) break;
        //         }
        //     else if (!(i & 1) && arr[i] < 0)
        //         for (; j < n; j++) {
        //             if (arr[j] >= 0 && (j & 1)) break;
        //         }
        //     // while (j < n && (i & 1) && arr[j] < 0)
        //     //     j++;

        //     if (j > i && j < n) {
        //         int temp = arr[j];
        //         // cout << "==" << i << " " << arr[i] << " " << j << " " << temp << endl;
        //         while (j > i) arr[j--] = arr[j - 1];
        //         arr[i] = temp;
        //     }
        // }
        // vector<int> p;
        // vector<int> neg;
        // for (int i = 0; i < n; i++)
        //     if (arr[i] >= 0)
        //         p.push_back(arr[i]);
        //     else
        //         neg.push_back(arr[i]);
        // int l = 0, r = 0;
        // for (int i = 0; i < n; i++) {
        //     if (i & 1)
        //         arr[i] = l < neg.size() ? neg[l++] : p[r++];
        //     else
        //         arr[i] = r < p.size() ? p[r++] : neg[l++];
        // }
        int i = -1;
        for (int j = 0; j < n; j++)
            if (arr[j] >= 0) swap(arr[j], arr[++i]);
        int neg = i + 1, p = 1;
        while (neg < n && p < neg && arr[p] >= 0) {
            swap(arr[p], arr[neg]);
            neg++;
            p += 2;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends