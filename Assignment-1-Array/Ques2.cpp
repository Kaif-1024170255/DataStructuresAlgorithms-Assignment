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
void removeElement(int *p,int pos,int size){
    for(int i=pos;i<size;i++)
        p[i]=p[i+1];
}
int removeDuplicates(int *p,int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(p[i]==p[j]){
                removeElement(p,i,size);
                size--;
            }
        }
    }
    return size;
}
int main(){
    int *arr,size;
    cout<<"Enter Size : "<<endl;
    cin>>size;
    arr=new int[size];
    getElements(arr,size);
    display(arr,size);
    size=removeDuplicates(arr,size);
    display(arr,size);
    return 0;
}