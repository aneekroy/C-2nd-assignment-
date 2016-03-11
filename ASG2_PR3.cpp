/*
 * PROGRAM 3:  Implement a Priority Queue with linked lists. Provide functionalities exactly like the template provided in C++.
With Respect ot student class.

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define max_subject  5

using namespace std;

class priority;//forward declaration of class priority
class student{
                 	
	        int  roll; // to hold roll number of student
	        int  marks[max_subject]; //data member to hold marks obtained
	        char name[100];//data member to hold name
		double cgpa;//data member to hold cgpa(priority)
		student *link;//link to next student node
	public:
		    	
		friend	class priority;//Making Priority Class friend of Student to Access pvt data members

		/*function for student details entry */
		  student* input(int size){
		    int c;
		    student * s=new student;
		    cout<<"\n\tENTER NAME OF STUDENT : ";
		    cin.ignore();
	       	    cin.getline(s->name,100);
		
		    cout<<"\n\tENTER ROLL NO OF STUDENT :";
		    cin>>c;
		    if(c<0)
			cout<<"\n\t WRONG ROLL NUMBER ENTERED !!";
	            else{
			s->roll=c;
			//cout<<"\tROLL NO ASSIGNED IS : "<<s->roll<<endl;
			}
		 
		    double sum=0;
		    cout<<"\n\tENTER MARKS OF STUDENT:\n";
			for(int i = 0; i < max_subject; ++i){
			cout<<"\n\tSubject "<<(i+1)<<" : ";
				cin>>s->marks[i] ;
				sum+=s->marks[i];//finding the sum of all the marks
				
			}
			
			s->cgpa=sum/(max_subject*10);   //calculating the cgpa of each student
			
			 s->link=NULL;//Initialising link to Null    	
	
			return s;//Returning Student object
		}
			
			
		/*to display  student details */
			void display(){
				cin.ignore();
		      		cout   << "\tROLL NO : " << roll << endl;
			     	for(int i = 0; i <max_subject; ++i){
		
			       		 cout <<"\tSUBJECT NO "<<i+1<<" : " <<marks[i] << " "<<endl;
		           		 cout << endl<<endl;
			  	  }
			
	       			 cout<<"\n\tCGPA : "<<cgpa<<endl;
           
         		 }


};//student class ends	

 /* Class Priority Queue*/
 
class priority{
    private:
      student   *front;//points to front of queue
      student   *rear;//points to rear of queue
   
    public:
	/*user defined constructor to initialize the data members of the class priority*/
        priority() {
            front = NULL;
             rear =NULL; 
        }
        
        /*to get the front of the queue*/ 
         student *obtain_front_queue(){
         	return front;
	}
          /*to get the rear of the queue*/ 
         student *obtain_rear_queue(){
         	return rear;
	}
         
         
         /*member function to push cgpa to the queue*/
        void enqueue(student *t){
            student *q, *previous;
           
		
            if (front == NULL ){  //to check if the queue  is empty or not
                front=t;
                rear=t;
           
            }
            
            /*more than one element but element to be entered has highest priority*/
            else if(t-> cgpa> front->cgpa){
                t->link = front;
                front = t;
         
            }
            else{ 
                q  = front; 
                previous=q;
                while ((q->link != NULL) && (q->cgpa>= t->cgpa)){//Searching for correct element position in Queue
				  
					previous=q;
				    q=q->link;
		}
			
               if(q->cgpa< t->cgpa){
				
                t->link = q;
                previous->link=t;
		}	
		/*to check if it is end of queue*/		
		else if(q->link==NULL){
			q->link=t;
			t->link=NULL;
			rear=t;
				
		}    
				
           } 
		   
      }
      
      
   /*function to take out an element  from queue */  
	student* dequeue(){
       		 student *temp;
       		 temp=new student;
        	 student *q=new student;
        	 student *temp2=new student;
       		 if( rear == NULL ){//to check if the queue is empty or not
             
			 cout<<"\n\tQueue Underflow\n";
			 return NULL;
		}		 
         	else if( front!= NULL&&front==rear){//there is only one node
      			 temp2 = rear;
           		 temp->cgpa  = temp2->cgpa;
           		 strcpy(temp->name,temp2->name);
         		 for(int i=0;i<max_subject;i++)
       			    temp->marks[i]=temp2->marks[i];
           		 temp->roll=temp2->roll;
                      	 front = NULL;
           		 rear = NULL;
           		 delete temp2;;
            
            		return temp;
    		}
   		 else{//there are more than one node
      		        temp2 = rear;
      		        q->cgpa  = temp2->cgpa;
      		        strcpy(temp->name,temp2->name);
        	        for(int i=0;i<max_subject;i++)
        		   q->marks[i]=temp2->marks[i];
         
           		q->roll=temp2->roll;
           	        temp = front;
            		while (temp->link->link != NULL)
            			  temp=temp->link;
            
           		 temp->link=NULL;
            		 rear=temp;
            		 delete temp2;
            		 return q;
         
    		}
  }
      
      /* function to check if queue is empty  or not*/
   bool isEmpty(){
   	if(front==NULL&&rear==NULL)
   	 return true;
   	 else
   	  return false;
   }
   	
   /*to display the queue(priority)*/
   void display(){
            student *ptr;
            ptr = front;
int sp=10-strlen(ptr->name);
            if (front == NULL)
                cout<<"\t\tQUEUE IS EMPTY\n";
            else{	
		cout<<"\n\tBATCH IS :\n";
                cout<<"NAME                 ROLL NO                  CGPA     \n";
			    while(ptr != NULL){
					sp=25-strlen(ptr->name);
                    			cout<<ptr->name;
					while(sp--)
						printf(" ");
					cout<<ptr->roll<<"\t\t\t"<<ptr->cgpa<<endl;
                 		        ptr = ptr->link;
                	    }
            }
   }
        
/*function to return the size of the queue at any instant*/      
  int size(){
        int s=0;
        student *ptr;
        ptr = front;
        while(ptr != NULL)//to count the no of elements untill null occurs
         s++;
         return s;
  }
        
        
  };//class priority ends
	
/*	MAIN FUNCTION*/
int main(void){
    int choice=1, item, prior;//variable decleration
    priority q; 
    student *t,p;
    int size=0;
    cout<<"\t\t STUDENT OPTIONS \n";
	/*MENU DRIVEN OPTIONS*/
    while(choice>0&&choice<5){
   	printf("\n\n**************MAIN MENU*********************\n");
    	cout<<"\n\t1.  Enter a student to the batch\n";
        cout<<"\t2.  Remove Student from the batch\n";
        cout<<"\t3.  Display total students in batch\n";
        cout<<"\t4.  Print the Number of Students in Batch\n";
        cout<<"\t5.  Exit Main Menu \n\n";
        cout<<"\n\t\tEnter your choice :"; 
        cin>>choice;
        if(choice==5){
		printf("\n\tExiting !!!\n");
		break;
		}
	else{
        	switch(choice){
       	
			 case 1:t=p.input(size);  //adding to the queue
            			q.enqueue(t);
            			size++;
				break;
      			  case 2:t=q.dequeue();  //removing from the queue
          			 if(t==NULL)
            				 break;
            			 size--;
            			 cout<<"\n\tThe Deleted Student Details are :"<<endl;
           			 (*t).display();      //display the elements of the queue
            		          break;
        		case 3:cout<<"\n\tThe Student(s) in batch are : \n"<<endl;
            		       q.display();
            		       break;
        		case 4:if(q.isEmpty())//to check if queue is empty or not
                  	       cout<<"\n\tThere are NO Students\n" ;
                 	       else
                 	       cout<<"\n\tTotal Number of Studentsin batch are :" << size <<endl;
           		       break;
        		default :cout<<"\n\t WRONG CHOICE!! \n";
        	}//End of switch case
    }//end of else
  }//end of while
return 0;
} //main() function ends
