// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"

class Solution {
    bool isTrue(int a1[], int a2[]) {
        for (int i = 0; i < 26; i++)
            a2[i] -= a1[i];
        for (int i = 0; i < 26; i++)
            if (a2[i] > 0) return false;
        return true;
    }

   public:
    string smallestWindow(string str, string pat) {
        int len1 = str.length();
        int len2 = pat.length();
        if (len1 < len2)
            return "-1";

        int hash_pat[256] = {0};
        int hash_str[256] = {0};

        for (int i = 0; i < len2; i++)
            hash_pat[pat[i]]++;

        int k = 0, start_index = -1, min_len = INT_MAX;

        int count = 0;
        for (int j = 0; j < len1; j++) {
            hash_str[str[j]]++;
            if (hash_str[str[j]] <= hash_pat[str[j]])
                count++;

            if (count == len2) {
                while (hash_str[str[k]] > hash_pat[str[k]] || hash_pat[str[k]] == 0) {
                    if (hash_str[str[k]] > hash_pat[str[k]])
                        hash_str[str[k]]--;
                    k++;
                }
                int len_window = j - k + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = k;
                }
            }
        }
        if (start_index == -1)
            return "-1";

        return str.substr(start_index, min_len);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}   // } Driver Code Ends