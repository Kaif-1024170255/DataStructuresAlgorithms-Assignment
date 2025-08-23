#include<iostream>
#include <cmath>
using namespace std;

// LOWER TRI MATRIX
class UpperTriMatrix{
    private:
    int n;
    int* A;
    public:
    UpperTriMatrix(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    ~UpperTriMatrix(){
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j)    cout<<A[((i-1)*n-(i-1)*(i-2)/2)+(j-i)]<<" ";
                else    cout<<"0 ";
            }
            cout<<endl;
        }
    }
    int getDimension(){return n;}
};
void UpperTriMatrix::set(int i,int j,int x){
    if(i<=j)
        A[((i-1)*n-(i-1)*(i-2)/2)+(j-i)]=x;
}
int UpperTriMatrix::get(int i,int j){
    if(i<=j) return A[((i-1)*n-(i-1)*(i-2)/2)+(j-i)];
    else return 0;
}
int main(){
    int n;
    /*  LowerTriMatrix MATRIX */
    cout<<"Enter Dimension : \n";
    cin>>n;
    UpperTriMatrix um(n);
    int x;
    cout<<"Enter All Elements : \n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            um.set(i,j,x);
        }
    }
    um.display();
    return 0;
}