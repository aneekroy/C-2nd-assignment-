#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
class array{
private:
    int size;
    int* A;
public:
    //array(){}
    array(int numsSize,int val);
    array(int[],int);
    array(const array& arr);
    array operator +(const array& arr);
    void operator =(const array& arr);
    int& operator [](int index){
        if(index<0 || index>=size){
            static int x= INT_MIN;
            return x;
        }
        else{
            return A[index];
        }
    }
    void operator *(int factor){
        int i=0;
        for(i=0;i<size;i++){
            A[i]=A[i]* factor;
        }
    }
    friend array operator *(int ,array);
    void display(){
        cout<<"Size of array is : "<<size<<endl;
        cout<<"The elements of the array are : ";
        int i=0;
        for(i=0;i<size;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};
array operator *(int x,array arr){
    array res(arr.size,0);
    int i=0;
    for(i=0;i<arr.size;i++){
        res.A[i]=arr.A[i] * x;
    }
    return res;
}
array::array(int numsSize,int val){
    size=numsSize;
    A=(int*)malloc(sizeof(int)*numsSize);
    int i=0;
    for(i=0;i<size;i++){
        A[i]=val;
    }
    return;
}
array::array(int arr[],int len){
    size=len;
    A=(int*)malloc(sizeof(int)*size);
    int i=0;
    for(i=0;i<size;i++){
        A[i]=arr[i];
    }
    return;
}
array::array(const array& arr){
    size=arr.size;
    int i=0;
    A=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++){
        A[i]=arr.A[i];
    }
    return;
}
array array::operator +(const array& arr){
    int* res=(int*)malloc(sizeof(int)*size);
    int i=0;
    for(i=0;i<size;i++){
        res[i]=A[i]+arr.A[i];
    }
    return array(res,size);
}
void array::operator =(const array& arr){
    if(size!=arr.size){
        cout<<"Size do not match. Assignment cannot be done"<<endl;
        return ;
    }
    else{
        int i=0;
        for(i=0;i<size;i++){
            A[i]=arr.A[i];
        }
    }
}
int main(void){
    int length,init,flag;
    /*array arr1(10,0);
    arr1.display();
    array arr2(arr1);
    arr2.display();
    int B[10];
    int i=0;
    for(i=0;i<10;i++){
        B[i]=10;
    }
    array arr3(B,10);
    arr3.display();
    arr1=arr3;
    arr1.display();
    arr1 * 10;
    arr1.display();
    array arr4= 10 * arr1;
    arr4.display();
    array arr5=arr1+arr2;
    arr5.display();*/
    cout<<"Enter length of array and initialization constant : ";
    cin>>length>>init;
    cout<<endl;
    array arr1(length,init);
    arr1.display();
    cout<<"Would you like to initialize a new array object with the already existing object : "<<endl;
    cout<<"Enter 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        array arr2(arr1);
        arr2.display();
    }
    cout<<"Enter length of new C array : ";
    cin>>length;
    cout<<endl;
    int*B=(int*)malloc(sizeof(int)*length);
    for(int i=0;i<length;i++){
        cout<<"Enter value at  index "<<i<<" : ";
        cin>>B[i];
        cout<<endl;
    }
    array arr3(B,length);
    arr3.display();
    cout<<"Would you like to assign arr3 to arr1: ";
    cout<<endl<<"Press 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        arr1=arr3;
        arr1.display();
    }
    cout<<"Would you want to multiply arr1 with a constant ? "<<endl;
    cout<<"press 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        cout<<"Enter the constant : ";
        cin>>init;
        cout<<endl;
        arr1*init;
        arr1.display();
    }
    cout<<"Would you like to multiply arr1 in the format constant *  array object ? "<<endl;
    cout<<"press 0 if yes, 1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        cout<<"Enter the constant : ";
        cin>>init;
        cout<<endl;
        array arr4=init * arr1;
        arr4.display();
    }
    cout<<"Would you like to add arr1 and arr3 : ";
    cout<<endl<<"Press 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        array arr5=arr1+arr3;
        arr5.display();
    }
    cout<<"Would you like to access value at given index of arr1 ?"<<endl;
    cout<<"press 0 if yes,1 if no"<<endl;
    cin>>flag;
    if(flag==0){
        cout<<"Enter value of index : ";
        cin>>init;
        cout<<endl;
        int res=arr1[init];
        cout<<"Value of arr1["<< init <<"] is : "<< res <<endl;
    }
    cout<<"Program terminated ."<<endl;
    return 0;
}
