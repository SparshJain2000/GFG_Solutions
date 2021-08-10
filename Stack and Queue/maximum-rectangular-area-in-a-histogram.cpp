// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long hist[], int n) {
        stack<int> s;

        long long int max_area = 0;
        long long int tp;
        long long int area_with_top;

        // Run through all bars of given histogram
        int i = 0;
        while (i < n) {
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);

            else {
                tp = s.top();   // store the top index
                s.pop();        // pop the top

                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

                // update max area, if needed
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }

        while (s.empty() == false) {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
    }
};
/*
Algorithm:

1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘arr[i]’ where ‘i’ varies from 0 to n-1.
      a) If stack is empty or arr[i] is higher than the bar at top of stack, then push ‘i’ to stack.
      b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be arr[tp]. Calculate area of rectangle with arr[tp] as smallest bar. For arr[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
*/

// { Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends