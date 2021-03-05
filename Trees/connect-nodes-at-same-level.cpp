// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
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
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void connect(struct Node* p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

void printSpecial(Node* root) {
    if (root == NULL)
        return;

    Node* next_root = NULL;

    while (root != NULL) {
        cout << root->data << " ";

        if (root->left && (!next_root))
            next_root = root->left;
        else if (root->right && (!next_root))
            next_root = root->right;

        root = root->nextRight;
    }

    printSpecial(next_root);
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        connect(root);
        printSpecial(root);
        cout << endl;
        inorder(root);
        cout << endl;
    }
    return 0;
}
void connect(Node* p) {
    if (!p) return;
    queue<Node*> q;
    q.push(p);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node* temp = q.front();
            q.pop();
            temp->nextRight = n ? q.front() : NULL;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

/*
       10                       10 ------> NULL
      / \                      /  \
     3   5       =>         3 ------> 5 --------> NULL
    / \   \                /  \        \
   4   1   2              4 --> 1 -----> 2 -------> NULL
*/