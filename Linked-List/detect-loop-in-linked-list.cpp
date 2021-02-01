#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);
/* Driver program to test above function*/
int main() {
    int t, n, c, x, i;
    cin >> t;
    while (t--) {
        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++) {
            cin >> x;
            push(&head, x);
        }
        cin >> c;
        if (c > 0) {
            c = c - 1;
            temp = head;
            while (c--) temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
int detectloop(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return 1;
    }
    return 0;
}
