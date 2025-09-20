#include<iostream>
#include<string>
#include<string.h>
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
bool checkBalancedExpression(string str){
    Stack st(str.length());
    for(int i=0;i<str.length();i++){
        if(str.at(i)=='(' || str.at(i)=='[' || str.at(i)=='{')
            st.push(str.at(i));
        else if((str.at(i)==')' && st.peek()=='(') || (str.at(i)==']' && st.peek()=='[') || (str.at(i)=='}' && st.peek()=='{'))
            st.pop();
    }
    if(st.isEmpty()) return true;
}
int main(){
    string str;
    cout<<"Enter Expression : "<<endl;
    getline(cin,str); 
    (checkBalancedExpression(str))?(cout<<"BALANCED\n"):(cout<<"NOT BALANCED\n");
    return 0;
}