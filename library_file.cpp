#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;


class item
{
	std::string name;
	std::string author;
	char type[50];
	int id;

	public:

	void get_info (int flag1)
	{
		FILE *fp;
		int i,k=0,flag2=0;
		fp=fopen("Book_List.txt","a+");
		char line1[300];
		char line2[100];
		if(flag1)
		{
			cout<<"\n\t Please enter the type(journals/books): ";
			cin>>type;
		}
		else
			strcpy(type,"books");

		cout<<"\n\t Please enter the name of the book: ";
		cin.ignore();
		getline(cin,name);

		cout<<"\n\t Please enter the author of the book: ";
		getline(cin,author);

		while(fgets(line1,200,fp)!=NULL)
		{
			for(i=0;line1[i]!='$';i++)
				line2[i]=line1[i];
			line2[i]='\0';
			i++;
				if(!strcmp(name.c_str(),line2))
				{
					while(line1[++i]!='*')
					{
						line2[k]=line1[i];
						k++;
					}
					line2[k]='\0';
					k=0;
					if(!strcmp(author.c_str(),line2))
					{
						cout<<"\n\t Found!";
						flag2=1;
						break;
					}
				}
				else
					continue;
		}
		if(flag2)
		{

			cout<<"\n\t Please enter the id of the book: ";
			cin>>id;
		}
	}

	void put_info (void)
	{
		cout<<"\n\tId: "<<id<<"\t Type: "<<type<<"\t Name: "<<name<<"\t Author: "<<author;
	}
};

class issue
{
	int transaction_id;
	item it[10];
	int dd;
	int mm;
	int yyyy;
	int dd1;
	int mm1;
	int yyyy1;
	char issuer_type[10];
	char issuer_name[50];
	int quantity;
	int fine;

	public:

	void get_info()
	{
		int flag;

		cout<<"\n\t Please input the transaction id: ";
		cin>>transaction_id;

		cout<<"\n\t Please input the name of the issuer: ";
		cin>>issuer_name;

		cout<<"\n\t Please input the type of the issuer: ";
		scanf("%s",issuer_type);

		cout<<"\n\t Please enter the quantity: ";
		cin>>quantity;

		//cout<<"\n\t Please input the date: ";
		//scanf("%d/%d/%d",&dd,&mm,&yyyy);

		if(!strcmp(issuer_type,"Faculty") && quantity <=10)
		{
			flag=1;

			for(int i=0;i<quantity;i++)
				it[i].get_info(flag);

		}

		else if(!strcmp(issuer_type,"Student") && quantity <=2)
		{
			flag=0;

			for(int i=0;i<quantity;i++)
				it[i].get_info(flag);
		}

		else
			cout<<"\n\t Wrong entry";
	}

	void submit_date(int dd2,int mm2,int yyyy2)
	{
		dd1=dd2;
		mm1=mm2;
		yyyy1=yyyy2;
	}

	void calculate_fine(void)
	{
		if(!strcmp(issuer_type,"Faculty"))
			fine=0;

		else
		{
			if(mm1==mm)
				fine=dd1-dd;

			else
				fine=((dd1+30-dd)+(mm1-1-mm)*30);

		}
	}

	int get_transaction_id(void)
	{
		return transaction_id;
	}

	void put_info(void)
	{
		cout<<"\n\t Name of the issuer: "<<issuer_name;
		cout<<"\n\t Type of the issuer: "<<issuer_type;
		cout<<"\n\t Book/Journal Info.";
		for(int i=0;i<quantity;i++)
			it[i].put_info();

		cout<<"\n\t Your fine amount is:"<<fine;
	}

};

struct transaction
{
	issue is;
	struct transaction * next;
};


class library
{
	struct transaction *i1;


	public:

		library()
		{
			i1=NULL;
		}
		void issuee(void)
		{
			if(i1==NULL)
			{
				i1= new struct transaction;
				i1->is.get_info();
			}

			else
			{
				struct transaction *i2;
				i2= new struct transaction;
				i2->is.get_info();
				i2->next=i1;
				i1=i2;
			}

		}

		void submission(void)
		{
			int id_no;
			int flag2=0;
			struct transaction *i2;
			int dd1;
			int mm1;
			int yyyy1;

			cout<<"\n\t Please enter the transaction id: ";
			cin>>id_no;

			i2=i1;
			while(i2!=NULL)
			{
				if(i2->is.get_transaction_id()==id_no)
					{
						flag2=1;
						break;
					}
				i2=i2->next;
			}

			if(flag2)
			{
				cout<<"\n\t Enter today's date: ";
				scanf("%d/%d/%d",&dd1,&mm1,&yyyy1);

				i2->is.submit_date(dd1,mm1,yyyy1);
				i2->is.calculate_fine();
				i2->is.put_info();

			}
			else
				cout<<"\n\t Wrong Transaction id";
		}
};

int main()
{
	library l1;
	int choice;
	do
	{
		cout<<"\n\t Please input your choice\n\t1.Issue\n\t2.Submit\n\t3.Exit......";
		cin>>choice;

		switch(choice)
		{
			case 1:
				l1.issuee();
				break;

			case 2:
				l1.submission();
				break;

			case 3:
				exit(0);

			default:
				cout<<"\n\t Wrong Entry";
				break;
		}
		//cin.ignore();

	}while(1);
	return 0;
}
