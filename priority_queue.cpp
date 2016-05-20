//C++ program to implement priority queue
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node{
    int priority;
    int val;
    struct node* next;
};
typedef struct node node_t;
class priority_queue{
private :
    node_t* front;
public:
    priority_queue(){
        front=NULL;
    }
    void insert(int item,int priority){
        node_t* temp,q;
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

    int choice, item, priority;
    priority_queue pq;

    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.insert(item, priority);
            break;
        case 2:
            cout<<"Enter priority : ";
            cin>>priority;
            cout<<endl;
            pq.del(priority);
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong choice\n";
        }
    }while(choice != 4);

    return 0;
}
