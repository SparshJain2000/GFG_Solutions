// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
   public:
    bool same(vector<int> freq) {
        int j = 0;
        for (int i : freq)
            if (i) j = i;
        for (int i : freq)
            if (i && i != j) return false;
        return true;
    }
    bool sameFreq(string s) {
        vector<int> freq(26, 0);
        for (char i : s) freq[i - 'a']++;
        if (same(freq)) return true;

        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                freq[i]--;
                if (same(freq)) return true;
                freq[i]++;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.sameFreq(s) << endl;
    }
}

// } Driver Code Ends