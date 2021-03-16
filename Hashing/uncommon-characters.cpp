#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string UncommonChars(string A, string B) {
        // code here
        string ans = "";
        int arr1[26] = {0};
        int arr2[26] = {0};
        for (char c : A) arr1[c - 'a'] = 1;
        for (char c : B) arr2[c - 'a'] = 1;
        for (int i = 0; i < 26; i++)
            if (arr1[i] ^ arr2[i]) ans += (i + 'a');
        return ans == "" ? "-1" : ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
}