#include <bits/stdc++.h>
using namespace std;

bool ispar(string x) {
    stack<char> s;
    for (char c : x) {
        if (c == '{' || c == '[' || c == '(')
            s.push(c);
        else if (c == '}' && !(s.size() > 0 && s.top() == '{'))
            return false;
        else if (c == ']' && !(s.size() > 0 && s.top() == '['))
            return false;
        else if (c == ')' && !(s.size() > 0 && s.top() == '('))
            return false;
        else
            s.pop();
    }
    return s.size() == 0;
}
int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        if (ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}