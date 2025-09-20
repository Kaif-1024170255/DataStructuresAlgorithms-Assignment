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
int* nextLeftSmallest(int* A,int size){
    int* ans=new int[size];    
    Stack st(size);
    for (int i = 0; i < size; i++) {
        // Pop elements that are >= current element
        while (!st.isEmpty() && st.peek() >= A[i]) 
            st.pop();
        if (!st.isEmpty())  ans[i] = st.peek();  // nearest smaller element
        else                ans[i] = -1;
        st.push(A[i]);
    }
    return ans;
}
int* nextRightGreatest(int* A,int size){
    int* ans=new int[size];    
    Stack st(size);
    for (int i = size-1; i>=0; i--) {
        while (!st.isEmpty() && st.peek() <= A[i]) 
            st.pop();
        if (!st.isEmpty())  ans[i] = st.peek();
        else                ans[i] = -1;
        st.push(A[i]);
    }
    return ans;
}
int main(){
    int s;
    cout<<"Enter Size : "<<endl;
    cin>>s;
    int* A=new int[s];
    for(int i=0;i<s;i++){
        cout<<"Enter "<<i<<" element : ";
        cin>>A[i];
    }
    int* ans=nextLeftSmallest(A,s);
    cout<<"Output NLS : \n";
    for(int i=0;i<s;i++){
        cout<<ans[i]<<" ";
    }
    ans=nextRightGreatest(A,s);
    cout<<"\nOutput NRG : \n";
    for(int i=0;i<s;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}