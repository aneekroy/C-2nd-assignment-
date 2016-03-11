/*

4. Design an ARRAY class with the following features:
a. Array object may be declared for a specific size and a value for initializing all the elements. If this it is to be assumed as a 0.
b. An array object may be declared and initialized with another object.
c. An array object may be declared and initialized with another array (not the object, standard array as in C language).
Let a and b are two objects:
i. a+b will add corresponding elements.
ii. a=b will do the assignment.
iii. a[I] will return the ith element of the object.
iv. a*5 or 5*a will multiply the element with 5.
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

class Array
{
	int *n;	/*Private data members*/
	int size;
	
	int ret_size() /*Function Returning size variable*/
	{
		return size;
	} 
	
	public:			/*Public Function Members*/

	Array(int size1=1){
		size=size1;
		
		n = new int[size];		/*User defined constructor*/
		for(int i=0;i<size;i++)
			n[i]=0;
	}
	
	void operator = (int *f)
	{
		for(int i=0;i<size;i++)
			n[i]=*(f+i);		/*Assignment Opearion with a pointer of a particuar data type*/
	}	
	
	void operator = (Array b)
	{
		int c=b.ret_size();
		
		if(c>size)
			c=size;			/*Assignment Opearion with another object of same data type*/
			
		for(int i=0;i<c;i++)
			n[i]=b.n[i];
	}
	
	int operator [] (int i)			/*Operator overloading to return array element*/
	{
		if(i>size){
			cout<<"\n\t Wrong access point";
			return -1;
		}
		else
			return n[i];
			
	}
	
	Array operator * (const int k)		/*Operator overloading for const multiplication with an array(a*5 form)*/
	{
		Array b(k);
		for(int i=0;i<size;i++)
			b.n[i]=n[i]*k;
			
		return b;
	} 
	
	friend Array operator * (int a, Array b)	/*Friend Function As Invoking Object is primitive datatype*/
	{
		return b*a;
	}
	
	Array operator + (Array b)		/*Operator overloading for adding two Array*/
	{
		Array c(b.ret_size());
		
		for(int i=0;i<(this->size);i++)
			c.n[i]=n[i]+b.n[i];
		
		return c;	
	}
	
	void print_array(void)			/*Print the array*/
	{	cout<<"\n\tThe Array is : ";
		for(int i=0;i<size;i++)
			cout<<n[i]<<" , ";
			printf("\b\b\n");
	}
};//End of class Array

int main(void){
int h,choice=0;//Choice variable for input in Main Menu
int n=0,k=0;
cout<<"Enter the number of elements of Arrays :";
cin>>h;
	if(h>0){
	int *f=new int[h];
	Array a(h),b(h),c(h);
	cout<<"\n\t Enter the 1st array: ";

	for(int i=0;i<h;i++)
		cin>>f[i];
	a=f;
	
	cout<<"\n\t Enter the 2nd array: ";
		
	for(int i=0;i<h;i++)
		cin>>f[i];
	
	b=f;
	
	do
	{
		printf("\n************Main Menu****************");//Main Menu
		printf("\n\t1.Assignment by another array\n");
		printf("\t2.Addition of 2 arrays\n");
		printf("\t3.Return an array element\n");
		printf("\t4.Multiply with any const(a*5 i.e. form 1)");
		printf("\n\t5.Multiply with any const(5*a i.e. form 2)\n");
		cout<<"\t6.Print the array\n\t7.Exit \n\t";
		printf("\n\t Enter choice :");
		cin>>choice;
		switch(choice)
		{ 
			
			case 1:
				cout<<"\n\tEnter The Array to be assigned: ";
				cin>>n;
				if(n==1)//Checking for which array to be assigned
					c=a;		
				else
					c=b;
					
				cout<<"\n\t After Assignment the New array is: "<<endl;
				c.print_array();
				cout<<endl;
				break;
			
			case 2:
				c=a+b;
				//printf("The Final Array is :");
				c.print_array();
				cout<<endl;
				break;
				
			case 3:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the array key: ";
				cin>>k;
				if(a[k]!=-1){
				if(n==1)
					cout<<"\n\t So the element is: "<<a[k]<<endl;
				else if(n==2)
					cout<<"\n\t So the element is: "<<b[k]<<endl;
				else
					printf("Wrong Input !!!");
				}
				else
					printf("Wrong Input !!!");
				break;
				
			case 4:
				cout<<"\n\t Enter the array number(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Input the constant multiplier  : ";
				cin>>k;
				
				if(n==1){
						c=a*k;
						c.print_array();
						cout<<endl;
				}
				else if(n==2){
					c=b*k;
					c.print_array();
				cout<<endl;
				}
				else
					printf("Error !! Wrong Input !!");
				break;
				
			case 5:
				cout<<"\n\t Please choose the array first(1st or 2nd in numerics): ";
				cin>>n;
				cout<<"\n\t Please input the constant multiplier : ";
				cin>>k;
				
				if(n==1){
					c=k*a;
					c.print_array();
					cout<<endl;
				}
				else if(n==2){
					c=k*b;
					c.print_array();
					cout<<endl;
				}
				else
					printf("Error !! Wrong Input !!");
				break;
				
			case 6:
				cout<<"\n\t The Final array is: ";
				c.print_array();
				cout<<endl;
				break;
				
			case 7:
				cout<<"\n\t Thank you.";
				exit(0);
				
			default:
				cout<<"\n\t Wrong Entry!!";
				break;
		}			
	
	}while(choice>0&&choice<8);
	}
	else{
	printf("ERROR !!");
	}
	return 0;
}//End of main()

