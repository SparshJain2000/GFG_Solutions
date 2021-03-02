// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
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
bool isSymmetric(struct Node* root);

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        if (isSymmetric(root))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}

// return true/false denoting whether the tree is Symmetric or not
bool palindrome(vector<Node*> v) {
    int n = v.size();
    for (int i = 0; i < n; i++)
        if ((v[i] ? v[i]->data : NULL) != (v[n - i - 1] ? v[n - i - 1]->data : NULL)) return false;
    return true;
}
bool isSymmetric(struct Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        vector<Node*> v;
        while (n--) {
            Node* node = q.front();
            q.pop();
            v.push_back(node);
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (!palindrome(v)) return false;
    }
    return true;
}