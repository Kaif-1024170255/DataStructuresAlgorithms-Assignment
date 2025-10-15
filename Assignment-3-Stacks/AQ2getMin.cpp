#include<iostream>
using namespace std;

class Stack {
public:
    int* elements;
    int s;
    int top;

    Stack(int size) {
        elements = new int[size];
        s = size;
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == s - 1);
    }

    void push(int v) {
        if (isFull()) {
            cout << "Stack is Full" << endl;
            return;
        }
        elements[++top] = v;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return elements[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return elements[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Elements from Top:\n";
        for (int i = top; i >= 0; i--)
            cout << elements[i] << endl;
    }
};

// ---------------------- SpecialStack ----------------------
class SpecialStack : public Stack {
    int* minStack;
    int minTop;
    public:
    SpecialStack(int size) : Stack(size) {
        minStack = new int[size];
        minTop = -1;
    }
    void push(int v) {
        if (isFull()) {
            cout << "Stack is Full" << endl;
            return;
        }
        // Push to main stack
        Stack::push(v);
        // Update minStack
        if (minTop == -1 || v <= minStack[minTop])
            minStack[++minTop] = v;
        else
            minStack[++minTop] = minStack[minTop - 1];
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        minTop--;
        return Stack::pop();
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return minStack[minTop];
    }
};
// ---------------------- Main ----------------------
int main() {
    SpecialStack s(10);
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    cout << "Minimum: " << s.getMin() << endl; // 1
    s.pop();
    cout << "Minimum: " << s.getMin() << endl; // 2

    s.push(0);
    cout << "Minimum: " << s.getMin() << endl; // 0

    return 0;
}
