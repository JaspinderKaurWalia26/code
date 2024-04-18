#include<iostream>
using namespace std;
int size;
int arr[40];
bool isCreated = false; // Flag to check if array is created

void create()
{
    cout<<"Enter the size of array:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element for index position:"<<i<<":";
        cin>>arr[i];
    }
    isCreated = true; // Set the flag to true after creating the array
}

void display()
{
    cout<<"The array is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Index position:"<<i<<",Element:"<<arr[i]<<endl;
    }
}

void insertion()
{
    if (isCreated) // Check if array is created
    {
        int element, i, pos;
        cout<<"Enter the position at which you want to insert:";
        cin>>pos;
        cout<<"Enter the element you want to insert:";
        cin>>element;

        if(pos <= size && pos >= 0)
        {
            for(i=size;i>pos;i--)
                arr[i] = arr[i-1];
            
            arr[pos] = element;
            size++; // Increase the size of the array after insertion
            
        }
        else
        {
            cout<<"Invalid position ";
        }
    }
    else
    {
        cout<<"Array not created. Please create the array first."<<endl;
    }
}

void deletion()
{
    if (isCreated) // Check if array is created
    {
        int position2;
        cout<<"Enter the position you want to delete:";
        cin>>position2;
        if (position2 >= 0 && position2 < size)
        {
            for(int i=position2;i<size;i++)
            {
                arr[i] = arr[i+1];
            }
            size--; // Decrease the size of the array after deletion
            
        }
        else
        {
            cout<<"Invalid position ";
        }
    }
    else
    {
        cout<<"Array not created. Please create the array first."<<endl;
    }
}

int main()
{
    int choice;
    while(1)
    { 
        cout<<"Menu"<<endl;
        cout<<"1.Create"<<endl<<"2.Display"<<endl<<"3.Insert"<<endl<<"4.Delete"<<endl<<"5.Exit"<<endl;
        cout<<"Enter choice"<<endl;
    
        cin>>choice;
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertion();
                break;
            case 4:
                deletion();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice";
        }
    }
}
