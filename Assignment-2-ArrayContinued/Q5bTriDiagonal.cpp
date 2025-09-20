#include<iostream>
#include <cmath>
using namespace std;

// LOWER TRI MATRIX
class Tridiagonal{
    private:
    int n;
    int* A;
    public:
    Tridiagonal(int n){
        this->n=n;
        A=new int[3*n-2];
    }
    ~Tridiagonal(){
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((i-j)==1)    cout<<A[i-2]<<" ";
                else if((i-j)==0)  cout<<A[(n-1)+i-1]<<" ";
                else if((i-j)==-1) cout<<A[(2*n-1)+i-1]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
    int getDimension(){return n;}
};
void Tridiagonal::set(int i,int j,int x){
    if((i-j)==1)    A[i-2]=x;
    else if((i-j)==0)  A[(n-1)+i-1]=x;
    else if((i-j)==-1) A[(2*n-1)+i-1]=x;
}
int Tridiagonal::get(int i,int j){
    if((i-j)==1)    return A[i-2];
    else if((i-j)==0)  return A[(n-1)+i-1];
    else if((i-j)==-1) return A[(2*n-1)+i-1];
    else return 0;
}
int main(){
    int n;
    /*  Tridiagonal MATRIX */
    cout<<"Enter Dimension : \n";
    cin>>n;
    Tridiagonal tdm(n);
    int x;
    cout<<"Enter All Elements : \n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            tdm.set(i,j,x);
        }
    }
    tdm.display();
    return 0;
}