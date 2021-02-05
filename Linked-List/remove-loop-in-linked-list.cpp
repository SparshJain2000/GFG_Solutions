/*
1. This method is also dependent on Floyd’s Cycle detection algorithm.
2. Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
3. Count the number of nodes in loop. Let the count be k.
4. Fix one pointer to the head and another to a kth node from the head.
5. Move both pointers at the same pace, they will meet at loop starting node.
6. Get a pointer to the last node of the loop and make next of it as NULL.
*/

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

Node* insert(Node* head, int data) {
    if (head == NULL)
        head = new Node(data);
    else
        head->next = insert(head->next, data);
    return head;
}

void makeLoop(Node* head, int x) {
    if (x == 0)
        return;
    Node* curr = head;
    Node* last = head;

    int counter = 0;
    while (counter < x) {
        curr = curr->next;
        counter++;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}

int detectloop(Node* head) {
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL) {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;

        if (hare == tortoise)
            return 1;
    }

    if (hare == tortoise)
        return 1;
    return 0;
}

int length(Node* head, bool hasloop) {
    int len = 0;
    if (hasloop == false) {
        Node* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        return len;
    }

    else {
        Node* hare = head->next;
        Node* tortoise = head;
        while (hare != tortoise) {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;

            if (hare == tortoise)
                break;
        }

        int looplen = 0;
        while (hare->next != tortoise) {
            hare = hare->next;
            looplen++;
        }

        looplen++;

        Node* begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise) {
            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;
        }
        return looplen + startlen;
    }
}

void removeTheLoop(Node* head) {
    if (detectloop(head) == 0)   // If loop doesn't exist return
        return;
    Node* slow = head;
    Node* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    int k = 0;
    while (slow != fast->next) fast = fast->next, k++;
    Node* temp = head;
    while (k--) temp = temp->next;
    Node* temp2 = head;
    while (temp != temp2) temp = temp->next, temp2 = temp2->next;
    while (temp->next != temp2) temp = temp->next;
    temp->next = NULL;
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        Node* head = NULL;
        int sizeOfArray;
        cin >> sizeOfArray;
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++) {
            cin >> arr[i];
            head = insert(head, arr[i]);
        }

        int x;
        cin >> x;
        makeLoop(head, x);
        int lengthll = 0;
        if (detectloop(head) == 1)
            lengthll = length(head, true);
        else
            lengthll = length(head, false);

        removeTheLoop(head);

        if (detectloop(head) == 0 && lengthll == length(head, false)) {
            cout << 1 << endl;
        } else
            cout << 0 << endl;
    }
    return 0;
}   // } Driver Code Ends