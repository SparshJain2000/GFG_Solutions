// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node *reverse(Node *head) {
    Node *temp = NULL;
    Node *ptr = head;
    Node *tempn = head;
    while (ptr != NULL) {
        tempn = ptr->next;
        ptr->next = temp;
        temp = ptr;
        ptr = tempn;
    }
    head = temp;
    return head;
}
class Solution {
   public:
    Node *compute(Node *head) {
        // your code goes here
        // Node *curr = head;
        // Node *prev = NULL;
        // while (curr && curr->next) {
        //     // cout << head->data << " ";
        //     while (curr->next && curr->data < curr->next->data) {
        //         if (prev) {
        //             prev->next = curr->next;
        //             curr = prev;
        //             prev=NULL;
        //         } else {
        //             head = curr->next;
        //             curr = head;
        //             prev = NULL;
        //         }
        //     }
        //     prev = curr;
        //     curr = curr->next;
        // }
        // // cout << "_" << head->data << endl;
        // return head;
        head = reverse(head);
        Node *temp = head;

        while (temp && temp->next) {
            Node *pre = temp;
            int val = temp->data;
            temp = temp->next;
            while (temp && temp->data < val) {
                val = max(val, temp->data);
                temp = temp->next;
            }
            pre->next = temp;
        }
        head = reverse(head);
        return head;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}
// } Driver Code Ends