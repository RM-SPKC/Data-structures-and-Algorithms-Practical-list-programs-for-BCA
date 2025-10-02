#include<iostream>
using namespace std;
class list
{
public:
	int a[10];
	int n;
	void create();
	void insert();
	void remove();
	void search();
	void display();
};
void list::create()
{
	cout<<"\t\t---CREATE---\n";
	cout<<"Enter the array size:";
	cin>>n;
	cout<<"Enter the elements one by one:";
	for(int i=1;i<=n;i++)
	    cin>>a[i];
}
void list::insert()
{
	cout<<"\t\t---INSERT---\n";
	int d,in;
	cout<<"Enter the new data:";
	cin>>d;
	cout<<"Enter an index to insert new element:";
	cin>>in;
	for(int i=n;i>=in;i--)
	{
	    a[i+1]=a[i];
	}
	a[in]=d;
	n++;
}
void list::remove()
{
	cout<<"\t\t---REMOVE---\n";
	int ind;
	if(n>0)
    {
	cout<<"Enter an index to remove element :";
    cin>>ind;
    for(int i=ind+1;i<=n;i++)
        a[i-1]=a[i];
    n--;
    cout<<"Deleted Successfully"<<endl;
    }
    else
    {
        cout<<"\n\tEmpty List";
    }
}
void list::search()
{
	cout<<"\t\t---SEARCH---\n";
	int k;
	cout<<"Enter the key value:";
	cin>>k;
	for(int i=1;i<=n;i++)
	{
	   if(k==a[i])
	   {
		cout<<"The element found at "<<i<<endl;
		return;
	   }
	}
	cout<<"The element not found.";
}

void list::display()
{
	cout<<"\t\t---DISPLAY---\n";
	if(n>0)
    {
	cout<<"List elements are:";
	for(int i=1;i<=n;i++)
	    cout<<a[i]<<" ";
    }
    else
    {
        cout<<"\n\tEmpty List";
    }
}
int main()
{
	list l;
	int choice;
	cout<<"\t\t\tLIST ADT  USING ARRAY\n";
	cout<<"\t\t\t---------------------\n";
	cout<<"\tChoose the options:\n";
	cout<<"1.Create\n";
	cout<<"2.Insert\n";
	cout<<"3.Remove\n";
	cout<<"4.Search\n";
	cout<<"5.Display\n";
	cout<<"6.Exit\n";
	do
	{
	    cout<<"\n\nEnter the choice:";
	    cin>>choice;
	    cout<<"\n";
	    switch(choice)
	    {
	    case 1:
		    l.create();
		    break;
	    case 2:
		    l.insert();
		    break;
	    case 3:
		    l.remove();
		    break;
	    case 4:
		    l.search();
		    break;
	    case 5:
		    l.display();
	    	break;
	    case 6:
	    	cout<<"Exiting.....\n";
	    	break;
	    default:
	    	cout<<" Enter the Choice between 1-5 "<<endl;
            break;
	    }
	}while(choice!=6);
	return 0;
}
