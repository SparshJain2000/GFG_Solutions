// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse(struct node *head, int k);

struct node {
    int data;
    struct node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    /* Start with the empty list */

    int t;
    cin >> t;

    while (t--) {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new node(value);
                temp = head;
            } else {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;
        head = reverse(head, k);

        printList(head);
    }

    return (0);
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
struct node *reverseList(struct node *head, int k) {
    struct node *pre = NULL, *ptr = head, *temp = head;
    while (k-- && ptr) {
        temp = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = temp;
    }
    head->next = ptr;
    head = pre;
    return head;
}

struct node *reverse(struct node *head, int k) {
    struct node *temp = head;
    struct node *t1, *t2 = NULL;
    while (temp) {
        t1 = temp;
        temp = reverseList(temp, k);
        t2 ? t2->next = temp : head = temp;
        temp = t1->next;
        t2 = t1;
    }
    return head;
}
/*
1
6
1 2 3 4 5 6
3
*/