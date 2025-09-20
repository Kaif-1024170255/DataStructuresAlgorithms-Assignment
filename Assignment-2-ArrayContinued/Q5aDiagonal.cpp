#include<iostream>
#include <cmath>
using namespace std;

// DIAGONAL
class Diagonal{
    private:
    int n;
    int* A;
    public:
    Diagonal(int n){
        this->n=n;
        A=new int[n];
    }
    ~Diagonal(){
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)    cout<<A[i]<<" ";
                else    cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
void Diagonal::set(int i,int j,int x){
    if(i==j)
        A[i-1]=x;
}
int Diagonal::get(int i,int j){
    if(i==j) return A[i-1];
    else return 0;
}
int main(){
    int n;
    /*  DIAGONAL MATRIX */
    Diagonal d(4);
    d.set(1,1,5);
    d.set(2,2,4);
    d.set(3,3,4);
    d.set(4,4,4);
    d.display();

    return 0;
}