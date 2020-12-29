// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t, k;

    scanf("%d", &t);
    while (t--) {
        Node *head = insert();   // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k);   // rotate linked list anti-clockwise  by k nodes
        printList(head);          // print linked list after rotation
    }
    return (0);
}
Node *rotate(Node *head, int k) {
    Node *last = head;
    while (last->next) last = last->next;
    last->next = head;
    Node *temp = head;
    while (--k)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}
