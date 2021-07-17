#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}
// } Driver Code Ends
/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node* reverseUtil(Node* pre, Node* head) {
    if (!head) return pre;
    Node* next = head->next;
    head->next = pre;
    return reverseUtil(head, next);
}
Node* addTwoLists(Node* first, Node* second) {
       int carry = 0;
    Node* head = NULL;
    Node* ptr = head;
    while (first && second) {
        int sum = first->data + second->data + carry;
        carry = sum / 10;
        if (!head)
            head = new Node(sum % 10), ptr = head;
        else
            ptr->next = new Node(sum % 10), ptr = ptr->next;
        first = first->next;
        second = second->next;
    }
    while (first) {
        int sum = first->data + carry;
        carry = sum / 10;
        if (!head)
            head = new Node(sum % 10), ptr = head;
        else
            ptr->next = new Node(sum % 10), ptr = ptr->next;
        first = first->next;
    }
    while (second) {
        int sum = second->data + carry;
        carry = sum / 10;
        if (!head)
            head = new Node(sum % 10), ptr = head;
        else
            ptr->next = new Node(sum % 10), ptr = ptr->next;
        second = second->next;
    }
    if (carry) ptr->next = new Node(carry);
    return reverseUtil(NULL, head);
}