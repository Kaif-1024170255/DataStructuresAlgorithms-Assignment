#include <iostream>
#include <string>
#define MAX_SIZE 100
using namespace std;

class CharQueue {
private:
    char arr[MAX_SIZE];
    int front, rear;
public:
    CharQueue() {
        front = -1;
        rear = -1;
    }
    void push(char val) {
        if (rear == MAX_SIZE - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = val;
    }
    void pop() {
        if (isEmpty()) return;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    char front_val() {
        if (isEmpty()) return ' ';
        return arr[front];
    }
    bool isEmpty() {
        return front == -1;
    }
};

void firstNonRepeatingChar() {
    string str;
    cout << "\n--- First Non-Repeating Character ---" << endl;
    cout << "Enter a string (no spaces): ";
    cin >> str;

    int count[256] = {0};
    CharQueue q;

    cout << "Output: ";
    for (char ch : str) {
        count[ch]++;
        if (count[ch] == 1) {
            q.push(ch);
        }

        while (!q.isEmpty() && count[q.front_val()] > 1) {
            q.pop();
        }

        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.front_val() << " ";
        }
    }
    cout << endl;
}