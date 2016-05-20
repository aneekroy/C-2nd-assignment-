#include<iostream>
#include<cstdio>

using namespace std;

class Time
{
	int hours=0,scan_hours=0;
	int minutes=0,scan_minutes=0;
	
	public:
	
	void input_time_in_format_1(void)
	{
		cout<<"\n\t Enter the time in the format hh:mm A.M./P.M.:  ";
		if(scanf("%d",&hours)==1)
		{
			if(scanf(":%d A.M.",&minutes)==1)
			{	
				if(hours>12||minutes>60||hours<0||minutes<0)
					{	
						cout<<"\n\t Wrong entry";
						hours=minutes=0;
					}
				else	
					cout<<"\n\t Your time has been accepted";
			}
			else if(scanf(":%d P.M.",&minutes)==1)
			{
				if(hours>12||minutes>60||hours<0||minutes<0)
					{	
						cout<<"\n\t Wrong entry";
						hours=minutes=0;
					}
				
				else
					cout<<"\n\t Your time has been accepted";
					
				//hours=(hours+12)%24;	
			}	
			else
			{	
				cout<<"\n\t Wrong entry";
				hours=0;
				minutes=0;
			}
				
		}
		else
		{	
			cout<<"\n\t Wrong entry";
			hours=0;
		}
		
			
	}
	void input_time_in_format_2(void)
	{
		cout<<"\n\t Enter the time in the format hh:mm hours:  ";
		if(scanf("%d",&hours)==1 && hours<24)
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
				
		
	void show_time_in_format_1(void)
	{
		cout<<"\n\t Showing time in 24 hours format: "<<hours<<":"<<minutes<<" hours";
	}
		
	void show_time_in_format_2(void)
	{
		if(hours>12)
			cout<<"\n\t Showing time in 12 hours format: "<<(hours%12)<<":"<<minutes<<" P.M.\n\n";
		else
			cout<<"\n\t Showing time in 12 hours format: "<<hours<<":"<<minutes<<" A.M.\n\n";
	}
	void add_time(void)
	{
		cout<<"\n\t Please enter the hours and minutes respectively";
		cin>>scan_hours;
		cin>>scan_minutes;
		if(minutes+=scan_minutes>=60)
		{
			hours+=(scan_hours+1);
			hours%=24;
		}
		else
		{
			hours+=(scan_hours);
			hours%=24;
		}
	}
			
		
};

int main()
{
	Time t1;
	int choice;
	do
	{
		cout<<"\n\t\t\t --Welcome--"<<"\n\n\t Please enter your choice \n\t1.Input time in 12 hours format\n\t2.Input time in 24 hours format\n\t3.Show time in 12 hours format\n\t4.Show time in 24 hours format\n\t5.Add user input time\n\t6.Exit....-->";
			cin>>choice;
			switch(choice)
			{
				case 1:cin.ignore();
					t1.input_time_in_format_1();
					break;
			
				case 2:
					t1.input_time_in_format_2();
					break;
			
				case 3:
					t1.show_time_in_format_2();
					break;
			
				case 4:
					t1.show_time_in_format_1();
					break;
			
				case 5:
					t1.add_time();
					break;
			
				case 6:
					cout<<"\n\t Thank You";
					exit(0);
			
				default:
					cout<<"\n\n\t Wrong entry";
					break;
					
			}
				
	}while(1);
	
	return 0;
}	
