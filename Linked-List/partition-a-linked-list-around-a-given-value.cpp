// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends

// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    Node* h1 = NULL;
    Node* h2 = NULL;
    Node* h3 = NULL;
    Node* l1 = NULL;
    Node* l2 = NULL;
    Node* l3 = NULL;
    Node* temp = head;
    while (temp) {
        if (temp->data < x) {
            if (!l1)
                h1 = new Node(temp->data), l1 = h1;
            else
                l1->next = new Node(temp->data), l1 = l1->next;

        } else if (temp->data == x) {
            if (!l2)
                h2 = new Node(temp->data), l2 = h2;
            else
                l2->next = new Node(temp->data), l2 = l2->next;
        } else {
            if (!l3)
                h3 = new Node(temp->data), l3 = h3;
            else
                l3->next = new Node(temp->data), l3 = l3->next;
        }
        temp = temp->next;
    }
    if (h2) l2->next = h3;
    if (h1) l1->next = h2 ? h2 : h3;
    return h1 ? h1 : (h2 ? h2 : h3);
}