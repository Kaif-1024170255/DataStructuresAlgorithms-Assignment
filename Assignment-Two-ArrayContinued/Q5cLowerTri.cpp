#include<iostream>
#include <cmath>
using namespace std;

// LOWER TRI MATRIX
class LowerTriMatrix{
    private:
    int n;
    int* A;
    public:
    LowerTriMatrix(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    ~LowerTriMatrix(){
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j)    cout<<A[(i*(i-1)/2)+(j-1)]<<" ";
                else    cout<<"0 ";
            }
            cout<<endl;
        }
    }
    int getDimension(){return n;}
};
void LowerTriMatrix::set(int i,int j,int x){
    if(i>=j)
        A[(i*(i-1)/2)+(j-1)]=x;
}
int LowerTriMatrix::get(int i,int j){
    if(i>=j) return A[(i*(i-1)/2)+(j-1)];
    else return 0;
}
int main(){
    int n;
    /*  LowerTriMatrix MATRIX */
    cout<<"Enter Dimension : \n";
    cin>>n;
    LowerTriMatrix lm(n);
    int x;
    cout<<"Enter All Elements : \n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            lm.set(i,j,x);
        }
    }
    lm.display();
    return 0;
}