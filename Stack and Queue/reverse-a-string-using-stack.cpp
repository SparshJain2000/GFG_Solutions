#include <bits/stdc++.h>
using namespace std;
char *reverse(char *str, int len);
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        cout << ch;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//return the address of the string
char *reverse(char *S, int len) {
    //code here
    char *s = new char;
    s = S;
    stack<char> st;
    for (int i = 0; i < len; i++) st.push(S[i]);
    int i = -1;
    while (!st.empty()) {
        s[++i] = st.top();
        st.pop();
    }
    return s;
}