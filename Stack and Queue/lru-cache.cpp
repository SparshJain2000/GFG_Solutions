#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    int value;
    Node* next;
    Node* pre;
    Node(int k, int v) {
        key = k;
        value = v;
        pre = NULL;
        next = NULL;
    }
};
class LRUCache {
   private:
    static int capacity, count;
    static Node *head, *tail;
    static unordered_map<int, Node*> m;

   public:
    LRUCache(int cap) {
        unordered_map<int, Node*> temp;
        m = temp;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        capacity = cap;
        head->next = tail;
        tail->pre = head;
        count = 0;
    }
    static void insert(Node* n) {
        n->next = head->next;
        n->next->pre = n;
        head->next = n;
        n->pre = head;
    }
    static void del(Node* n) {
        n->pre->next = n->next;
        n->next->pre = n->pre;
    }
    static int get(int key) {
        if (m.count(key) > 0) {
            Node* node = m[key];
            del(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    static void set(int key, int value) {
        if (m.count(key) > 0) {
            Node* node = new Node(key, value);
            insert(node);
            del(m[key]);
            m[key] = node;
        } else {
            if (count < capacity) {
                Node* node = new Node(key, value);
                m[key] = node;
                insert(node);
                count++;
            } else {
                Node* node = new Node(key, value);
                m[key] = node;
                m.erase(tail->pre->key);
                del(tail->pre);
                insert(node);
            }
        }
    }
};
unordered_map<int, Node*> temp;
Node* LRUCache::head = new Node(0, 0);
Node* LRUCache::tail = new Node(0, 0);
int LRUCache::capacity = 0;
int LRUCache::count = 0;
unordered_map<int, Node*> LRUCache::m = temp;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int capacity;
        cin >> capacity;
        LRUCache* cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}