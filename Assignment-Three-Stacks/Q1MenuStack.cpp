#include<iostream>
using namespace std;
class Stack{
    public:
    int* elements;
    int s;
    int top;
    Stack(int size){
        elements=new int[size];
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
    int pop(){
        if(isEmpty()){cout<<"Stack is Empty"<<endl;return -1;};
        int v=elements[top];
        top--;
        return v;
    }
    int peek(){
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
int main(){
    int ch,s;
    cout<<"Enter size : "<<endl;
    cin>>s;
    Stack st(s);
    while(ch!=-1){
        cout<<"Enter Choice : 1.push, 2.pop, 3.isEmpty, 4.isFull, 5.display, 6.peek, -1:BREAK"<<endl;
        cin>>ch;
        if(ch==-1) break;
        switch(ch){
            case 1:{
                int v;
                cout<<"Enter Element to Push : \n";
                cin>>v;
                st.push(v);
                break;
            }
            case 2:{
                int k=st.pop();
                cout<<"Element Popped : "<<k<<endl;
                break;
            }
            case 3:{
                cout<<"Is Stack Empty : "<<st.isEmpty()<<endl;
                break;
            }
            case 4:{
                cout<<"Is Stack Full : "<<st.isFull()<<endl;
                break;
            }
            case 5:{
                cout<<"DISPLAYING : "<<endl;
                st.display();
                break;
            }
            case 6:{
                int k=st.peek();
                cout<<"Element at Top : "<<k<<endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}