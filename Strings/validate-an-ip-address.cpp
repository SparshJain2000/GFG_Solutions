// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int isValid(string s) {
        // code here
        string temp = "";
        int dots = 0;
        for (char c : s) {
            if (dots > 3) return false;
            if (c == '.') {
                dots++;
                try {
                    if (temp != "0" && temp[0] == '0') return 0;
                    if (temp.length() > 3 || temp == "") return 0;
                    int add = stoi(temp);
                    if (add > 255 || add < 0) return 0;
                    temp = "";
                } catch (...) {
                    return 0;
                }
            } else
                temp += c;
        }
        if (dots < 3) return false;
        try {
            if (temp != "0" && temp[0] == '0') return 0;
            if (temp.length() > 3 || temp == "") return 0;
            int add = stoi(temp);
            if (add > 255 || add < 0) return 0;
            temp = "";
        } catch (...) {
            return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}   // } Driver Code Ends