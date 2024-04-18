#include<iostream>
using namespace std;
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  
        }
    }
    return -1;
}
int binarySearch(int arr[], int left, int right, int element) {
    while (left <= right) {
        int mid = (left +right )/ 2;

        if (arr[mid] == element) {
            return mid;  
        }

        if (arr[mid] < element) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }
    return -1;  
}
int main()
{
	int arr[100];
	int i;
	int size;
	cout<<"Enter size:";
	cin>>size;
	cout<<"Enter elements in ascending:";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"Entered Array: ";
	for(i=0;i<size;i++)
	{
		
		cout<<arr[i]<<",";
	}
	
	int element;
	cout<<"\nEnter element to search:";
	cin>>element;
	int linearPosition = linearSearch(arr, size, element);
	if (linearPosition != -1) {
        cout << "Using Linear Search: Element found at position: " << linearPosition << endl;
    } else {
        cout << "Using Linear Search: Element not found in the array." << endl;
    }
	int binaryPosition = binarySearch(arr, 0, size - 1, element);
	if (binaryPosition != -1) {
        cout << "Using Binary Search: Element found at position: " << binaryPosition << endl;
    } else {
        cout << "Using Binary Search: Element not found in the array." << endl;
    }


}

