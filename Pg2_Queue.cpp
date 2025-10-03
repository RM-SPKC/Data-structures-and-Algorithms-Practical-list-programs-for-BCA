#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node*next;
};
class queue
{
public:
    node *front,*rear;
    queue(){ front=nullptr;rear=nullptr;}
    void enqueue();
    void dequeue();
    void peek();
    void display();
};
void queue::enqueue()
{
    int d;
    cout<<"Enter an element : ";
    cin>>d;
    node*n=new node();
    n->data=d;
    if(front==nullptr){
        front=n;
        rear=n;
    }
    else{
        rear->next=n;
        rear=n;
    }
}
void queue::dequeue()
{
    node*t=front;
    if(front==nullptr){
        rear=nullptr;
        cout<<"\n\tEmpty queue\n";
    }
    else{
        cout<<"\n\tRemoved Element : "<<t->data;
        front=t->next;
    }
}
void queue::peek()
{
    if(front==nullptr){
        cout<<"\n\tEmpty queue\n";
    }
    else{
        cout<<"\n\tTop element : "<<front->data;
    }
}
void queue::display()
{
    if(front==nullptr){
        cout<<"\n\tEmpty queue\n";
    }
    else{
        node*t=front;
        cout<<"\n\tFRONT";
        while(t!=NULL){
            cout<<"<-"<<t->data;
            t=t->next;
        }
        cout<<"<-REAR"<<endl;
    }
}
int main()
{
    queue obj;
    int choice;
    cout<<"\t\t\t*****QUEUE USING LINKED LIST******\n\n";
    cout<<"1.Enqueue\n";
    cout<<"2.Dequeue\n";
    cout<<"3.Peek\n";
    cout<<"4.Display\n";
    cout<<"5.Exit\n";
    do{
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            obj.enqueue();
            cout<<" "<<endl;
            break;
        case 2:
            obj.dequeue();
            cout<<" "<<endl;
            break;
        case 3:
            obj.peek();
            cout<<" "<<endl;
            break;
        case 4:
            obj.display();
            cout<<" "<<endl;
            break;
        case 5:
            cout<<"\n\tExit Successfully..\n";
            break;
        default:
            cout<<"\n\tInvalid Choice : Choose Options Between 1-5\n";
            break;
        }
    }while(choice!=5);
    return 0;
}

