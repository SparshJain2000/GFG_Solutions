// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if two strings are anagram
*   a, b: input string
*/
bool isAnagram(string a, string b){
    int m[26]={0};
    for(char c:a) m[c-'a']++;
    for(char c:b) m[c-'a']--;
    for(int i=0;i<26;i++) if(m[i]) return false;
    return true;
}

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}