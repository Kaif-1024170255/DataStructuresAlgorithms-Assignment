#include<iostream>
using namespace std;
class Element{
    public:
    int r,c,x;
};
class Sparse{
    public:
    int m,n,nums;
    Element *ele;
};
void create(Sparse* s){
    cout<<"Enter Dimensions : \n";
    cin>>s->m>>s->n;
    cout<<"Enter Number of Non-Zero Elements : \n";
    cin>>s->nums;
    s->ele=new Element[s->nums];
    for(int i=0;i<s->nums;i++){
        cout<<"Enter R,C,V : \n";
        cin>>s->ele[i].r>>s->ele[i].c>>s->ele[i].x;
    }
}
void display(Sparse s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(s.ele[k].r==i && s.ele[k].c==j) cout<<s.ele[k++].x<<" ";
            else cout<<"0 ";

        }
        cout<<endl;
    }
}
Sparse* add(Sparse s1,Sparse s2){
    if(s1.m!=s2.m || s1.n!=s2.n){
        cout<<"Matrices cannot be added (dimension mismatch)\n";
        return nullptr;
    }
    Sparse *sum=new Sparse;
    sum->m=s1.m; sum->n=s1.n;
    sum->ele=new Element[s1.nums+s2.nums];
    int i,j,k;
    i=j=k=0;
    while(i<s1.nums && j<s2.nums){
        if(s1.ele[i].r<s2.ele[j].r) //s1 Row < s2 Row (Copy s1)
            sum->ele[k++]=s1.ele[i++];
        else if(s1.ele[i].r>s2.ele[j].r) //s1 Row > s2 Row (Copy s2)
            sum->ele[k++]=s2.ele[j++];
        else{    //s1 row ==  s2 row
            if(s1.ele[i].c<s2.ele[j].c) //s1 Col < s2 Col (Copy s1)
                sum->ele[k++]=s1.ele[i++];
            else if(s1.ele[i].c>s2.ele[j].c) //s1 Col > s2 Col (Copy s2)
                sum->ele[k++]=s2.ele[j++];
            else{
                sum->ele[k]=s1.ele[i++];
                sum->ele[k++].x += s2.ele[j++].x;
            }
        }
    }
    for(;i<s1.nums;i++) sum->ele[k++]=s1.ele[i];
    for(;j<s2.nums;j++) sum->ele[k++]=s2.ele[j];
    sum->nums=k;
    display(*sum);
    return sum;
}
Sparse* transpose(Sparse s){
    Sparse *trp = new Sparse;
    trp->m=s.n; trp->n=s.m; trp->nums=s.nums;
    trp->ele=new Element[s.nums];
    // Swapping
    for(int i=0;i<s.nums;i++){
        trp->ele[i].r=s.ele[i].c;
        trp->ele[i].c=s.ele[i].r;
        trp->ele[i].x=s.ele[i].x;
    }
    // Sorting Row -> Col
    for(int i=0; i<trp->nums-1; i++){
        for(int j=i+1; j<trp->nums; j++){
            if(trp->ele[i].r > trp->ele[j].r || (trp->ele[i].r == trp->ele[j].r && trp->ele[i].c > trp->ele[j].c)){
                swap(trp->ele[i], trp->ele[j]);
            }
        }
    }
    display(*trp);
    return trp;
}
Sparse* multiply(Sparse a,Sparse b){
    if(a.n!=b.m) return nullptr;
    Sparse *mul=new Sparse;
    mul->m=a.m;  mul->n=b.n;
    mul->ele=new Element[a.nums*b.nums];
    // MULTIPLY
    int k=0;
    for (int i=0;i<a.nums;i++){
        for (int j=0;j<b.nums;j++){
            if(a.ele[i].c==b.ele[j].r){
                int row=a.ele[i].r;
                int col=b.ele[j].c;
                int val=a.ele[i].x*b.ele[j].x;
                // Check if already exists
                int f=-1;
                for(int t=0;t<k;t++){
                    if(mul->ele[t].r==row && mul->ele[t].c==col){
                        f=t;
                        break;
                    }
                }
                if(f==-1){  //NO ENTRY EXIST
                    mul->ele[k].r=row;
                    mul->ele[k].c=col;
                    mul->ele[k++].x=val;
                }else   //ALREADY EXIST
                    mul->ele[f].x+=val;
            }
        }
    }
    mul->nums=k;
    // Sorting Row -> Col
    for(int i=0; i<mul->nums-1; i++){
        for(int j=i+1; j<mul->nums; j++){
            if(mul->ele[i].r > mul->ele[j].r || (mul->ele[i].r == mul->ele[j].r && mul->ele[i].c > mul->ele[j].c)){
                swap(mul->ele[i], mul->ele[j]);
            }
        }
    }
    display(*mul);
    return mul;
}
int main(){
    Sparse s1;
    create(&s1);
    cout<<"\nDISPLAYING s1 : \n";
    display(s1);
    Sparse s2;
    create(&s2);
    cout<<"\nDISPLAYING s2 : \n";
    display(s2);
    cout<<"\nDISPLAYING Sum : \n";
    add(s1,s2);
    cout<<"\nDISPLAYING MultipliedMatrix : \n";
    multiply(s1,s2);
    return 0;
}