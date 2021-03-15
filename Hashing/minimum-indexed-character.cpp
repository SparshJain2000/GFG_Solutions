// { Driver Code Starts
// C++ implementation to find the character in first
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
int minIndexChar(string str, string patt) {
    int arr[26] = {0};
    for (char c : patt) arr[c - 'a']++;
    for (int i = 0; i < str.length(); i++)
        if (arr[str[i] - 'a']) return i;
    return -1;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        string patt;
        cin >> str;
        cin >> patt;
        int ans = minIndexChar(str, patt);
        if (ans == -1)
            cout << "No character present";
        else
            cout << str[ans];
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends