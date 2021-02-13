/* O(k) space & O(N) time
- Create a deque to store k elements.
- Run a loop and insert first k elements in the deque.  if the element at the back of queue is < the current element ,  remove the element from the back of deque, until all elements left in the deque are > the current element. Then insert the current element, at the back of  deque.
- Now, run a loop from k to end of the array.
    - Print the front element of the deque.
    - Remove the element from the front of the queue if they are out of the current window.
    - Insert the next element in the deque.   if the element at the back of queue is < the current element ,  remove the element from the back of deque, until all elements left in the deque are > the current element. Then insert the current element, at the back of  deque.
- Print the maximum element of the last window.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i);
    }
    for (int i = k; i < n; i++) {
        ans.push_back(arr[q.front()]);
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        while (!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    return ans;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> res = max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}