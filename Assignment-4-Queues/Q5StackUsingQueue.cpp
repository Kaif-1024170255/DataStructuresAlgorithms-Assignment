#include <iostream>

using namespace std;

#define MAX_SIZE 100

// Custom Queue for integers
class IntQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;
public:
    IntQueue() {
        front = -1;
        rear = -1;
    }
    void push(int val) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue is full. Cannot push." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = val;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot pop." << endl;
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

void swapQueues(IntQueue& q1, IntQueue& q2) {
    IntQueue temp;
    
    // Move elements from q1 to temp
    while (!q1.isEmpty()) {
        temp.push(q1.front_val());
        q1.pop();
    }
    // Move elements from q2 to q1
    while (!q2.isEmpty()) {
        q1.push(q2.front_val());
        q2.pop();
    }
    // Move elements from temp to q2
    while (!temp.isEmpty()) {
        q2.push(temp.front_val());
        temp.pop();
    }
}

// Stack using two queues
class StackUsingTwoQueues {
private:
    IntQueue q1, q2;

public:
    void push(int val) {
        // Push the new element into q2
        q2.push(val);
        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.push(q1.front_val());
            q1.pop();
        }
        // Swap the names of q1 and q2
        swapQueues(q1, q2);
        cout << val << " pushed to stack." << endl;
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Popped element: " << q1.front_val() << endl;
        q1.pop();
    }

    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q1.front_val();
    }

    bool empty() {
        return q1.isEmpty();
    }
};

// Stack using one queue
class StackUsingOneQueue {
private:
    IntQueue q;

public:
    void push(int val) {
        int s = q.size();
        q.push(val);
        for (int i = 0; i < s; i++) {
            q.push(q.front_val());
            q.pop();
        }
        cout << val << " pushed to stack." << endl;
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Popped element: " << q.front_val() << endl;
        q.pop();
    }

    int top() {
        if (q.isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q.front_val();
    }

    bool empty() {
        return q.isEmpty();
    }
};

void stackUsingQueuesMenu() {
    int choice;
    cout << "\n--- Implement Stack using Queues ---" << endl;
    cout << "1. Using Two Queues" << endl;
    cout << "2. Using One Queue" << endl;
    cout << "3. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            StackUsingTwoQueues s2q;
            int sub_choice, val;
            do {
                cout << "\n--- Two Queues Stack ---" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Top" << endl;
                cout << "4. Back" << endl;
                cout << "Enter your choice: ";
                cin >> sub_choice;
                switch (sub_choice) {
                    case 1:
                        cout << "Enter value to push: ";
                        cin >> val;
                        s2q.push(val);
                        break;
                    case 2:
                        s2q.pop();
                        break;
                    case 3:
                        cout << "Top element: " << s2q.top() << endl;
                        break;
                }
            } while (sub_choice != 4);
            break;
        }
        case 2: {
            StackUsingOneQueue s1q;
            int sub_choice, val;
            do {
                cout << "\n--- One Queue Stack ---" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Top" << endl;
                cout << "4. Back" << endl;
                cout << "Enter your choice: ";
                cin >> sub_choice;
                switch (sub_choice) {
                    case 1:
                        cout << "Enter value to push: ";
                        cin >> val;
                        s1q.push(val);
                        break;
                    case 2:
                        s1q.pop();
                        break;
                    case 3:
                        cout << "Top element: " << s1q.top() << endl;
                        break;
                }
            } while (sub_choice != 4);
            break;
        }
        case 3:
            break;
        default:
            cout << "Invalid choice." << endl;
    }
}
int main() {
    stackUsingQueuesMenu();
    return 0;
}