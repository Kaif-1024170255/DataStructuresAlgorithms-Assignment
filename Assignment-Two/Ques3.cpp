#include<iostream>
using namespace std;
void display(int *arr,int size){
    cout<<"DISPLAYING : \n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void getElements(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<"Enter Element at index "<<i<<" : "<<endl;
        cin>>arr[i];
    }
}
int linearTimeSearch(int *p,int size){
    for(int i=0;i<size;i++){
        if(p[i]!=i+1)
            return i+1;
    }
}
bool useBinarySearch(int *p,int size,int l){
    int s=0,e=size-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(p[m]==l) return true;
        else if(l>p[m]) s=m+1;
        else e=m-1; 
    }
    return false;
}
int binarySearch(int *p,int size){
    for(int i=1;i<=size;i++){
        if(!useBinarySearch(p,size,i))
            return i;
    }
    return -1;
}
int main(){
    int size;
    cout<<"Enter n : "<<endl;
    cin>>size;
    size--;
    int *arr;
    arr=new int[size];
    getElements(arr,size);
    display(arr,size);
    int k,ch;
    cout<<"Enter Choice : "<<"\n1.LinearTime"<<"\n2.BinarySearch\n";
    cin>>ch;
    switch(ch){
        case 1:
            k=linearTimeSearch(arr,size);
        break;
        case 2:
            k=binarySearch(arr,size);
        break;
        default:
        break;
    }
    cout<<"\nFOUND : "<<k<<endl;
    return 0;
}