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

Node *pairWiseSwap(Node *head);

void insert(Node **head) {
    int n, i, value;
    Node *temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            *head = new Node(value);
            temp = *head;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

void printList(struct Node *temp) {
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    /* Start with the empty list */
    int t, k, n, value;

    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    scanf("%d", &t);

    Node *head = NULL;

    while (t--) {
        head = NULL;
        insert(&head);
        head = pairWiseSwap(head);
        printList(head);
    }
    return (0);
}
Node *pairWiseSwap(struct Node *head) {
    Node *ptr1 = head;
    Node *ptr2;
    Node *temp = NULL;

    while (ptr1 != NULL) {
        if (ptr1->next == NULL)
            break;
        ptr2 = ptr1->next;
        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        if (temp)
            temp->next = ptr2;
        else
            head = ptr2;
        temp = ptr1;

        ptr1 = ptr1->next;
    }
    return head;
}