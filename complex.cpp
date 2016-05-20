#include<iostream>
#include<cstdio>
using namespace std;

class complex{
	
		private :
			int real;
			int comp;

		public :
		complex(void)
		{
		real=0;
		comp=0;
		}
			void set(){
				
				printf("Input the Complex and Real part :");
				scanf("%d %d",&real,&comp);
			return ;
			}
			void get(){
				if(comp>0&&real!=0)
				printf("\nThe Complex Number is : %d +i %d \n",real,comp);
				else if(comp<0&&real!=0)
				printf("\nThe Complex Number is : %d -i %d \n",real,(-1)*comp);
				else if(real==0){
					if(comp<0)
						printf("\nThe Complex Number is : -i %d \n",((-1)*comp));
					else
						printf("\nThe Complex Number is : +i %d \n",comp);
				}
				else if(comp==0){
					printf("\nThe Complex Number is : %d \n",real);
				}
			}
		
			void add(complex a,complex b){
				real=a.real+b.real;
				comp=a.comp+b.comp;
				return ;
			}
			void subtract(complex a,complex b){
				real=a.real-b.real;
				comp=a.comp-b.comp;
				return ;
			}

};//End of class complex

int main(void){
	complex x,y,c;
	int choice=0;
	do{
	printf("Enter choice\n");
	printf("Enter 1 to input\n");
	printf("Enter 2 to display\n");
	printf("Enter 3 to add\n");
	printf("Enter 4 to subtract\n");
	printf("Enter any other number to exit");
	scanf("%d",&choice);
	switch(choice){
		case 1 :
			x.set();
			y.set();
			break;
		case 2 :
			x.get();
			y.get();
			break;
		case 3 :
			c.add(x,y);
			c.get();
			break;
		case 4 :
			c.subtract(x,y);
			c.get();
			break;
		default :
			printf("ERROR!!!!!\n");
			break;
		}
	}while(choice>0&&choice<5);
	
	return 0;
	}
	
