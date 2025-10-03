#include <iostream>
using namespace std;

class lb_search
{
private:
    int arr[10];
    int range;
public:

    void getinput();
    void display();
    void linear_search();
    void binary_search();
    void bubblesort();
};
void lb_search::getinput()
{
    cout<<"\nEnter the no. of elements : ";
    cin>>range;
    for(int i=0;i<range;i++)
    {
        cout<<"Enter element "<<i<<" : ";
        cin>>arr[i];
    }
}
void lb_search::display()
{
     cout<<"\n\tArray Elements : ";
     for(int i=0;i<range;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void lb_search::linear_search()
{
    int element;

    cout<<"\nEnter an element to search : ";
    cin>>element;
    for(int i=0;i<range;i++)
    {
        if(arr[i]==element)
        {
            cout<<"\n\tElement found"<<endl;
            return;
        }
    }
    cout<<"\n\tElement not found"<<endl;
}
void lb_search::bubblesort()
{
    for(int i=0;i<range;i++)
    {
        for(int j=0;j<range-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
void lb_search::binary_search()
{
    int element,flag=0,low=0,mid,high=range;

    cout<<"\nEnter an element to search :";
    cin>>element;

    while(low<=high)
    {
         mid=(low+high)/2;

        if(arr[mid]==element)
        {
            cout<<"\n\tElement found"<<endl;
            flag=1;
            break;
        }
        else if(element>arr[mid])
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(flag==0)
    cout<<"\n\tElement not found"<<endl;
}
int main()
{
    int choice;
    cout<<"\t\t\t*****LINEAR AND BINARY SEARCH*******\n\n";
    lb_search obj;
    obj.getinput();
    obj.display();
    cout<<"\n\n1. Linear Search";
    cout<<"\n2. Binary Search";
    cout<<"\n3. Exit";
    do{
        cout<<"\n\nEnter your choice :";
        cin>>choice;
        switch(choice){
        case 1:
            obj.linear_search();
            cout<<"  ";
            break;
        case 2:
            obj.bubblesort();
            obj.binary_search();
            cout<<"  ";
            break;
        case 3:
            cout<<"\n\tExit Successfully...\n";
            break;
        default:
            cout<<"\n\tInvalid Choice.Enter the choice between 1-3.\n";
            break;
        }
    }while(choice!=3);
    return 0;
}
