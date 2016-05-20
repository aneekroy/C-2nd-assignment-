#include<cstdio>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class TIME
{
	int hr;
	int min ;
	int sec;
	
	public:
		static int check(int hr,int min,int sec)
		{
			if(hr>=0&&hr<24){
				if(min>=0&&min<60){
					if(sec>=0&&sec<60){
						return 1;
						}
					}
					else{
					return 0;
					}
				}	
				else{
					return 0;
				}
		} 
		/*void set()
		{	char *s=new char[15];
			printf("\nEnter Time :");
			scanf("%s",&s);
			
			int i1=0,i2=0,i3=0;
			char c=*(s+i1);
			char *n=new char[3];
			n[3]='\0';
			while(c!='\0')
			{	if(c!=':'||c!=' '||c!='\0'){
				while(c!=':'||c!=' '||c!='\0'){
					c=*(s+i1++);
					*(n+i3++)=c;
				}
				}
					else{
					i3=0;
					i2++;
					if(i2==1){
					if(check(hr,min,sec)){
					i3=0;
					while(n[i3]!='\0'){
					hr= hr*10+atoi(&n[i3++]);
					}
					}
					else {
					printf("Error!!");
					return;
					}
					}					
					else if(i2==2)	
					{ 
					if(check(hr,min,sec)){
					i3=0;
					while(s[i3]!='\0'){
					min= min*10+atoi(&n[i3++]);
					}
					}
					else{
					printf("Error!!");
					return;
					}
					}
					else if(i2==3)
					{
					if(check(hr,min,sec)){
					i3=0;
					while(n[i3]!='\0'){
					sec= sec*10+atoi(&n[i3++]);
					}
					}
					else{
					printf("Error!!");
					return;
					}
					}
					else if(i2==4)
					{	if(check(hr,min,sec)){
						i3=0;
						if(*(n)=='P'||*(n)=='p')
						{   hr=hr+12;
							if(hr>24)
							hr%=24;
						}
						}
						else{
						printf("Error");
						return;
					}
				}				
			}
		}
		}*/
		void set(){
		printf("To Enter time in 12 hrs enter 1\n");
		printf("To Enter time in 24 hrs enter 1\n");
		
		
		
		
		
		void add(int s=0,int m=0,int h=0){
		min+=m;
		hr+=h;
		sec+=s;
		if(!check(hr,min,sec)){
			if(sec>=60)
			{
				min+=sec/60;
				sec%=60;
			}
			if(min>=60)
			{
				hr+=min/60;
				min%=60;
			}
			if(hr>=24)
				hr%=24;
			}
		}
	
		void display12(void)
		{
			if(hr>12&&check(hr,min,sec))
			printf("The Time is : %d:%d:%d PM",(hr%12),min,sec);
			else if(hr==12&&check(hr,min,sec))
			printf("The Time is : %d:%d:%d PM",(hr),min,sec);
			else if(hr>0&&hr<12&&check(hr,min,sec))
			printf("The Time is : %d:%d:%d AM",hr,min,sec);
			else
			printf("ERROR !!");
		}
		void display24(void)
		{
			if(hr>=0&&hr<24&&check(hr,min,sec))
			printf("The Time is : %d:%d:%d ",hr,min,sec);
			else
			printf("Error!!");
		}
		
	};
	
	int main(void){
TIME t;
	int choice=0;int a=0,b=0,c=0;
	do{
	printf("\nEnter Choice\n");
	printf("\nEnter 1 for entering time\n");
	printf("\nEnter 2 for adding time in seconds, mins, hours\n");
	printf("\nEnter 3 for displaying time in 24 hours\n");
	printf("\nEnter 4 for displaying time in 12 hours\n");
	printf("\nEnter -1 to exit\n"); 
	scanf("%d",&choice);
	switch(choice){
	case 1:
		t.set();
		break;	
	case 2:
		printf("\nEnter time to be added in format SS MM HH :");
		
		scanf("%d %d %d",&a,&b,&c);
		t.add(a,b,c);
		break;
	case 3:
		t.display24();
		break;
	case 4:
		t.display12();
		break;
	default:
		printf("Error !!");
		break;
	}
	}while(choice>0&&choice<5);
	
	return 0;
	}
				
	
