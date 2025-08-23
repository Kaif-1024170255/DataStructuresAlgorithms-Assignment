#include<iostream>
#include<string>
using namespace std;
void concat(string s){
    string s2;
    cin.ignore();
    cout<<"Enter another String : \n";
    getline(cin,s2);
    s=s+" "+s2;
    cout<<"Concatenated String : "<<s;
}
void reverseString(string* s){
    for(int i=0;i<(s->size())/2;i++){
        cout<<(*s)[i]<<" ";
        char t=(*s)[i];
        (*s)[i]=(*s)[s->size()-1-i];
        (*s)[s->size()-1-i]=t;
    }
}
void removeCharacter(string* s,int i){
    for(int j=i;j<s->size();j++)
        (*s)[j]=(*s)[j+1];
}
void deleteVowels(string *s){
    char vowels[6]={'a','e','i','o','u'};
    for(int i=0;i<s->size();i++){
        for(char v:vowels){
            if(v==char((*s)[i]))
                removeCharacter(s,i);
        }
    }
}
void sortString(string* s){
    bool swapped=false;
    for(int i=0;i<s->size();i++){
        for(int j=0;j<s->size()-i-1;j++){
            swapped=false;
            if((int)(*s)[j]>(int)(*s)[j+1]){
                //Swap
                char t=(*s)[j];
                (*s)[j]=(*s)[j+1];
                (*s)[j+1]=t;
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}
void u2L2U(string* s){
    for(int i=0;i<s->size();i++){
        char ch=(*s)[i];
        if((int)(*s)[i]>=65 && (int)(*s)[i]<=90)
            (*s)[i]=(int)ch+32;
        else if((int)(*s)[i]>=97 && (int)(*s)[i]<=122)
            (*s)[i]=(int)ch-32;
    }
}
int main(){
    string s;
    cout<<"Enter String : \n";
    getline(cin,s);
    cout<<"\nEnter Choice : "<<"\n1.Concat"<<"\n2.Reverse"<<"\n3.Delete Vowels"<<"\n4.Sort"<<"\n5.UpperToLower\n";
    int ch;
    cin>>ch;
    switch (ch){
        case 1:
            concat(s);
        break;
        case 2:
            reverseString(&s);
            cout<<"Reversed String : \n"<<s;
        break;
        case 3:
            deleteVowels(&s);
            cout<<"After Removing Vowels : \n"<<s;
        break;
        case 4:
            sortString(&s);
            cout<<"Sorted String : \n"<<s;
        break;
        case 5:
            u2L2U(&s);
            cout<<"Converted String : \n"<<s;
        break;
        default:
        break;
    }
    return 0;
}