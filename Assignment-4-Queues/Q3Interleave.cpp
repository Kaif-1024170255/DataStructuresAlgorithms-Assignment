#include <iostream>
#define MAX_SIZE 100
using namespace std;

class CustomStack {
private:
    int arr[MAX_SIZE];
    int topIndex;

public:
    CustomStack() {
        topIndex = -1;
    }
    void push(int val) {
        if (topIndex == MAX_SIZE - 1) {
            return;
        }
        arr[++topIndex] = val;
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        topIndex--;
    }
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return arr[topIndex];
    }
    bool isEmpty() {
        return topIndex == -1;
    }
};

class CustomQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CustomQueue() {
        front = -1;
        rear = -1;
    }
    void push(int val) {
        if (rear == MAX_SIZE - 1) {
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = val;
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    int front_val() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    bool isEmpty() {
        return front == -1;
    }
    int size() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
};

void interleaveQueue() {
    CustomQueue q;
    cout << "\n--- Interleave Queue ---" << endl;
    cout << "Enter queue elements (enter -1 to stop): ";
    int val;
    while (cin >> val && val != -1) {
        q.push(val);
    }
    
    if (q.isEmpty()) {
        cout << "Queue is empty. Nothing to interleave." << endl;
        return;
    }

    int n = q.size();
    if (n % 2 != 0) {
        cout << "Interleaving is not possible with an odd number of elements." << endl;
        return;
    }

    CustomStack s;
    int half_size = n / 2;
    
    // Push first half into a stack
    for (int i = 0; i < half_size; i++) {
        s.push(q.front_val());
        q.pop();
    }

    // Push elements from stack back to queue
    while (!s.isEmpty()) {
        q.push(s.top());
        s.pop();
    }
    
    // Dequeue first half and push to back
    for(int i = 0; i < half_size; i++){
        q.push(q.front_val());
        q.pop();
    }

    // Interleave
    for(int i = 0; i < half_size; i++){
        s.push(q.front_val());
        q.pop();
        q.push(q.front_val());
        q.pop();
        q.push(s.top());
        s.pop();
    }

    cout << "Interleaved queue: ";
    while (!q.isEmpty()) {
        cout << q.front_val() << " ";
        q.pop();
    }
    cout << endl;
}