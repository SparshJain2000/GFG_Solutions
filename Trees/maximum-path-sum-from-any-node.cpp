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

// Function to Build Tree
Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User Fuction template for C++

class Solution {
   public:
    int util(Node *root, int &ans) {
        if (!root) return INT_MIN;
        int l = util(root->left, ans);
        int r = util(root->right, ans);
        ans = max(ans, root->data);
        if (l != INT_MIN && r != INT_MIN)
            ans = max({ans, l + r + root->data, max(l, r) + root->data});
        else if (l != INT_MIN)
            ans = max(ans, l + root->data);
        else if (r != INT_MIN)
            ans = max(ans, r + root->data);
        return max(l, r) == INT_MIN ? root->data : max(root->data, max(l, r) + root->data);
    }
    int findMaxSum(Node *root) {
        // Your code goes here
        int ans = INT_MIN;
        util(root, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";
    }

    return 0;
}   // } Driver Code Ends