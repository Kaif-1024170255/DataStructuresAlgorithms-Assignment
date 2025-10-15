#include <iostream>
using namespace std;

class ListNode{
public:
    int coeff;
    int power;
    ListNode* next;
    ListNode(int c, int p){
        coeff = c;
        power = p;
        next = nullptr;
    }
};

class LinkedList{
public:
    ListNode* head;
    LinkedList(){
        head = nullptr;
    }
    void insertAtEnd(int c, int p){
        ListNode* ln = new ListNode(c, p);
        if(head == nullptr){
            head = ln;
            return;
        }
        ListNode* t = head;
        while(t->next != nullptr)
            t = t->next;
        t->next = ln;
    }
    void display(){
        ListNode* t = head;
        while(t){
            cout << t->coeff << "x^" << t->power;
            if(t->next) cout << " + ";
            t = t->next;
        }
        cout << endl;
    }
};

LinkedList addPolynomials(LinkedList& l1, LinkedList& l2){
    ListNode* a = l1.head;
    ListNode* b = l2.head;
    LinkedList result;

    while(a != nullptr && b != nullptr){
        if(a->power == b->power){
            result.insertAtEnd(a->coeff + b->coeff, a->power);
            a = a->next;
            b = b->next;
        } else if(a->power > b->power){
            result.insertAtEnd(a->coeff, a->power);
            a = a->next;
        } else {
            result.insertAtEnd(b->coeff, b->power);
            b = b->next;
        }
    }
    // Append remaining terms
    while(a != nullptr){
        result.insertAtEnd(a->coeff, a->power);
        a = a->next;
    }
    while(b != nullptr){
        result.insertAtEnd(b->coeff, b->power);
        b = b->next;
    }
    return result;
}
int main(){
    LinkedList poly1, poly2;

    poly1.insertAtEnd(5,3);
    poly1.insertAtEnd(4,2);
    poly1.insertAtEnd(2,0);

    poly2.insertAtEnd(3,3);
    poly2.insertAtEnd(1,1);
    poly2.insertAtEnd(6,0);

    LinkedList sum = addPolynomials(poly1, poly2);

    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();
    cout << "Sum: ";
    sum.display();

    return 0;
}
