#include<string>
#include<string.h>
#include<iostream>
using namespace std;
class Stack{
    public:
    char* elements;
    int s;
    int top;
    Stack(int size){
        elements=new char[size];
        s=size;
        top=-1;
    }
    bool isEmpty(){
        return (top==-1)?(true):(false);
    }
    bool isFull(){
        return (top==s-1)?(true):(false);
    }
    void push(int v){
        if(isFull()){cout<<"Stack is Full"<<endl;return;};
        elements[++top]=v;
    }
    char pop(){
        if(isEmpty()){cout<<"Stack is Empty"<<endl;return -1;};
        int v=elements[top];
        top--;
        return v;
    }
    char peek(){
        if(isEmpty()){cout<<"Stack is Empty"<<endl;return -1;};
        return elements[top];
    }
    void display(){
        if(isEmpty()){cout<<"Stack is Empty"<<endl;return;};
        cout<<"Elements from Top :\n";
        for(int i=top;i>=0;i--)
            cout<<elements[i]<<endl;
    }
};
int precedence(char op) {
    if (op=='^') return 3;
    if (op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return -1;
}
bool isRightAssociative(char op) {
    return (op=='^');
}
string infixToPostfix(string infix) {
    Stack st(infix.length());
    string postfix="";

    for(char ch:infix) {
        if(isalnum(ch)) postfix+=ch;
        else if(ch=='(') st.push(ch);
        else if(ch==')'){
            while(!st.isEmpty() && st.peek()!='('){
                postfix+=st.peek();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isEmpty() && precedence(st.peek())>precedence(ch)) {
                postfix+=st.peek();
                st.pop();
            }
            while(!st.isEmpty() && precedence(st.peek())==precedence(ch) && !isRightAssociative(ch)) {
                postfix+=st.peek();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.isEmpty()){
        postfix+=st.peek();
        st.pop();
    }
    return postfix;
}
int main(){
    string inf;
    cout<<"Enter Expression : "<<endl;
    getline(cin,inf); 
    string post=infixToPostfix(inf);
    cout<<"Postfix Expression : "<<post<<endl;
    return 0;
}