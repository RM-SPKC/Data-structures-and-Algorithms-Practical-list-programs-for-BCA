#include<iostream>
using namespace std;

class Array
{
public:
    int range,index;
    int element;
    int arr[100];

    void create ();
    void insert();
    void remove();
    void search();
    void display();
};
void Array::create()
{
    cout<<"Enter the range : ";
    cin>>range;

    for(int i=1;i<=range;i++)
    {
        cout<<"Enter Element "<<i<<" : ";
        cin>>arr[i];
    }
}

void Array::insert()
{
    cout<<"Enter the index : ";
    cin>>index;
    cout<<"Enter an element to insert :";
    cin>>element;

    for(int i=range;i>=index;i--)
        arr[i+1]=arr[i];
    arr[index]=element;
    range++;
}

void Array::remove()
{
     cout<<"Enter an index to Remove Element :";
    cin>>index;

    for(int i=index+1;i<=range;i++)
        arr[i-1]=arr[i];
    range--;

}

void Array::search()
{
    cout<<"Enter an element to search : ";
    cin>>element;
    for(int i=1;i<=range;i++)
    {
       if(element==arr[i]){
            cout<<"\nElement Found"<<endl;
            return ;
        }
    }
    cout<<"\nElement Not Found\n";
}
void Array::display()
{
    cout<<"Array Elements :  ";
    for (int i=1;i<=range;i++)
        cout<<arr[i]<<" ";
    cout<<""<<endl;
}

int main()
{
    int choice;
    Array obj;
        cout<<"\t\t\t*******LIST ADT USING ARRAY******\n\n"<<endl;
        cout<<"1.Create Array "<<endl;
        cout<<"2.Insert Element"<<endl;
        cout<<"3.Remove Element"<<endl;
        cout<<"4.Search An Element"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Exit"<<endl<<endl;
     do{
        cout<<"Enter Your Choice :";
        cin>>choice;

        switch(choice)
        {
            case 1:
                obj.create();
                cout<<""<<endl;
                break;
            case 2:
                obj.insert();
                cout<<""<<endl;
                break;
            case 3:
                obj.remove();
                cout<<""<<endl;
                break;
            case 4:
                obj.search();
                cout<<""<<endl;
                break;
            case 5:
                obj.display();
                cout<<""<<endl;
                break;
            default:
                cout<<"Exit Successfully...."<<endl;
        }
    }while(choice<=5);

    return 0;
}
