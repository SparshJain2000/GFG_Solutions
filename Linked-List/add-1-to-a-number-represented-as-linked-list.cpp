// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    Node* util(Node* head, int& carry) {
        if (!head) return head;
        head->next = util(head->next, carry);
        head->data += (head->next == NULL) ? 1 : carry;
        carry = head->data / 10;
        head->data %= 10;
        return head;
    }

   public:
    Node* addOne(Node* head) {
        int carry = 0;
        head = util(head, carry);
        if (carry == 1) {
            Node* temp = head;
            head = new Node(1);
            head->next = temp;
        }
        return head;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Node* head = new Node(s[0] - '0');
        Node* tail = head;
        for (int i = 1; i < s.size(); i++) {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends