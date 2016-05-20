#include "Student.cpp"

class Priority_Class
{
	struct Priority_c
	{
		int course_id;
		int year;
		int roll;
		float cgpa_priority;
		
		struct Priority_c *next;
	};
	struct Priority_c *root;
	
	public:
	
	Priority_Class()
	{
		root=NULL;
	}
	
	void prepare_priority_queue(int a,int b,int c,Student s1)
	{
		
		if(root==NULL)
		{
			root = new struct Priority_c;
			
			root->course_id=a;
			root->year=b;
			root->roll=c;
			root->cgpa_priority=s1.cgpa;
			
			root->next=NULL;
			//cout<<root->cgpa_priority<<"->";
		}
		
		else
		{
			struct Priority_c *root1,*root2,*root3;
			
			root2=root;
			
			root1= new struct Priority_c;
			
			root1->course_id=a;
			root1->year=b;
			root1->roll=c;
			root1->cgpa_priority=s1.cgpa;
			
			if(root1->cgpa_priority>root->cgpa_priority)
			{
				root1->next=root;
				root=root1;
			}
			
			else
			{
			
				while(root2!=NULL && (root2->cgpa_priority)>s1.cgpa)
				{
					root3=root2;
				
					root2=root2->next;
					//cout<<root->cgpa_priority<<"->"<<endl;
				}
			
				if(root3->next==NULL)
				{
					root3->next=root1;
					root1->next=NULL;
				}
			
				else
				{
					root3->next=root1;
					root1->next=root2;
				}
			}
		
		}

	}
	
	void get_priority(Student s[3][99][100])
	{
		struct Priority_c *root1;
		root1=root;
		
		while(root1!=NULL)
		{
			cout<<"\n\t Name: "<<s[root1->course_id][root1->year][root1->roll].name<<"\t CGPA: "<<s[root1->course_id][root1->year][root1->roll].cgpa<<endl;
			
			root1=root1->next;
		}
	}
	
	void delete_from_priority_queue(void)
	{
		if(root==NULL)
			cout<<"\n\t Wrong Entry.";
			
		else
			root=root->next;
	}
};
	

int main()
	{
		Priority_Class p1;
		int index[3]={1,1,1},dd,mm,yy;
		long long int roll1;
		int choice;
		char course_name[31];
		Student s[3][99][100];
		
		do
		{
			cout<<"\n\t\t\t --Welcome--"<<"\n\n\t Please enter your choice\n\t1.Admission\n\t2.Mark_sheet_display\n\t3.Marks_Entry\n\t4.Display the no of students till now\n\t5.Show Priority Queue\n\t6.Delete from Priority Queue\n\t7.Exit.....-->";
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
			
							if(yy<1985||yy>2016||dd<0||dd>31||mm<1||mm>12)
								cout<<"\n\t You have entered a wrong date,try for another time.";
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
					{
						s[(roll1/100)%10][(roll1/10000)%100][roll1%100-1].recieving_marks();
						
						p1.prepare_priority_queue((roll1/100)%10,(roll1/10000)%100,roll1%100-1,s[(roll1/100)%10][(roll1/10000)%100][roll1%100-1]);	
					}
						
					break;
					
				
				case 4:
					Student::count_of_total_students();
					break;
				
				case 5:
					p1.get_priority(s);
					break;
				
				case 6:
					p1.delete_from_priority_queue();
					break;
				
				case 7:
					cout<<"\n\t Thank you";
					exit(0);
					
				default:
					cout<<"\n\t Wrong entry.";
					break;
			}
			
		}while(1);
	
	return 0;
}
