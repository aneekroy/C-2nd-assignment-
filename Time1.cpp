#include<iostream>
#include<cstdio>

using namespace std;

class Time
{
	int hours=0,scan_hours=0;
	int minutes=0,scan_minutes=0;//data members
	
	public:
	
	void input_time_in_format_12(void)//Function for taking input in 12 hour format
	{
		cout<<"\n\t Enter the time in the format hh:mm A.M./P.M.:  ";
		if(scanf("%d",&hours)==1)//taking Input for Hours
		{
			if(scanf(":%d A.M.",&minutes)==1)//Taking Input for mins in given format 
			{	if(hours==12)
				hours=0;
				if(hours>12||minutes>60||hours<0||minutes<0)
					{	
						cout<<"\n\t Wrong entry";//Exception Handling
						hours=minutes=0;
					}
				else	
					cout<<"\n\t Your time has been accepted";
			}
			else if(scanf(":%d P.M.",&minutes)==1)//Taking Input for mins in given format 
			{
				if(hours>12||minutes>60||hours<0||minutes<0)
					{	
						cout<<"\n\t Wrong entry";//Exception Handling
						hours=minutes=0;
					}
				
				else
					cout<<"\n\t Your time has been accepted";//Exception Handling
					
	
			}	
			else
			{	
				cout<<"\n\t Wrong entry";//Exception Handling
				hours=0;
				minutes=0;
			}
				
		}
		else
		{	
			cout<<"\n\t Wrong entry";//Exception Handling
			hours=0;
		}
		
			
	}
	void input_time_in_format_24(void)//Function for 24 hour format
	{
		cout<<"\n\t Enter the time in the format hh:mm hours:  ";
		if(scanf("%d",&hours)==1 && hours<24&&hours>=0)
		{
			if(scanf(":%d hours",&minutes)==1 && minutes<60)
				cout<<"\n\t Your time has been accepted";
				
			else
			{	
				cout<<"\n\t Wrong entry";
				hours=minutes=0;
			}
		}
		else
		{	
			cout<<"\n\t Wrong entry";
			hours=0;
		}
	}
				
		
	void show_time_in_format_24(void)//display time in 24 hour
	{
		cout<<"\n\t Showing time in 24 hours format: "<<hours<<":"<<minutes<<" hours";
	}
		
	void show_time_in_format_12(void)//Display time in 12 hour format
	{	if(hours==12)
			cout<<"\n\t Showing time in 12 hours format: "<<(hours)<<":"<<minutes<<" P.M.\n\n";
		else if(hours>12&& hours<24)
			cout<<"\n\t Showing time in 12 hours format: "<<(hours%12)<<":"<<minutes<<" P.M.\n\n";
		else
			cout<<"\n\t Showing time in 12 hours format: "<<hours<<":"<<minutes<<" A.M.\n\n";
	}
	void add_time(void)//Function for adding time
	{
		cout<<"\n\t Please enter the minutes ";
		cin>>scan_minutes;
		int hrs=0;
		if((minutes+=scan_minutes)>=60)
		{	while(minutes>=60){
			hrs=minutes/60;
			hours+=(hrs);
			hours%=24;
			minutes%=60;
		}
		}
	}
			
		
};//End of class Time

int main()//start of function main
{
	Time t1;
	int choice;
	do
	{//Main menu
		cout<<"\n\t\t\t --Welcome--"<<"\n\n\t Please enter your choice \n\t1.Input time in 12 hours format\n\t2.Input time in 24 hours format\n\t3.Show time in 12 hours format\n\t4.Show time in 24 hours format\n\t5.Add user input time\n\t6.Exit....-->";
			cin>>choice;
			switch(choice)
			{
				case 1:cin.ignore();
					t1.input_time_in_format_12();//Input for 12 hours
					break;
			
				case 2:
					t1.input_time_in_format_24();//Input for 12 hours
					break;
			
				case 3:
					t1.show_time_in_format_12();//Printing for 12 hours
					break;
			
				case 4:
					t1.show_time_in_format_24();//printing for 24 hours
					break;
			
				case 5:
					t1.add_time();//Function call for adding time
					break;
			
				case 6:
					cout<<"\n\t Thank You";//case for exiting 
					exit(0);
			
				default:
					cout<<"\n\n\t Wrong entry"; //wrong entry
					break;
					
			}
				
	}while(1);
	
	return 0;
}//End of main	
