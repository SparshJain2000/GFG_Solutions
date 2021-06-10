// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        if (startWord == targetWord) return 0;
        int start = -1, target = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == startWord) start = i;
            if (wordList[i] == targetWord) target = i;
        }
        if (target == -1) return 0;
        if (start == -1) {
            wordList.push_back(startWord);
            start = wordList.size() - 1;
        }

        int n = wordList.size();
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                for (int k = 0; k < wordList[i].length(); k++) {
                    if (wordList[i][k] != wordList[j][k]) count++;
                    if (count > 1) break;
                }
                if (count == 1) mat[i][j] = 1, mat[j][i] = 1;
            }
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        int ans = 0;
        while (!q.empty()) {
            int z = q.size();
            ans++;
            while (z--) {
                int x = q.front();
                q.pop();
                vis[x] = true;
                if (x == target) return ans;
                for (int j = 0; j < n; j++)
                    if (!vis[j] && mat[x][j] == 1) q.push(j);
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++) cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}   // } Driver Code Ends