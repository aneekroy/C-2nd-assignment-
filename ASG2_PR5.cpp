/*

5. Design a STRING class, which will have the initialization facility similar to array class. Provide support for 
Assigning one object for another, 
Two string can be concatenated using + operator, 
Two strings can be compared using the relational operators.

*/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std;

class STRING
{
	char *a;//pvt data member for STRING Class
	
	public:
	
	STRING()//Default constructor Initialisation
	{
		a='\0';
	}
	
	STRING (const STRING &t)//Constructor for STRING class object initialisation
	{
		a=new char[strlen(t.a)+1];
		strcpy(a,t.a);
	}
	
	STRING(std::string b)//Constructor for String initialisation of stl
	{
		a=new char[b.size()+1];
		strcpy(a,b.c_str());
	}

	void operator =(const char *f)//Overloading Assignment Operator
	{
		a=new char[strlen(f)+1];
		strcpy(a,f);
	}
	
	void operator =(char *f)//Overloading Assignment Operator
	{
		a=new char[strlen(f)+1];
		strcpy(a,f);	
	}
	
	friend STRING operator +(STRING c,STRING b)//Overloading + operator
	{
		STRING s1;
		s1.a=new char[strlen(b.a)+strlen(c.a)+1];
			
		strcat(s1.a,c.a);
		strcat(s1.a,b.a);
		
		return s1;
	}
	
	void scan(void)//Function for Scanning Input
	{
		string s2;
		getline(cin,s2);
		a=new char[s2.size()+1];
		strcpy(a,s2.c_str());
	}
	
	friend ostream &operator <<(ostream &t,STRING &s) //overloading extraction operator
	{
		t<<"\n\t The String is : "<<s.a<<endl ;
		return t;
	}
	
	friend int operator <(STRING b,STRING c)//Less Than Operator Overloading
	{
		if(strcasecmp(b.a,c.a)<0)
		return 1;
	}
	
	friend int operator >(STRING b,STRING c)//Greater than Operator Overloading
	{
		if(strcasecmp(b.a,c.a)>0)
		return 1;
	}	
	
	friend int operator ==(STRING b,STRING c)//Equality Operator Overloading
	{
		if(strcasecmp(b.a,c.a)==0)
		return 1;
	}	 	
		
};

//End of Class STRING

int main()//Main function
{
	STRING a,b,c;//String Objects
	int choice,flag=0;
	
	do
	{
		cout<<"\n\t***************Main Menu***************\n\t1.Enter The strings \n\t2.Concatinate the strings \n\t3.Compare them \n\t4.Display the strings\n\t5.Exit\n\n \t  Enter your choice:  ->";
		cin>>choice;//Choice variable for main menu
		
		switch(choice)
		{
			case 1:
				cin.ignore();
					
				cout<<"\n\t Enter the 1st string: ";
				a.scan();
		
				cout<<"\n\t Enter the 2nd string: ";
				b.scan();
					
				break;
				
			case 2:
			flag=1;
				c=a+b;
				cout<<"\n\t The New String is.\n";
				cout<<c;
				break;
				
			case 3:
				if(a>b)
					cout<<"\n\t 1st string is greater than the 2nd one.";
				
				else if(a==b)
					cout<<"\n\t Both the strings are same,";
				
				else if(a<b)
					cout<<"\n\t 2nd String is grater than the 1st one. ";
				break;
				
			case 4:
				cout<<a;
				cout<<b;
				if(flag)//Checking whether c object has been used
					cout<<c;
				break;
					
			case 5:
				cout<<"\n\t Thank you. Exiting !!!\n"<<endl;
				break;
				
			default:
				cout<<"\n\t Wrong Entry. Exiting !!!\n\n";
				break;
		}//End of switch case
			
	}while(choice>0&&choice<5);
	
	return 0;
}//End of main()
