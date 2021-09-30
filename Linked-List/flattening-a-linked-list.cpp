// { Driver Code Starts
#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            } else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {
                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                } else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}


Node *flatten(Node *root) {
    Node *temp = root;
    Node *rt = temp->next;
    Node *bt = temp->bottom;
    while (temp->next && rt && bt) {
        while (bt->bottom) bt = bt->bottom;
        bt->bottom = rt;
        temp->next = rt->next;
        rt->next = NULL;
        rt = temp->next;
    }
    root = temp;
    while (temp->bottom) {
        Node *temp2 = temp->bottom;
        while (temp2) {
            if (temp->data > temp2->data) {
                int x = temp->data;
                temp->data = temp2->data;
                temp2->data = x;
            }
            temp2 = temp2->bottom;
        }
        temp = temp->bottom;
    }

    return root;
}
