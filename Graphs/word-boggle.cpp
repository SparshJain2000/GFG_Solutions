// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfsRec(vector<vector<char>> &board, string word, vector<vector<bool>> &vis, int i, int j, int ind) {
        if (ind == word.size()) {
            return true;
        }

        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && vis[i][j] == false && board[i][j] == word[ind]) {
            vis[i][j] = true;

            if (
                dfsRec(board, word, vis, i - 1, j - 1, ind + 1) || dfsRec(board, word, vis, i - 1, j + 0, ind + 1) || dfsRec(board, word, vis, i - 1, j + 1, ind + 1) || dfsRec(board, word, vis, i + 0, j - 1, ind + 1) || dfsRec(board, word, vis, i + 0, j + 1, ind + 1) || dfsRec(board, word, vis, i + 1, j - 1, ind + 1) || dfsRec(board, word, vis, i + 1, j + 0, ind + 1) || dfsRec(board, word, vis, i + 1, j + 1, ind + 1)) {
                return true;
            }

            vis[i][j] = false;
        }

        return false;
    }

    bool findWords(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ind = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[ind]) {
                    if (dfsRec(board, word, vis, i, j, ind) == true) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

   public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary) {
        vector<string> res;

        for (auto x : dictionary) {
            if (findWords(board, x)) {
                res.push_back(x);
            }
        }

        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char>> board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends