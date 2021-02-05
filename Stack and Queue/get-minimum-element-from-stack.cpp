#include <bits/stdc++.h>
using namespace std;
class _stack {
    stack<int> s;
    int minEle;

   public:
    int getMin();
    int pop();
    void push(int);
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        _stack *a = new _stack();
        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                //push
                int att;
                cin >> att;
                a->push(att);
            } else if (qt == 2) {
                //pop
                cout << a->pop() << " ";
            } else if (qt == 3) {
                //getMin
                cout << a->getMin() << " ";
            }
        }
        cout << endl;
    }
}

int _stack ::getMin() {
    if (s.empty())
        return -1;
    else
        return minEle;
}
int _stack ::pop() {
    if (s.empty())
        return -1;

    int t = s.top();
    s.pop();
    if (t < minEle) {
        int k = minEle;
        minEle = 2 * minEle - t;
        return k;

    } else
        return t;
}
void _stack::push(int x) {
    if (s.empty()) {
        minEle = x;
        s.push(x);
        return;
    }
    if (x < minEle) {
        s.push(2 * x - minEle);
        minEle = x;
    } else
        s.push(x);
}
/*
- Push(x) : Inserts x at the top of stack.
If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
Pop() : Removes an element from top of stack.

- Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
*/