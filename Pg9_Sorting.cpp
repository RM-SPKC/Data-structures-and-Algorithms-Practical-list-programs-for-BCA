#include<iostream>
using namespace std;
class sortt
{
public:
    int arr[50], original[50],range;

    void bubblesort();
    void input();
    void display();
    void selection();
    void insertion();
    void radix();
    void reset();
    int getmax();
    void countsort(int exp);
};
void sortt::input()
{
    cout<<"\nEnter the no. of elements : ";
    cin>>range;
    for (int i=0;i<range;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
        original[i]=arr[i];
    }
}
void sortt::display()
{
    for(int i=0;i<range;i++)
    {
        cout<<arr[i]<<"\t";
    }

}
//bubblesort
void sortt::bubblesort()
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
//selection
void sortt::selection()
{
    int i,j,minindex,temp;

    for(int i=0;i<range-1;i++)
    {
        minindex=i;
        for(j = i + 1; j < range; j++) {
        if(arr[j] < arr[minindex])

        {
            minindex=j;
        }}

    swap(arr[i], arr[minindex]);

    }
}
//insertion
void sortt::insertion()
{
    for(int i=1;i<range;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
//radixsort
int sortt::getmax()
{
    int big=0;
    for(int i=0;i<range;i++)
    {
        if(arr[i]>big)
            big=arr[i];
    }
    return big;
}

void sortt::countsort(int exp)
{
    int output[50];
    int i,count[10] = { 0 };

    for (i = 0; i < range; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = range - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < range; i++)
        arr[i] = output[i];
}
void sortt::radix()
{
    int maxx=getmax();
    for (int div=1;maxx/div>0;div*=10)
    {
        countsort(div);
    }
}
//reset array
void sortt:: reset()
 {
    for (int i = 0; i < range; i++) {
        arr[i] = original[i];
    }
}
int main()
{
    sortt s;
    cout<<"\t\t\t********SORTING******** \n";
    s.input();
    int c;
    cout<<"\n\n1.Bubble Sort \n";
    cout<<"2.Selection Sort\n";
    cout<<"3.Insertion Sort\n";
    cout<<"4.Radix Sort\n";
    cout<<"5.Exit\n";
    do{
        cout<<"\n\nEnter your choice : ";
        cin>>c;
        switch(c){
    case 1:
            cout<<"\n\t---BUBBLE SORT--- \n";
            s.reset();
            cout<<"\nArray Elements : ";
            s.display();
            s.bubblesort();
            cout<<"Sorted Array : ";
            s.display();
            break;
        case 2:
            cout<<"\n\t---SELECTION SORT---\n";
            s.reset();
            cout<<"\nArray Elements : ";
            s.display();
            s.selection();
            cout<<"Sorted Array : ";
            s.display();break;
        case 3:
            cout<<"\n\t---INSERTION SORT---\n";
            s.reset();
            cout<<"\nArray Elements : ";
            s.display();s.insertion();
            cout<<"Sorted Array : ";
            s.display();
            break;
        case 4:
            cout<<"\n\t---RADIX SORT---\n";
            s.reset();
            cout<<"\nArray Elements : ";
            s.display();
            s.radix();
            cout<<"Sorted Array : ";
            s.display();
            break;
        case 5:cout<<"\n\tExit Successfully... ";break;
        default:cout<<"\n\tEnter the choice between 1 to 5.";break;
        }
    }while(c!=5);
    return 0;
}




