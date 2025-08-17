#include<iostream>
using namespace std;
void display(int *arr,int size){
    cout<<"\nDISPLAYING : \n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}
void getElements(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<"Enter Element at index "<<i<<" : "<<endl;
        cin>>arr[i];
    }
}
void bubbleSort(int *arr,int size){
    bool swapped;
    for(int i=0;i<size-1;i++) {
        swapped = false;
        for(int j=0;j<size-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    display(arr,size);
}
int main(){
    int size;
    cout<<"Enter Size : "<<endl;
    cin>>size;
    int *arr;
    arr=new int[size];
    getElements(arr,size);
    display(arr,size);
    bubbleSort(arr,size);
    return 0;
}