// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> verticalOrder(Node* root);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Node* root = buildTree(s);

        vector<int> res = verticalOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

vector<int> verticalOrder(Node* root) {
    map<int, queue<int>> m;
    queue<pair<Node*, int>> q;
    q.push(pair<Node*, int>(root, 0));
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node* temp = q.front().first;
            int ht = q.front().second;
            m[ht].push(temp->data);
            q.pop();
            if (temp->left) q.push(pair<Node*, int>(temp->left, ht - 1));
            if (temp->right) q.push(pair<Node*, int>(temp->right, ht + 1));
        }
    }
    vector<int> ans;
    for (auto p : m)
        while (!p.second.empty()) {
            ans.push_back(p.second.front());
            p.second.pop();
        }
    return ans;
}
