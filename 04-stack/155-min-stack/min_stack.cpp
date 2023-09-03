#include <iostream>

using namespace std;

class MinStack {
public:
    typedef struct node{
        int value;
        int min;
        node* next;
    }node;

    node *head;

    MinStack() : head(nullptr){}

    ~MinStack() {
        while(head) {
            pop();
        }
    }

    void push(int val) {
        node *n = new node();
        n->value = val;
        n->min = val;
        
        if(head)
            n->next = head;
        else
            n->next = nullptr;
        head = n;

        if(n->next && n->next->min < n->value)
            n->min = n->next->min;
    }

    void pop() {
        node* next = head->next;
        delete(head);
        head = next;
    }

    int top() {
        return head->value;
    }

    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main() {
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    int min = obj->getMin();
    cout << "min = " << min << endl;
    
    //int top = obj->top();
    //cout << "top = " << top << endl;
    obj->pop();

    int top = obj->top();
    cout << "top = " << top << endl;

    min = obj->getMin();
    cout << "min = " << min << endl;
    delete(obj);
 }
