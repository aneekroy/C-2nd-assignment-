#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <limits>
#include <ctime>
#define maxResourceLimit 5
using namespace std;
int f1=0,f2=0;
void fileRead(string file){
        ifstream in;
     	in.open(file.c_str());
	string line;
	if(in.is_open()){
		while(getline(in, line))
				cout << line << endl;
			in.close();
		}

	else
	 cout<<"\n\n\tCannot Open File!!"<<endl;

 }


  void append(string file, string record) {
		 ofstream os;
     	 os.open(file.c_str(),ios::app);
			os<< record << endl;
			os.close();
	}


   void replace(string file, int number, string record, bool check) {//true for repace false for erase
			ifstream in;
     	    in.open(file.c_str());
			 ofstream os;
     	     os.open("temp.txt",ios::out);
			string line;
			for(int i = 0; i < number; ++i) {
				getline(in, line);
				os << line << endl;
			}
			getline(in, line);
			if(check == true)
				os << record << endl;
			while(getline(in, line))
				os << line << endl;
			in.close();
			os.close();
			remove(file.c_str());
			rename("temp.txt",file.c_str());
		}
 class CLIENT{
    int maxLimit; // data member to store maximum issue limit
    double fine; // member to store fine incurred on late submission

   protected :
   	int card_no; // member to store faculty/student library card no
    int issues;  //	member to store no of issues made

   public:
    CLIENT(int mx = 2, int fn =0, int n = -1,int is = 0){
   	  maxLimit=mx;
   	  fine = fn;
   	  card_no=n;
   	  issues = 0;
   	  if(card_no == -1){
   	  srand(clock());
		 card_no=rand()%1000;
  	   }
    }

    //getter function for card number
     int getCardNo(){
    	return card_no;
	 }

    //member function to find student or faculty and return number of issues
    int Enquiry( string file,int id,bool state){
        ifstream in;
     	in.open(file.c_str());
    	int flag = 0;int i = 0;
		if(in.is_open()){
    		string line;
    		issues = 0;
    		while(getline(in,line)){

    		    istringstream ss(line);
    			int copy;
    			ss>>copy;
    			if(copy == id){
    			    ss>>issues;
    				flag=1;
					break;
				}
				i++;
    	    }

        }

        else {
		cout<<"\n\n\tFile Not Open!!\n"; return -1;}
        if(!flag){
		 cout<<"\n\n\tCard No Invalid!!\n";return -1;}
	    in.close();
        return i;
    }


	//member function to log issue or return

    void Log(string file,string record,bool state){  //state 1 for issue, 0 for return
       	f1=0;int flag=0;

		   stringstream ss(record);

		int query, line;
			ss >> query;
			if(!state)
			 flag=1;
			 else{

		    string copy;
		    copy="Admin_"+file;
		   // cout<<copy;
		     ifstream in;

            	in.open(copy.c_str());
			if(in.is_open()){

    		string line;
    		issues = 0;
    		while(getline(in,line)){

    		    istringstream s(line);
    			int copy;
    			s>>copy;
    			if(copy == query){

				    s>>issues;
    			    if(issues==0&&state==true){
				//	cout<<"H\n";
					flag=2;issues++;}

    				else flag=1;
					break;
				}

    	    }

        }

       else {
		cout<<"\n\n\tFile Not Open!!\n"; return ;}
}
		if(flag==1){

			line = Enquiry(file,query,state);
			if(line==-1){
				cout<<"\n\n\tInvalid Card No";return;
			}
			f1=1;
			if(state)
			  issues++;
		    else issues--;

			if((issues < 0) || (issues > maxLimit))
				{cout<<"\n\n\tExceeded library limit.\n";
				}
			else if(issues == 0)
				 replace(file, line, recordIt(), false);// true for replace false for erase
			else
				replace(file, line, recordIt(), true);

		}

		else if(flag==2)
		    {
			  append(file,recordIt());f1=1;}
		     else if(flag==0)
		      cout<<"\n\n\tStudent/Faculty not enrolled in admnil log.";
		      else
		       cout<<"\n\n\tInvalid card or book no\n";
}
		//member function to record transaction of student or faculty
		string recordIt() {
			stringstream ss;
			ss << card_no << "\t" << issues;
			return ss.str();
		}

		//getter function for fine
		int getFine() {
			return fine;
		}

 };



	//class to store and manipulate STUDENT values
	class STUDENT : public  CLIENT{
		char name[100];
		char dept[100];

	public:
		//constructor to initialize data members and validate class invariants
	STUDENT(int id=-1, int is=0) : CLIENT(STUDENT::max, STUDENT::fine, id, is) {
	}
		static const int max = 2; //<member to hold maximum issue limit for student
		static const int fine = 1; //<member to hold fine applicable for all student

		//member function for new entry to student log
		 void new_input() {
			int card;
			cout << "\n\tEnter Name: ";
			cin.ignore();
			cin.getline(name,100);

			cout << "\n\tEnter Department: ";
			cin.ignore();
			cin.getline(dept,100);

			card_no+=60000;
			string line;
		    stringstream ss;
			ss<<card_no<<"\t"<<issues<<"\t"<<name<<"\t"<<dept;
			line=ss.str();
			cout<<"\n\tCard No "<<card_no<<" has been added to the Student log."<<endl;
			append("Admin_Student.txt",line);
		}

		//member function to input a journal
		static STUDENT* input(bool state) {
			int card;
			cout << "\n\tEnter card number: ";
			cin>>card;
			return new STUDENT(card);
		}


 };





 //class to store and manipulate FACULTY values
 class FACULTY : public CLIENT {

		char name[100];
	public:
		//constructor to initialize data members and validate class invariants
	FACULTY(int id=-1, int is=0) : CLIENT(FACULTY::max, FACULTY::fine, id, is) {}
		static const int max = 10; ///<member to hold maximum issue limit for all faculty
		static const int fine = 0; ///<member to hold fine applicable for all faculty

		//member function to make an entry to Faculty log
		 void new_input() {
			int card;
			cout << "\n\tEnter Name: ";
			cin.ignore();
			cin.getline(name,100);

			card_no+=90000;
			string line;
		    stringstream ss;
			ss<<card_no<<"\t"<<issues<<"\t"<<name;
			line=ss.str();
			cout<<"\n\tCard No "<<card_no<<" has been added to the Faculty log."<<endl;
			append("Admin_Faculty.txt",line);
		}

		///member function to input a journal
		static FACULTY* input(bool state) {
			int card;
			cout << "\n\n\tEnter Card number: ";
			cin>>card;
			return new FACULTY(card);
		}

	};



	class RESOURCE{


		protected:
		int ID; //<member to hold ID of books and journals
		time_t issue_time; //<member to hold time of issue
	    char issued[100];
	    int count;
	public:
		//constructor to initialize data members and validate class invariants
		RESOURCE(int id=-1)  {
		ID = id;
        issue_time = time(0);
			strcpy(issued , ctime(&issue_time));
			count=maxResourceLimit;
		}


		//getter function for ID
		int getID() {
			return ID;
		}

		//member function to find book or journal and return period of issue
		int issuePeriod(string file, int query)  {
			ifstream in;
     	    in.open(file.c_str());
			int match;
			time_t t;int tmp;
			string line;int flag=0;
			while(getline(in, line)) {
				istringstream stream(line);
				stream >> match;
				if(match == query) {
					stream>>tmp;
					stream >> t ;
					in.close();
					flag=1;
					return time(0) -t;
				}
			}
			if(!flag)cout<<"\n\n\tInvalid Book No.\n";
			in.close();
			return 0;
		}


		int Enquiry( string file,int id,bool state){
         ifstream in;
      	 in.open(file.c_str());
    	 int flag = 0;int i = 0;
		 if(in.is_open()){
    		string line;
    		count = 0;
    		while(getline(in,line)){

    		    istringstream ss(line);
    			int copy;
    			ss>>copy;
    			if(copy == id){
    			    ss>>count;
    				flag=1;
					break;	return i;
				}
				i++;
    	    }

        }

        else {
		cout<<"\n\n\tFile Not Open!!\n"; return -1;}
        if(!flag){
		 cout<<"\n\n\tCard No Invalid!!\n";return -1;}
	    in.close();
        return i;
    }



	 void Log(string file,string record,bool state){  //state 1 for issue, 0 for return

	   	f2=0;int flag=0;
       	 stringstream ss(record);
		int query, line;
			ss >> query;
       if(!state)
       {
        flag=1;
	   }

	   else{

	   	string copy;
		    copy="Admin_"+file;
		     ifstream in;
            	in.open(copy.c_str());
			if(in.is_open()){
    		string line;

    		while(getline(in,line)){

    		    istringstream s(line);
    			int copy;
    			s>>copy;
    			if(copy == query){
    			    s>>count;
    			    if(count==maxResourceLimit){
					flag=2;count--;}
    				else flag=1;
					break;
				}

    	    }}

        else {
		cout<<"\n\n\tFile Not Open!!\n"; return ;}
	}
		  if(flag==1){

			line = Enquiry(file,query,state);
			if(line==-1){
				cout<<"\n\n\tInvalid Book No";return;
			}
			f2=1;
			if(state)
			  count--;
		    else count++;

			if((count < 0))
				{cout<<"\n\n\tExceeded library limit.\n";
				count++;
				}
			else if(count == maxResourceLimit)
				 replace(file, line, recordIt(), false);// true for replace false for erase
			else

					replace(file, line, recordIt(), true);
	}


	else if(flag==2)
	{
	  append(file,recordIt());f2=1;}
		     else if(flag==0)
		      cout<<"\n\n\tStudent not enrolled in admin log.";
	          else
		       cout<<"\n\n\tInvalid card or book no\n";
		}
       	string recordIt() {
			stringstream ss;
			ss << ID << "\t" <<count<<"\t"<< issue_time << "\t" <<issued;
			return ss.str();
		}

 };





 //class to store and manipulate BOOK values
class BOOK : public RESOURCE {
	char author[100], //member to hold author of book
			title[100]; //member to hold title of book

	public:
	//constructor to initialize data members and validate class invariants

	BOOK(int id=-1, char* aut=" ", char* tit=" "):
		RESOURCE(id) {
	strcpy(author,aut);
	strcpy(title,tit);
	}


		//member function to record transaction of book
		string a_recordIt()  {
			stringstream ss;
			ss << ID << "\t" << issue_time << "\t" <<issued<<"\t"<< author << "\t" << title;
			return ss.str();
		}

		//member function to input a book
		 void  new_input() {
			                    cout << "\n\n\tEnter book title: ";

								cin.ignore();
								cin.getline(title,100);
								cout << "\n\n\tEnter book author: ";
							 	cin.ignore();
								 cin.getline(author,100);
								srand(clock());
								ID = rand()%1000;
								ID+=40000;
								cout << "\n\n\tBook ID  " << ID <<" has been added to the Book Log"<< endl;
							    append("Admin_Books.txt",recordIt());

			}

	//member function to input a book
	static BOOK* input(bool state) {
			char title[100],author[100];
			int ID;
			if(state) {
			  cout << "\n\n\tEnter book title: ";
			  cin.ignore();
			  cin.getline(title,100);

			  cout << "\n\n\tEnter book author: ";
			  cin.ignore();
			  cin.getline(author,100);
			  cout<<"\n\n\tEnter ID ";
			  cin>>ID;
			  return new BOOK(ID, author, title);}
		    else{
					cout << "Enter book ID: ";
							cin>>ID;
							return new BOOK(ID);
			}
		}

};


	//class to store and manipulate JOURNAL values
    class JOURNAL : public RESOURCE {
	char author[100], //member to hold author of journal
			title[100]; //member to hold title of journal

	int issue, //<member to hold issue number of journal
		volume; //<member to hold volume number of journal



	public:
	//constructor to initialize data members and validate class invariants
	JOURNAL(int id=-1, char* aut=" ", char* tit=" ",int is=0,int vol=0):
		RESOURCE(id) {
	strcpy(author,aut);
	strcpy(title,tit);
    issue=is;volume=vol;
	}

	//member function to record transaction of journal
		string a_recordIt()  {
			stringstream ss;
			ss << ID << "\t" << issue_time <<"\t"<<issued<< "\t" << author << "\t" << title
				<< "\t" << volume << "\t" << issue;
			return ss.str();
		}


		//member function to input a journal
		 void new_input() {
				cout << "\n\n\tEnter journal title: ";
								cin.getline(title,100);
								cout << "\n\n\tEnter journal author: ";
								cin.getline(author,100);
								cout << "\n\n\tEnter issue number: ";
                                cin>>issue;
								cout << "\n\n\tEnter volume number: ";
								cin>>volume;
								srand(clock());
								ID = rand()%1000;
								ID+=70000;
								cout << "\n\n\tJournal ID  " << ID <<" has been added to the journal log"<< endl;
								append("Admin_Journals.txt",recordIt());

			}

		static JOURNAL* input(bool state) {
			char title[100], author[100];
			int issue, volume, ID;
		//	JOURNAL journal;
			if(state) {
			cout << "\n\n\tEnter journal title: ";
			cin.getline(title,100);
			cout << "\n\n\tEnter journal author: ";
            cin.getline(author,100);
		    cout << "\n\n\tEnter issue number: ";
            cin>>issue;
			cout << "\n\n\tEnter volume number: ";
			cin>>volume;
			cout << "\n\n\\tEnter Journal id : ";
			cin>>ID;
			return new JOURNAL(ID, author, title, issue, volume);
		   }
				else{
					cout << "\n\n\\tEnter Journal id : ";
			            cin>>ID;
								return new JOURNAL(ID);
			}
	}
		};


 class TRANSACTION{
	char transaction_time[100];
	public:
		TRANSACTION(){
			time_t t =time(0);
			strcpy(transaction_time,ctime(&t));

		}
	void recordTransaction(string line){
	append("Transaction.txt",line);
}

	//helper function to provide issue and return slips for student and faculty
   void slip(string filenames[], bool state) { //state 1 for issue 0 for return
	  int c, line;
	 cout << "\n\n\t<1> Request student book slip" << endl
		  << "\n\n\t<2> Request faculty book slip" << endl
		  << "\n\n\t<3> Request faculty journal slip" << endl
		  << endl << "\n\tEnter choice: ";

	cin>>c;
	RESOURCE *paper;
	CLIENT *people;
	int query;
	switch(c) {
		case 1:	paper = BOOK::input(state);
				people = STUDENT::input(state);
				break;

		case 2:	paper = BOOK::input(state);
				people = FACULTY::input(state);
				break;
		case 3:	paper = JOURNAL::input(state);
				people = FACULTY::input(state);
				break;
		default: cout << "invalid operation code" << endl;
	}
	if(c>1)c++;
	people->Log(filenames[2 + (c - 1) / 2], people->recordIt(), state);
//	cout<<"fi "<<f1<<endl;
	if(f1==1)
	paper->Log(filenames[(c - 1) % 2], paper->recordIt(), state);
	if(state == false)
		cout << "\n\n\tFine due : Rs " << (people->getFine() * paper->issuePeriod(filenames[(c - 1) % 2], paper->getID()) / (24 * 3600 * 1000));
	cout << endl;
	stringstream ss;string l;
	ss<<people->getCardNo()<<"\t"<<paper->getID()<<"\t"<<	transaction_time;
	l=ss.str();
	if(f1==1&&f2==1)
	recordTransaction(l);

}



};

 class ADMINISTRATION {
	BOOK book;
	JOURNAL journal;
	STUDENT student;
	FACULTY faculty;

	public:

	void admin_desk(){
	 cout << "\n\n\t<1> Add new Student to the admin Log " << endl
		  << "\n\n\t<2> Add new Faculty to the admin Log" << endl
		  << "\n\n\t<3> Add new Book to the admin Log" << endl
          << "\n\n\t<3> Add new Journal to the admin Log" << endl
		  << endl << "\n\tEnter choice: ";
		int c;
		cin>>c;
		switch(c){
			case 1: student.new_input();
			        break;
			case 2: faculty.new_input();
			        break;
			case 3: book.new_input();
			        break;
			case 4: journal.new_input();
			        break;
			default: cout<<"\n\n\tWrong Input\n";
		}


	}
};

  int main()
{
int ch,c; ADMINISTRATION admin;TRANSACTION t;
	string filenames[] = {"Books.txt", "Journals.txt", "Student.txt", "Faculty.txt","Transaction.txt"};

      do{
      	 cout<<"\n\t====================== MAIN MENU =======================\n";
	 cout<< "\n\n\t<0> EXIT" << endl
			<< "\n\n\t<1> MAKE AN ISSUE" << endl
			<< "\n\n\t<2> MAKE A RETURN" << endl
			<< "\n\n\t<3> VIEW LOG" << endl
			<< "\n\n\t<4> ADMINISTRATION WORK"<<endl
			<< "\n\n\tEnter Choice ";
		  cin>>c;
      	switch(c) {
				case 0: cout << "\n\n\tTerminating program" << endl; break;
				case 1:	t.slip(filenames, true); break;
				case 2: t.slip(filenames, false); break;
				case 3: cout << "\n\n\t<1> View book log" << endl
							 << "\n\n\t<2> View journal log" << endl
							 << "\n\n\t<3> View student log" << endl
							 << "\n\n\t<4> View faculty log" << endl
							 << "\n\n\t<5> View Transaction log" << endl
			          		 << "\n\n\tEnter Choice ";

						cin>>ch;
						if((ch > 0) && (c < 6)) {
							switch(c) {
								case 1: cout << "Book No\tCount\tTime_t\tIssue date" << endl; break;
								case 2: cout << "Journal No\tCount\tTime_t\tIssue date" << endl; break;
								case 3: cout << "Card No\tIssues" << endl; break;
								case 4: cout << "Card no\tIssues" << endl; break;
								case 5: cout << "Card No\tBook/Journal Id\tTransaction time"<<endl;
							}
						     fileRead(filenames[c - 1]);
						}
						break;

						case 4 :admin.admin_desk();
						         break;
				default: cout << "invalid operation code" << endl;
			}

	  }while(c);


 }

