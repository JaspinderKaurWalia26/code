
#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    char queue[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
            return true;
        return false;
    }

    bool isEmpty() {
        if (front == -1)
            return true;
        return false;
    }

    void insertElement(char element) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert element." << endl;
            return;
        }
        
        if (front == -1)
            front = 0;
        
        rear = (rear + 1) % MAX;
        queue[rear] = element;
        cout << "Element " << element << " inserted into the queue." << endl;
    }

    void deleteElement() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot delete element." << endl;
            return;
        }
        
        char deletedElement = queue[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        
        cout << "Element " << deletedElement << " deleted from the queue." << endl;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        cout << "Circular Queue: ";
        
        int i = front;
        
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        
        cout << endl;
    }
};

int main() {
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
    CircularQueue cq;

    char choice, element;

    do {
        cout << "Menu:\n";
        cout << "a. Insert an Element\n";
        cout << "b. Delete an Element\n";
        cout << "c. Demonstrate Overflow and Underflow\n";
        cout << "d. Display Queue Status\n";
        cout << "e. Exit\n";
        
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 'a':
                cout << "Enter element to insert: ";
                cin >> element;
                cq.insertElement(element);
                break;

            case 'b':
                cq.deleteElement();
                break;

            case 'c':
                if (cq.isFull()) {
                    cout << "Queue Overflow! Maximum capacity reached." << endl;
                } else if (cq.isEmpty()) {
                    cout << "Queue Underflow! No elements in the queue." << endl;
                } else {
                    cout << "Queue is neither full nor empty." << endl;
                }
                break;

            case 'd':
                cq.displayQueue();
                break;

            case 'e':
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(choice != 'e');

    return 0;
}
