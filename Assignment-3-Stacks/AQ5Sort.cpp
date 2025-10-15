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
            return -1;
        }
        return elements[top--];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return elements[top];
    }
};
bool canBeSorted(int A[], int N) {
    Stack S(N);
    int nextExpected = 1;  
    for (int i = 0; i < N; i++) {
        S.push(A[i]);
        while (!S.isEmpty() && S.peek() == nextExpected) {
            S.pop();
            nextExpected++;
        }
    }
    return S.isEmpty();
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int* A = new int[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        if (canBeSorted(A, N))
            cout << "YES\n";
        else
            cout << "NO\n";

        delete[] A;
    }

    return 0;
}
