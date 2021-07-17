// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <stack>
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

void append(struct Node **head_ref, struct Node **tail_ref, int new_data) {
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main() {
    int T, i, n, l;
    cin >> T;
    while (T--) {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        cout << isPalindrome(head) << endl;
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
};
*/
/*You are required to complete this method */
#include <stack>
Node *reverse(Node *head) {
    Node *ptr = head;
    Node *pre = NULL;
    while (ptr) {
        Node *temp = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = temp;
    }
    return pre;
}
bool isPalindrome(Node *head) {
    Node *temp = head;
    stack<int> s;
    while (temp) s.push(temp->data), temp = temp->next;
    temp = head;
    while (!s.empty() && temp) {
        if (s.top() != temp->data) return false;
        s.pop();
        temp = temp->next;
    }
    return true;

    //O(N) time O(1) space
    if (!head || !head->next) return true;

    Node *slow = head;
    Node *fast = head;
    Node *pre = NULL;
    int n = 0;
    while (slow && fast && fast->next) n++, pre = slow, slow = slow->next, fast = fast->next->next;

    pre->next = NULL;
    slow = reverse(slow);

    while (slow && head) {
        if (slow->data != head->data) return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}
