#include <bits/stdc++.h>
using namespace std;
/*
    create array "ans"
    push into stack last element of arr
    iterate from back of arr
    if arr[i] is less than st.top, st.top is the next greater element(ans[i]=st.top) and push arr[i] into stack
    else pop the top element while st is not empty && arr[i] is greater than st.top
        - if st is empty now push arr[i] into the stack
        - else st.top is the next greater element (ans[i]=st.top) and push arr[i] into stack

*/
vector<long long> nextLargerElement(vector<long long> arr, int n) {
    stack<long long> s;
    s.push(arr[n - 1]);
    vector<long long> ans(n, -1);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < s.top()) {
            ans[i] = s.top();
            s.push(arr[i]);
        } else {
            while (!s.empty() && arr[i] > s.top()) s.pop();
            if (s.empty())
                s.push(arr[i]);
            else
                ans[i] = s.top(), s.push(arr[i]);
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
