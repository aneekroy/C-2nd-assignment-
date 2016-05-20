#include<iostream>
#include<cstdlib>
using namespace std;
class String{
private:
    int len;
    char* str;
    int* ref_count;
public:
    String(int size,char c='c'){
        len=size;
        str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=c;
        }
        ref_count= new int;
        *ref_count=1;
    }
    String (char* A,int size){
        ref_count=new int;
        *ref_count=1;
        len=size;
        str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=A[i];
        }
    }
    String (const String& A){
        len=A.len;
        /*str=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            str[i]=A.str[i];
        }*/
        ref_count=A.ref_count;
        str=A.str;
        *ref_count=*ref_count+1;
    }
    ~String(){
        /*if(!str){

        }*/
        *ref_count=*ref_count -1;
        if(*ref_count==0){
           delete ref_count;
           delete str;
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
        cout<<"Ref_count = "<<*ref_count<<endl;
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
    String str(10);
    str.display();
    char arr[11]="C++CodesII";
    String str2(arr,10);
    str2.display();
    bool equals=str==str2;
    cout<<equals<<endl;
    String str3(str2);
    str3.display();
    str=str3;
    str.display();
    String str4=str+str3;
    str4.display();
    equals= str2==str3;
    cout<<equals<<endl;
    return 0;
}

