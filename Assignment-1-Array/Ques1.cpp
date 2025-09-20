#include<iostream>
using namespace std;

void display(int *p,int size){
    cout<<"\nDISPLAYING\n";
    for(int i=0;i<size;i++)
        cout<<p[i]<<" ";
    cout<<endl;
}
void copyElements(int *p,int *q,int size){
    for(int i=0;i<size;i++)
        q[i]=p[i];
}
int* insertion(int *p,int size){
    int el,j;
    cout<<"Enter Element and Index to be Inserted at : "<<endl;
    cin>>el>>j;
    int *newArr;
    newArr=new int[size+1];
    copyElements(p,newArr,size);
    for(int i=size+1;i>=j;i--)
        newArr[i]=newArr[i-1];
    newArr[j]=el;
    return newArr;
}
void indexDeletion(int *p,int size){
    int k;
    cout<<"Enter Index To be Deleted : "<<endl;
    cin>>k;
    for(int i=k;i<size;i++)
        p[i]=p[i+1];
}
int linearSearch(int *p,int size, int l){
    for(int i=0;i<size;i++){
        if(p[i]==l)
            return i;
    }
    return -1;
}
void elementDeletion(int *p,int size){
    int l;
    cout<<"Enter Element to be Deleted : "<<endl;
    cin>>l;
    int res=linearSearch(p,size,l);
    if(res!=-1){
        for(int i=res;i<size;i++)
            p[i]=p[i+1];
    }
}
void deletion(int *p,int size){
    int ch;
    cout<<"\nEnter Choice : "<<"\n1.Delete an Index\n"<<"2.Delete an Element\n";
    cin>>ch;
    switch (ch){
        case 1:
            //IndexDeletion
            indexDeletion(p,size);
            break;
        case 2:
            //elementDeletion
            elementDeletion(p,size);
            break;
        default:
            cout<<"Wrong Choice\n";
            break;
    }
}
int main(){
    int ch=-1;
    int size;
    int *arr;
    cout<<"Enter Choice : \n"<<"1.Create\n"<<"2.Display\n"<<"3.Insert\n"<<"4.Delete\n"<<"5.Linear Search\n"<<"*.Exit"<<endl;
    while(ch<=5){
        cout<<"Enter Choice : "<<endl;
        cin>>ch;
        switch (ch){
        case 1:
            //Create
            cout<<"Enter Size : "<<endl;
            cin>>size;
            arr=new int[size];
            for(int i=0;i<size;i++){
                cout<<"Enter "<<(i+1)<<" Element : "<<endl;
                cin>>arr[i];
            }   
            break;
        case 2:
            //Display
            display(arr,size);
            break;
        case 3:
            arr=insertion(arr,size);
            size++;
            //Insert
            break;
        case 4:
            deletion(arr,size);
            size--;
            //Delete  
            break;
        case 5:
            //Linear Search
            int l,d;
            cout<<"Enter Element to Search  : "<<endl;
            cin>>l;
            d=linearSearch(arr,size,l);
            if(d!=-1)
                cout<<"Found at : "<<d<<endl;
            else
                cout<<"Not Found"<<endl;
            break;
        default:
            //Exit
            break;
        }
    }  
    return 0;
}