#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
	cout<<"\nSorting algorithms: \n";
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    int bubbleArr[n];
    copy(arr, arr + n, bubbleArr);
    bubbleSort(bubbleArr, n);
    cout << "Bubble Sort: ";
    for (int i = 0; i < n; ++i) {
        cout << bubbleArr[i] << " ";
    }
    cout << endl;

    // Selection Sort
    int selectionArr[n];
    copy(arr, arr + n, selectionArr);
    selectionSort(selectionArr, n);
    cout << "Selection Sort: ";
    for (int i = 0; i < n; ++i) {
  
       cout << selectionArr[i] << " ";
    }
     cout << endl;

    // Insertion Sort
    int insertionArr[n];
    copy(arr, arr + n, insertionArr);
    insertionSort(insertionArr, n);
    cout << "Insertion Sort: ";
    for (int i = 0; i < n; ++i) {
     cout<< insertionArr[i] << " ";
    }
    cout<<endl;

    // Merge Sort
    int mergeArr[n];
    copy(arr, arr + n, mergeArr);
    mergeSort(mergeArr, 0, n - 1);
    cout << "Merge Sort: ";
    for (int i = 0; i < n; ++i) {
       cout << mergeArr[i] << " ";
    }
    cout<<endl;

    // Quick Sort
    int quickArr[n];
    copy(arr, arr + n, quickArr);
    quickSort(quickArr, 0, n - 1);
    cout << "Quick Sort: ";
    for (int i = 0; i < n; ++i) {
        cout << quickArr[i] << " ";
    }
    cout<<endl;

    return 0;
}
