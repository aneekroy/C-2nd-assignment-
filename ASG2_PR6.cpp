/* PROGRAM 6: to modify the previous string program so that assigning/initializing a string by another will not copy it
		physically but will keep a reference count, which will be incremented. Reference value 0 
		means the space can be released.*/

#include<iostream>
#include<cstring>

using namespace std;

class String{

	private:
		int *cp;//for reference count
		char *arr; //data memeber to store the characters
		int size; //data member to store the size of the string
	public:
		/*constructor to initialize the string object with a size and some characters*/
		String(int a=0){
			cp=new int; //allocating memory to the variable cp
			*cp=1;      //storing the value 1 in cp
			int i;
			size=a;
			arr= new char(size);
			for(i=0;i<size;i++)
				cin>>arr[i];//taking values fronm the user
		}
		/*copy constructor to initialize one string object with another*/
		String(const String &s){
			cp=s.cp;   //equating the reference count of the two objects
			arr=s.arr;//equating the two sizes
			size=s.size;
			for(int j=0;j<size;j++)
				arr[j]=s.arr[j];
			*cp+=1;  //incrementing the value of cp by 1
		}

		/*constructor to initialize the string object with another c++ string*/
		String(string s){
			cp=new int;
			*cp=1;
			size=s.length();
			for(int j=0;j<size;j++)
				arr[j]=s[j];
		}
		/*destructor to delete the reference count of the object when it is no longer needed or when it is assigned a different string object*/
		~String(){
			
			*cp=*cp-1;
			if(*cp==0){//checking if the value of reference count is 0 or not

				delete cp;
				delete arr;
			}
		}


		void display(void); //display  the resultant string
		
	/*overloaded + operator to concatenate two strings*/
		void operator +(String a){
			
			string b="";int i,k;
			for(i=0;i<size;i++)
				b=b+arr[i];
			for(k=0;k<a.size;k++)
				b=b+a.arr[k];
			cout<<b;
			
		}
		
	/*overloaded = operator to equate  two strings*/
		String operator =(String a){

			size=a.size;
			for(int i=0;i<size;i++)
				arr[i]=a.arr[i];  //equating each character
			
			return *this;
		}
/*overloaded == operator to compare two strings*/

		bool operator ==(String b){
			int j,flag=1;
			if(size!=b.size)//checking if the string objects have equal size
				return false;
			else{
				for(j=0;j<size;j++)
					if(arr[j]==b.arr[j])
						flag=1;
					else{
						flag=0;
						break;
					}
			if(flag==0)
				return false;
			else
				return true;
			}
			
		}

	/*overloaded > operator to compare two strings*/

		bool operator >(String b){
			int flag=0,i;
			if(size>b.size){ //to check if the size of the first string is greater or not
				for(i=0;i<b.size;i++){
					if(int(arr[i])>=int(b.arr[i]))
						flag=1;
					else if(int(arr[i])!=int(b.arr[i])){
						flag=0;   //keeping a flag to find at which point the character of the 2nd string is < than the 1st
						break;}
				}
				
				
			}
			else{
				for(i=0;i<size;i++){
					if(int(arr[i])>int(b.arr[i])){
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
				return false;
			else
				return true;

		}
		/*overloaded < operator to concatenate two strings*/
		bool operator <(String b){
			
			if(*this>b)//just swapping the two objects when calling the > operator
				return false;
			else
				return true;
		}	
		
	
};
/*to display the string object at any time*/
void String::display(){
	
	cout<<"\t\t The String is: \n";
	for(int j=0;j<size;j++)
		cout<<arr[j]<<" ";
	cout<<endl;
}	

/*	MAIN FUNCTION*/	

int main(){
	int choice,s,v,s1,v1,m;int choice1,c,c1;String a1;string str;char yes_no;int coi;String a,b,str1;//variable decleration
	/*menu driven choices*/
	while(true){
			cout<<"\n";
			cout<<"**************Main Menu***********************\n";
			cout<<"\t\t 1. INITIALIZE STRINGS \n";
			cout<<"\t\t 2. ADD STRINGS\n";
			cout<<"\t\t 3. COMPARE TWO STRINGS\n";
			cout<<"\t\t 4. EXIT\n";
			cout<<"Enter Choice : ";
			cin>>choice;
			if(choice==4)
				break;
			else{
				switch(choice){
					/* 3 types of initialization of the string object*/
					case 1:cout<<"\t\t1.Initiise string of Size N \n";
					       cout<<"\t\t2.INITIALIZE STRING WITH ANOTHER OBJECT STRING \n";
					       cout<<"\t\t3.INITIALIZE STRING WITH ANOTHER STRING (OF C++)\n";
					       cin>>choice1;
						switch(choice1){
					
							case 1: {cout<<"\t\t enter size\n";
								cout<<" ENTER LENGTH \n";
								cin>>s;
								cout<<"ENTER CHARACTERS TO INITIALIZE THE STRING\n";
								a1=String(s);//calling user defined constructor
								a1.display();
								break;}
							

							case 2:{cout<<"ENTER A STRING OBJECT"<<endl;
							       cin>>s;
							       String a2(s);
							       a1=a2;//calling the overloaded assignment operator operator
							       a1.display();
								break;
								}
							
							case 3:{ cout<<"ENTER YOUR STRING \n";
								cin>>str;
								a1=str;
								a1.display();
								break;}
						
							default: cout<<"wrong input \n";
						}
						break;
				/*asking the user if the entered string is to be used as an accumulator*/
					case 2:{cout<<"\t\t DO YOU WANT TO CONTINUE WITH OLD STRING (Y/N) \n";
					       cin>>yes_no;
						if(yes_no=='Y'){
							cout<<"\t\t ENTER ANOTHER STRING B \n";
							cin>>s;
							str1=String(s);
							a1+str1;
						}
					/*if the user wants he/she can enter two different strings for concatenation*/
						else{
		
							cout<<"\t\t ENTER 1ST STRING  \n";
							cout<<"ENTER LENGTH \n";
							cin>>s;
							cout<<"ENTER CHARACTERS \n";
							String a3(s);
							cout<<"\n";
						       cout<<"\t\t ENTER SECOND STRING OBJECT \n";
							cout<<"ENTER LENGTH \n";
							cin>>s1;
							cout<<"ENTER CHARACTERS \n";
							String a4(s1);
							a3+a4;
						}
						break;
						}
							
						/*for comparison of two strings whether == or > or <*/
					case 3: {cout<<"\t\tCOMPARE TWO STRINGS \n";
					/*entering two seperate strings*/
						cout<<"\t\tENTER TWO STRING OBJECTS"<<endl;
						cout<<"\t\t ENTER 1ST STRING OBJECT \n";
						cout<<"ENTER LENGTH \n";
						cin>>s;
						cout<<"ENTER CHARACTERS \n";
						a=String(s);
						cout<<"\n";
					       cout<<"\t\t ENTER SECOND STRING OBJECT \n";
						cout<<"ENTER LENGTH \n";
						cin>>s1;
						cout<<"ENTER CHARACTERS \n";
						b=String(s1);
					/*to check how the two strings are related whether = or > or<*/
					        if((a==b)==true)
							cout<<"\t\tthe strings are equal \n";
					        else if(a>b)
							cout<<"\t\t 1st string  is greater than 2nd string\n";
								
						else 
							cout<<"\t\t 1st string a is smaller than 2nd string \n";
						break;}
					default: cout<<"wrong choice"<<endl;
			}
	}
}
return 0;
}//main function ends
