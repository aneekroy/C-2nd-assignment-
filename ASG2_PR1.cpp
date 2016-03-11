/*

Question :

1. Write a program that simulates flipping a coin repeatedly and continues until three consecutive heads are tossed. At that point, your program should display the total number of coin flips that were made.


*/

#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<time.h>

using namespace std;

class COIN{
	
	int heads;//private variables to store number of heads and tails
	int toss;
	
	public:
		COIN(void){//Constructor to initialise data members
			heads=0;
			toss=0;
			}
		void toss_simulation(void){//function to simulate coin tossing
		srand(time(NULL));
		int random=0;
		this->heads=0;
		while(heads<3){
		random=rand()%2;   //random variable
		if(random)
		{
			printf("\nHeads");
			this->heads++;
		}
		else
		{
			printf("\nTails");
			this->heads=0;
		}
		this->toss++;//incrementing the number of toss
		}
		return;
		}
		void get_toss(void)//Function to print toss
		{
		printf("the number of tosses are :%d\n",toss);
		}
		void set_toss(void)//Function to set toss to 0
		{
		toss=0;
		}
	}coin;//Global Object of class COIN
	
	int main(void)
	{	int choice=0;//choice variable for Main Menu
		printf("\n\nWelcome To Coin Toss Simulation\n");
		do{
			printf("\nEnter 1 to simulate coin toss\n");
			printf("\nEnter 0 to exit !!\n\t Enter :");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				coin.toss_simulation();
				printf("\nFor 3 consecutive heads ");
				coin.get_toss();
				coin.set_toss();
				break;
			default :
				printf("\nExiting !!!");
				break;
			}
		}while(choice==1);
	return 0;
	
	}//End of main() function
