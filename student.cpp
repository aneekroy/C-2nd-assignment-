#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

class date{
int dd;
int mm;
int yy;
public :
		date(void)
		{
			dd=0;
			mm=0;
			yy=0;
		}
		int valid(){
		if(mm>0&&mm<=12){
			switch(mm){
				case 1:
					if(dd>0&&dd<32){
					return 1;
					break;}
					else{
					return 0;
					break;}
				case 2:
					if(yy%4||yy%40){
						if(dd>0&&dd<30){
							return 1;
							break;
							}
						else{
							return 0;
							break;
							}
						}
					else{
						if(dd>0&&dd<29){
							return 1;
							break;
							}
						else{
							return 0;
							break;
							}
						}
				case 3:
					if(dd>0&&dd<32){
						return 1;
						break;
						}
					else{
						return 0;
						break;
						}
				case 4:
					if(dd>0&&dd<31)
					return 1;
					else
					return 0;
				case 5:
					if(dd>0&&dd<32)
					return 1;
					else
					return 0;
					break;
				case 6:
					if(dd>0&dd<31)
					return 1;
					else
					return 0;
					break;
				case 7:
					if(dd>0&&dd<32)
					return 1;
					else
					return 0;
					break;
				case 8:
					if(dd>0&&dd<32)
					return 1;
					else
					return 0;
					break;
				case 9:
					if(dd>0&dd<31)
					return 1;
					else
					return 0;
					break;
				case 10:
					if(dd>0&&dd<32)
					return 1;
					else
					return 0;
					break;
				case 11:
					if(dd>0&&dd<31)
					return 1;
					else
					return 0;
					break;
				case 12:
					if(dd>0&&dd<32)
					return 1;
					else
					return 0;
					break;
				default:
					return 0;
					break;
					};
				}
				else{
				return 0;
				}
				return 0;
			}
			void set_date(int d,int m,int y){
			dd=d;
			mm=m;
			yy=y;
			}


};//End of class date


class Student
{
	long long int roll;
	date d;
	int yyyy;
	static int count;
	string name="NULL";
	char course[31]="NULL";
	char* arts[5]={"Bengali","English","Geography","History","Pol Science"};
	char* science[5]={"Bengali","English","Physics","Chemistry","Mathematics"};
	char* commerce[5]={"Bengali","English","Economics","Accountency","Business_Org"};
	int marks[5]={0,0,0,0,0};
	
	public:
		
	void admission(char course1[],int roll1,int yy)
	{
		strcpy(course,course1);
		
		cin.ignore();
		
		cout<<"\n\t Please enter the name:";
		getline(cin, name);
		
		yyyy=yy;
		
		if(!strcmp(course,"arts"))
			roll=10000*yyyy+100*2+roll1;
		else if(!strcmp(course,"science"))
			roll=10000*yyyy+100*1+roll1;
		else if(!strcmp(course,"commerce"))
			roll=10000*yyyy+100*0+roll1;
			
		cout<<"\n\t His roll no is: "<<roll;
		
		count++;	
	}
	
	void recieving_marks(void)
	{
		int i;
		if(!strcmp(course,"arts"))
		{
			for(i=0;i<5;i++)
			{
				cout<<"\n\t Please input the marks of "<<(arts[i])<<" = ";
				cin>>marks[i];
			}
		}
		
		if(!strcmp(course,"science"))
		{
			for(i=0;i<5;i++)
			{
				cout<<"\n\t Please input the marks of "<<(science[i])<<" = ";
				cin>>marks[i];
			}
		}
	
		if(!strcmp(course,"commerce"))
		{
			for(i=0;i<5;i++)
			{
				cout<<"\n\t Please input the marks of "<<(commerce[i])<<" = "; 
				cin>>marks[i];
			}
		}
		
	}
	
	void prepare_marksheet(void)
	{
		int i;
		cout<<"\n\t\t\t\t\t MARK SHEET\n";
		cout<<"\n\t Name: "<<name<<"\t\t\t\t\t\t\t\t\t Roll: "<<roll;
		cout<<"\n\t\t Subject\t\t\t\tMarks";
		
		if(!strcmp(course,"commerce"))	
			for(i=0;i<5;i++)
				cout<<"\n\t\t "<<commerce[i]<<"\t\t\t\t"<<marks[i];

		if(!strcmp(course,"arts"))
			for(i=0;i<5;i++)
				cout<<"\n\t\t "<<arts[i]<<"\t\t\t\t"<<marks[i];
						
		if(!strcmp(course,"science"))
			for(i=0;i<5;i++)
				cout<<"\n\t\t "<<science[i]<<"\t\t\t\t"<<marks[i];
			
	}
	
	void static count_of_total_students(void)
	{
		cout<<"\n\t So the total no of students till now: "<<count;
	}
	
};

int Student::count=0;
	
	int main()
	{
		int index[3]={1,1,1},dd,mm,yy;
		long long int roll1;
		int choice;
		char course_name[31];
		Student s[3][99][100];
		
		
		
		do
		{
			cout<<"\n\t\t\t --Welcome--"<<"\n\n\t Please enter your choice\n\t1.Admission\n\t2.Mark_sheet_display\n\t3.Marks_Entry\n\t4.Display the no of students till now\n\t5.Exit.....-->";
			cin>>choice;
			
			switch(choice)
			{
				case 1:
					
					do
					{
						cout<<"\n\t Please enter the name of the course: ";
						cin>>course_name;
						
						do
						{
							cout<<"\n\t Please enter the admission_date:";
							scanf("%d.%d.%d",&dd,&mm,&yy);
							
							if(yy<1985||yy>2016||dd<0||dd>31||mm<1||mm>12){
								cout<<"\n\t You have entered a wrong date,try for another time.";
								break;
								}
							else
								break;
						}while(1);
						
						if(!strcmp(course_name,"commerce"))
						{
							s[0][yy%100][index[0]-1].admission(course_name,index[0],yy);
							index[0]++;
							break;
						}
					
						else if(!strcmp(course_name,"science"))
						{
							s[1][yy%100][index[1]-1].admission(course_name,index[1],yy);
							index[1]++;
							break;
						}
					
						else if(!strcmp(course_name,"arts"))
						{
							s[2][yy%100][index[2]-1].admission(course_name,index[2],yy);
							index[2]++;
							break;
						}
						else
							cout<<"\n\t Invalid course name,try again";
					}while(1);
					break;
					
				case 2:
					cout<<"\n\t Please enter the roll ->";
					cin>>roll1;
					if(roll1>100000000 || roll1<10000000)
						cout<<"\n\t Wrong entry";
					else
						s[(roll1/100)%10][(roll1/10000)%100][roll1%100-1].prepare_marksheet();
					break;
					
				case 3:
					cout<<"\n\t Please enter the roll ->";
					cin>>roll1;
					if(roll1>100000000 || roll1<10000000)
						cout<<"\n\t Wrong entry";
					else
						s[(roll1/100)%10][(roll1/10000)%100][roll1%100-1].recieving_marks();
					break;
					
				
				case 4:
					Student::count_of_total_students();
					break;
				
				case 5:
					cout<<"\n\t Thank you";
					exit(0);
					
				default:
					cout<<"\n\t Wrong entry.";
					break;
			}
			
		}while(1);
		
		return 0;
	}
//g++ student.cpp -Wno-write-strings -std=c++11					
