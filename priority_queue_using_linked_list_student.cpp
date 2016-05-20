#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
class student{
private:
    string name;
    int roll;
    int marks[8];
    double cgpa;
    string dept;
public:
    static int count;
    void set_gpa();
    student(string inputName,string department,int* mark){
        name=inputName;
        count++;
        roll=count;
        int i=0;
        for(i=0;i<8;i++){
            marks[i]=mark[i];
        }
        dept=department;
        set_gpa();
    }
    double get_gpa(){
        return cgpa;
    }
    string get_name(){
        return name;
    }
    string get_dept(){
        return dept;
    }
    int get_roll(){
        return roll;
    }
    int* get_mark(){
        int mark[8];
        int i=0;
        for(i=0;i<8;i++){
            mark[i]=marks[i];
        }
        return mark;
    }
};
void student::set_gpa(){
        int sum=0;
        int i=0;
        double t;
        for(i=0;i<8;i++){
            t=marks[i];
            t/=10;
            if(t==(int)(t)){
                //do nothing
            }
            else{
                t=(int)(t)+1;
            }
            sum+=t;
        }
        sum/=8;
        cgpa=sum;
}
class priority_queue{
private :
    student* front;
public:
    priority_queue(){
        front=NULL;
    }
    void insert(student s){
        double priority=s.get_gpa();
        student* temp,q;
        temp=new node_t;
        temp->val=item;
        temp->priority=priority;
        if(front==NULL||priority<front->priority){
            temp->next=front;
            front=temp;
        }
        else{
            node_t* q=front;
            while(q->next&&q->next->priority<priority){
                q=q->next;
            }
            temp->next=q->next;
            q->next=temp;
        }
    }
    void del(int priority){
        if(front->priority==priority){
            node_t* q=front;
            front=front->next;
            free(q);
        }
        else{
            node_t* q=front;
            while(q->next->priority!=priority&&q->next){
                q=q->next;
            }
            if(q->next){
                node_t* t=q->next;
                q->next=q->next->next;
                free(t);
            }
        }
    }
    void display(){
        if(front){
            node_t* t=front;
            while(t!=NULL){
                cout<<"["<<t->val<<":"<<t->priority<<"]"<<"->";
                t=t->next;
            }
            cout<<"NULL"<<endl;
        }
        else{
            cout<<"Priority queue is empty."<<endl;
        }
    }
};
int main(void){
    return 0;
}
