#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node*next;
};
class stack
{
    public:
        node*top;
        stack()
        {
            top =nullptr;
        }
        void push();
        void pop();
        void peek();
        void display();
};
void stack::push()
{
    int d;
    cout<<"Enter an element :";
    cin>>d;
    node*n=new node();
    n->data=d;
    n->next=top;
    top=n;
}
void stack::pop()
{
    node*t=top;
    if(top==nullptr)
        cout<<"\n\tEmpty Stack\n";
    else{
        cout<<"\n\tPopped Element :"<<t->data;
        top=t->next;
        delete t;
    }
}
void stack::peek()
{
    node*t=top;
    if(top==nullptr)
        cout<<"\n\tEmpty Stack\n";
    else{
        cout<<"\n\tTop Element :"<<t->data;
    }
}
void stack::display()
{
     if(top==nullptr)
        cout<<"\n\tEmpty Stack\n";
    else{
        node*t=top;
        cout<<"\n**Stack Elements**\n\n";
        while(t!=NULL){
              cout<<"\t|  "<<t->data<<"   |\n";
              cout<<"\t---------\n";
              t=t->next;
            }
        }
}
int main()
{
    stack obj;
    int choice;
    cout<<"\t\t*****STACK USING LINKED LIST******\n\n";
    cout<<"1.push\n";
    cout<<"2.Pop\n";
    cout<<"3.Peek\n";
    cout<<"4.Display\n";
    cout<<"5.Exit\n";
    do{
        cout<<"\nEnter the choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            obj.push();
            cout<<" "<<endl;
            break;
        case 2:
            obj.pop();
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
            cout<<"\n\tExit Successfully...\n";
            break;
        default:
            cout<<"\n\tInvalid Choice : Choose Options Between 1-5\n";
            break;
        }
    }while(choice!=5);
    return 0;
}


