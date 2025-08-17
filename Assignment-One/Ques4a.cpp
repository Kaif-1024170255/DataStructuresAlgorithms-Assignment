#include<iostream>
using namespace std;
void display(int *p,int size){
    cout<<"DISPLAYING\n";
    for(int i=0;i<size;i++)
        cout<<p[i]<<" ";
    cout<<endl;
}
void getElements(int *p,int size){
    for(int i=0;i<size;i++){
        cout<<"Enter "<<(i+1)<<"th element : ";
        cin>>p[i];
    }
}
void reverseArray(int *p,int size){
    for(int i=0;i<size/2;i++){
        int t=p[i];
        p[i]=p[size-1-i];
        p[size-1-i]=t;
    }
}
int main(){
    int *arr,size;
    cout<<"Enter Size : "<<endl;
    cin>>size;
    arr=new int[size];
    getElements(arr,size);
    reverseArray(arr,size);
    display(arr,size);
    return 0;
}