#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

//int count = 1;
using namespace std;
class student{
private :
    string name;
    string dept;
    //int marks[8];
    double gpa;
    int roll;
public :
    friend class priority_queue;
    //friend class node;
    static int count;
    //student(){};
    student(string Name="Unknown",string Dept="Engg. Faculty",/*int* mark*/double GPA=10.0){
        name=Name;
        dept=Dept;
        /*int sum=0;
        for(int i=0;i<8;i++){
            marks[i]=mark[i];
            sum+=marks[i];
        }
        gpa=sum/80;*/
        gpa=GPA;
        count++;
        roll=count;
    }
    void operator =(const student& s){
        name=s.name;
        dept=s.dept;
        gpa=s.gpa;
        roll=s.roll;
    }
    void display(){
        cout<<"The name of the student is : "<<name<<endl;
        cout<<"The department in which "<<name<<" studies is : "<<dept<<endl;
        cout<<name<<"'s gpa is : "<<gpa<<endl;
        cout<<name<<"'s roll no. is : "<<roll<<endl;
    }
    double get_gpa(){
        return gpa;
    }
};
int student::count=0;
/*class node{
private:
    student s;
    double priority;
    node next;
public:
    friend class priority_queue;
    node(){}
    node(const student& person){
        s=person;
        priority=s.gpa;
        next=NULL;
    }
    void operator =(const node& A){
        s=A.s();
        priority=A.priority;
        next=NULL;
    }
};*/
struct node{
    student s;
    double priority;
    node* next;

    node() {
    	s = student();
    	priority = 0;
    	next = NULL;
    }
};
class priority_queue{
private:
      node* front;
public:
      priority_queue(){
          front=NULL;
      }
      void insert(const student& s){
          //node temp(s);
          node* temp = new node();
          node* q = new node();
          temp->s=s;
          temp->priority=(temp->s).get_gpa();
          student::count++;
          //cout<< temp;
          //cout<<(temp==&t);
          if(front==NULL||temp->priority>front->priority){
              temp->next=front;
              front=temp;
          }
          else{
              q=front;
              while(q->next!=NULL && q->next->priority > temp->priority){
                  q=q->next;
              }
              temp->next=q->next;
              q->next=temp;
          }
      }
      void del(double priority){
          node* ptr;
          ptr=front;
          if(ptr==NULL){
             cout<<"Queue is empty"<<endl;
          }
          else{
              if(ptr->priority==priority){
                 front=ptr->next;
              }
              else{
                 node* ptr2;
                 ptr=front;
                 while(ptr->next->priority!=priority && ptr->next!=NULL){
                       ptr2=ptr;
                       ptr=ptr->next;
                 }
                 if(ptr->next){
                    node* t;
                    t=ptr->next;
                    ptr->next=ptr->next->next;
                    free(t);
                    cout<<"priority "<<priority<<" deleted from priority queue"<<endl;
                 }
                 else{
                    cout<<"Key with given priority not found"<<endl;
                 }
              }
          }
      }
      void display(){
          node* ptr;
          ptr=front;
          if(ptr==NULL){
             cout<<"Nothing to display. The queue is empty"<<endl;
          }
          else{
              //cout<<front->priority;
              while(ptr!=NULL){
                   cout<<"Priority : "<<ptr->priority;
                   (ptr->s).display();
                   ptr=ptr->next;
              }
          }
      }
};
int main(void){
    int choice;
    string Name;
    string Dept;
    double GPA;
    double priority;
    priority_queue pq;
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){

        case 1:{
            cout<<"Enter name of student : ";
            cin>>Name;
            cout<<endl;
            cout<<"Enter dept in which the stduent studies : ";
            cin>>Dept;
            cout<<endl;
            cout<<"Enter the student's gpa : ";
            cin>>GPA;
            cout<<endl;
            //node* t;
            student s(Name,Dept,GPA);
            //t->s=s;
            //t->priority=(t->s).get_gpa();
            //delete s;
            //student s(Name,Dept,GPA);
            pq.insert(s);
            //delete s;
            break;
        }
        case 2:{
            cout<<"Enter priority value : ";
            cin>>priority;
            cout<<endl;
            pq.del(priority);
            break;
        }
        case 3:{
            pq.display();
            break;
        }
        case 4:{
            break;
        }
        default :{
            cout<<"Wrong choice.Try again"<<endl;
        }
        }
    }while(choice != 4);

    return 0;
}
