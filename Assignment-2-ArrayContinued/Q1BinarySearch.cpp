#include<iostream>
using namespace std;
void display(int *arr,int size){
    cout<<"DISPLAYING : \n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}
void getElements(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<"Enter Element at index "<<i<<" : "<<endl;
        cin>>arr[i];
    }
}
int binarySearch(int *arr,int size){
    int el;
    cout<<"\nEnter Element To Search : \n";
    cin>>el;
    int s=0,e=size-1;
    while(s<=e){
        int mid=e+(s-e)/2;
        if(arr[mid]==el)    return mid;
        else if(arr[mid]>el) e=mid-1;
        else s=mid+1; 
    }
    return -1;
}
void checkByBinarySearch(int *arr,int size){
    int k=binarySearch(arr,size);
    (k!=-1)?cout<<"Found at : "<<k<<endl:cout<<"Not Found\n";
}
int main(){
    int size;
    cout<<"Enter Size : "<<endl;
    cin>>size;
    int *arr;
    arr=new int[size];
    getElements(arr,size);
    display(arr,size);
    checkByBinarySearch(arr,size);
    return 0;
}