// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
class Solution {
    Node* merge(Node* temp1, Node* temp2) {
        if (!temp1) return temp2;
        if (!temp2) return temp1;
        if (temp1->data >= temp2->data) {
            temp2->next = merge(temp2->next, temp1);
            return temp2;
        } else {
            temp1->next = merge(temp1->next, temp2);
            return temp1;
        }
        return NULL;
    }

   public:
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next && fast->next->next) slow = slow->next, fast = fast->next->next;
        Node* head2 = slow->next;
        slow->next = NULL;
        head = mergeSort(head);
        head2 = mergeSort(head2);
        head = merge(head, head2);
        return head;
    }
};
//1 2 3 4 5
//1 1 1
//1   1   1
// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}   // } Driver Code Ends