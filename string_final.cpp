#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class String{
private:
    int len;
    char* str;
public:
    String(int size,char c='c'){
        len=size;
        str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=c;
        }
    }
    String (char* A,int size){
        len=size;
        str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=A[i];
        }
    }
    String (const String& A){
        len=A.len;
        str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=A.str[i];
        }
    }
    void operator =(const String& A){
        len=A.len;
        str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=A.str[i];
        }
    }
    String operator +(const String& A){
        char*temp=(char*)malloc(sizeof(char)*(len+A.len));
        int i=0;
        for(i=0;i<len;i++){
            temp[i]=str[i];
        }
        for(int j=0;j<A.len;j++){
            temp[i]=A.str[j];
            i++;
        }
        return String(temp,len+A.len);
    }
    void display(){
        for(int i=0;i<len;i++){
            cout<<str[i];
        }
        cout<<endl;
    }
    bool operator==(const String& A){
        if(len!=A.len){
            return false;
        }
        for(int i=0;i<len;i++){
            if(str[i]!=A.str[i]){
                return false;
            }
        }
        return true;
    }
};
int main(void){
    int init,flag;
    cout<<"First we build a string object."<<endl;
    cout<<"Enter length of character array within string object : ";
    cin>>init;
    cout<<endl;
    String str(init);
    str.display();
    cout<<"Enter a C type string to initialize a new user defined string object : ";
    char dummy[100];
    cin>>dummy;
    cout<<endl;
    int i=0;
    while(dummy[i]!='\0'){
        i++;
    }
    String str2(dummy,i);
    str2.display();
    cout<<"Checking if already created to strings are the same ..."<<endl;
    bool equals=str==str2;
    if(equals){
        cout<<"Both the strings are the same"<<endl;
    }
    else{
        cout<<"The strings aren't the same"<<endl;
    }
    cout<<"Creating a new string object using already existing string object str2"<<endl;
    String str3(str2);
    str3.display();
    cout<<"Would you like to assign a string to another ? "<<endl;
    cout<<"Press 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        str=str3;
        str.display();
    }
    cout<<"Would you like to concatinate two strings ?"<<endl;
    cout<<"Press 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        String str4=str+str3;
        str4.display();
    }
    cout<<"Would you want to check if str2 and str3 string objects are the same ? "<<endl;
    cout<<"Press 0 if yes, 1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        equals=(str2==str3);
        if(equals){
            cout<<"Both the strings are the same"<<endl;
        }
        else{
            cout<<"The string objects aren't the same"<<endl;
        }
    }
    cout<<"Program terminated"<<endl;
    return 0;
}
