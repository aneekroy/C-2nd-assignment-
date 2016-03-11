/*

2. Pascal’s Triangle has the interesting property that every entry is the sum of the two entries above it, except along the left and right edges, where the values are always 1. Consider, for example, the highlighted entry in the following display of Pascal’s Triangle:


This entry, which corresponds to c(6, 2), is the sum of the two entries—5 and 10—that appear above it to either side. Write a simple test program to demonstrate that your combinations function works. You may also write a program that uses c(n, k) to display the first ten rows of Pascal’s Triangle.

*/

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

class pascal
{
	int arr[20][20];//2D Array for storing pascal triangle
	int row;//pvt member for storing current row number
	int run;//pvt member for storing the current column number
	public :
		pascal(void)//constructor for initialising
		{
			for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
			arr[i][j]=0;
			row=0;
			run=0;
		}
	private:
		int fact(int x){//function to calculate the factorial
		if(x>1)
			return x*fact(x-1);
		else if(x==0||x==1)
			return 1;
		else
			return -1;
		}
		int com(int n,int k){//function to calculate the combination value (nCk)
			if(n>=0&&k>=0&&n>=k)
				return (fact(n)/(fact(k)*fact(n-k)));
			else
				return -1;
			}
	public:
		void generate_pascal_thru_comb(void)//Generating function through Combination
		{	
			
		printf("\nEnter Number of rows : ");
		cin>>(this->row);
			run++;
			int i=0,j=0;
			for(i=0;i<row;i++)
			{
				for(j=0;j<=i;j++)
				{
					this->arr[i][j]=com(i,j);
				}
			}
		return ;
		}
		void generate_pascal_thru_dp(void)//Genarating function through adding members of previous rows
		{	
		printf("\nEnter Number of rows : ");
		cin>>(this->row);
		run++;
		int i=0,j=0;
			arr[i][j]=1;
			for(i=1;i<row;i++)
			{
				arr[i][0]=1;
				arr[i][i]=1;
				
				for(j=1;j<i;j++)
				{
					this->arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
				}
			}
			return;
		}
		void display(void){//function to display pascal triangle
			int sp=40-(this->row);
			for(int i=0;i<(this->row);i++)
			{
				for(int j=0;j<=sp;j++)
					printf("  ");
				for(int k=0;k<=i;k++)
					printf("%3d  ",arr[i][k]);
				printf("\n\n");
				sp-=1;
			}
		return;
		}
		int check_validity(void){int n=0,k=0;//function to chekc validity
		printf("\nEnter Row Number of Element : ");
		scanf("%d",&n);
		printf("\nEnter Column Number of Element : ");
		scanf("%d",&k);
			if(run>0){
			
			if(n>=0&&k>=0&&n>=k){
			
			if(arr[n][k]==com(n,k)){
				return 1;
				//printf("Valid");
				}
			else{
		
				printf("\nNOT VALID!!!\n");
						return -1;
				}
			}
			else{
				printf("\nWrong Input !!\n");
				return -1;
				}
			}
			else{
			
			printf("FIRST RUN !! Run again");
					return -1;
			}
		}	
	}pas;//Object for calling pascal triangle class

	int main(void){
	int choice=0;//Choice variable for main menu
	
	do{
		printf("\n*********************MAIN MENU*************************\n");
		printf("\nEnter 1 to create Pascal Triangle Through Combination Function\n");
		printf("\nEnter 2 to create Pascal Triangle Through dp\n");
		printf("\nEnter 3 to check validity of element at given (Row,Column)\n");	
		printf("\nEnter 4 to check Display The Pascal Triangle\n");
		printf("\nEnter -1 or any other number to exit !!\n");
		printf("\n*******************************************************\n");
		printf("\nEnter Choice : "); 
		scanf("%d",&choice);
		switch(choice){
			case 1:
				pas.generate_pascal_thru_comb();
				break;
			case 2:
				pas.generate_pascal_thru_dp();
				break;
			case 3:
				if(pas.check_validity()!=-1)
				printf("\nValid");
				break;
			case 4:
				pas.display();
				break;
			default:
				printf("Exiting!!!");
				break;
			}
		}while(choice>0&&choice<5);\
		return 0;
		
		}//End of main menu
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
