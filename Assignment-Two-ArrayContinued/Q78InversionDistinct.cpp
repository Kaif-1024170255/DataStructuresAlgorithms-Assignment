#include<iostream>
using namespace std;
void getElements(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<"Enter element at : "<<i<<" index : ";
        cin>>arr[i];
    }
}
void display(int *arr,int size){
    cout<<"\nDisplaying : \n";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void findInversions(int *arr,int size){
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(i<j && arr[i]>arr[j])
                count++;
        }
    }
    cout<<"Number of Inversions are : "<<count<<endl;
}
void distinctElements(int *arr,int size){
    int count=size;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                count--;
                break;
            }
        }
    }
    cout<<"Number of Distinct Elements : "<<count<<endl;
}
int main(){
    int *arr;
    int size;
    cout<<"Size ? : \n";
    cin>>size;
    arr=new int[size];
    getElements(arr,size);
    display(arr,size);
    int ch;
    cout<<"Enter Choice: \n"<<"1.inversions\n"<<"2.distinctElements\n";
    cin>>ch;
    switch(ch){
        case 1:
            findInversions(arr,size);
        break;
        case 2:
            distinctElements(arr,size);
        break;
        default:
        break;
    }
    return 0;
}