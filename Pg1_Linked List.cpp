#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node*next;

    node(int d)
    {
        data=d;
        next=nullptr;
    }
};
class linkedlist
{
public:
    node*head;

    linkedlist()
    {
        head=nullptr;
    }
    void insertnode();
    void deletenode();
    void searchh();
    void display();
};
void linkedlist::insertnode()
{
    int element,pos,i=1;

    cout<<"Enter the data : ";
    cin>>element;
    cout<<"Enter the position: ";
    cin>>pos;

    node*n=new node(element);
    node*t=head;
    if(pos==1)
    {
        n->next=head;
        head=n;
    }
    else{
            while(t->next!=nullptr && i<pos-1)
            {
                t=t->next;
                i++;
            }
            n->next=t->next;
            t->next=n;
    }
}
void linkedlist::deletenode()
{
    int pos,i=1;
    node*t=head;
    if(head==NULL){
        cout<<"Empty List"<<endl;
    }
    else{
        cout<<"Enter the position to delete :";
        cin>>pos;

        if(t->next==nullptr){// only one node
           head=nullptr;
           cout<<"\n\tDeleted Successfully"<<endl;
        }
        else if(pos==1){
            head=t->next;//delete at begining
            cout<<"\n\tDeleted Successfully"<<endl;
        }
        else{
            while(t->next!=nullptr && i<pos-1)
            {
                t=t->next;
                i++;
            }
            t->next=t->next->next;
            cout<<"\n\tDeleted Successfully"<<endl;
        }
    }
}
void linkedlist::searchh()
{
    if(head==nullptr)
    {
        cout<<"\n\tEmpty List\n";
    }
    else{
        int k,pos=1;;
        cout<<"Enter the key to search :";
        cin>>k;
        node*t=head;
        while(t!=nullptr)
        {
            if(t->data==k)
            {
                cout<<"\n\tThe key "<<k<<" is found at position "<<pos<<endl;
                return;
            }
            t=t->next;
            pos++;
        }
        cout<<"\n\tThe key is not found.\n";
    }
}
void linkedlist::display()
{
    if(head==nullptr)
    {
        cout<<"\n\tEmpty List\n";
    }
    else{
        node*t=head;
        cout<<"\n\t\tHEAD->";
        while(t!=nullptr){
            cout<<t->data<<"->";
            t=t->next;
        }
        cout<<"NULL"<<endl;
    }

}

int main()
{
    int choice;
    linkedlist obj;
        cout<<"\t\t\t*******LIST ADT USING LINKED LIST******\n\n"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl<<endl;
     do{
        cout<<"Enter Your Choice :";
        cin>>choice;

        switch(choice)
        {
            case 1:
                obj.insertnode();
                cout<<""<<endl;
                break;
            case 2:
                obj.deletenode();
                cout<<""<<endl;
                break;
            case 3:
                obj.searchh();
                cout<<""<<endl;
                break;
            case 4:
                obj.display();
                cout<<""<<endl;
                break;
            case 5:
                cout<<"Exiting...."<<endl;
                break;
            default:
                cout<<" Enter the Choice between 1-5 "<<endl;
                break;
        }
    }while(choice!=5);

    return 0;
}

