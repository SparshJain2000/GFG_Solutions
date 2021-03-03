// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
int maxPathSum(Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}

//Given a binary tree in which each node element contains a number.Find the maximum possible sum from one leaf node to another.
int util(Node *root, int &res) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    int l = util(root->left, res);
    int r = util(root->right, res);
    if (root->left && root->right) {
        res = max(res, l + r + root->data);
        return max(l, r) + root->data;
    }
    return (!root->left) ? r + root->data : l + root->data;
}
int maxPathSum(Node *root) {
    // code here
    int res = INT_MIN;
    util(root, res);
    return res;
}