#include <iostream>
using namespace std;

// Structure to represent a student
struct Student {
    string USN;
    string Name;
    string Branch;
    int Sem;
    string PhNo;
    Student* next;
};

// Class for Singly Linked List operations
class LinkedList {
private:
    Student* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Function to create a new student node
    Student* createStudent(string USN, string Name, string Branch, int Sem, string PhNo) {
        Student* newStudent = new Student;
        newStudent->USN = USN;
        newStudent->Name = Name;
        newStudent->Branch = Branch;
        newStudent->Sem = Sem;
        newStudent->PhNo = PhNo;
        newStudent->next = NULL;
        return newStudent;
    }

    // Function to insert a student at the front of the SLL
    void insertFront(string USN, string Name, string Branch, int Sem, string PhNo) {
        Student* newStudent = createStudent(USN, Name, Branch, Sem, PhNo);
        if (head == NULL) {
            head = newStudent;
        } else {
            newStudent->next = head;
            head = newStudent;
        }
        cout << "Student inserted at the front successfully." << endl;
    }

    // Function to insert a student at the end of the SLL
    void insertEnd(string USN, string Name, string Branch, int Sem, string PhNo) {
        Student* newStudent = createStudent(USN, Name, Branch, Sem, PhNo);
        if (head == NULL) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student inserted at the end successfully." << endl;
    }

    // Function to delete the first student from the SLL (stack operation)
    void deleteFront() {
        if (head == NULL) {
            cout << "No students found in the list." << endl;
        } else {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted from the front successfully." << endl;
        }
    }

    // Function to delete the last student from the SLL
    void deleteEnd() {
        if (head == NULL) {
            cout << "No students found in the list." << endl;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Student deleted from the end successfully." << endl;
        } else {
            Student* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            cout << "Student deleted from the end successfully." << endl;
        }
    }

    // Function to display the SLL and count the number of nodes
    void display() {
        if (head == NULL) {
            cout << "No students found in the list." << endl;
        } else {
            Student* temp = head;
            int count = 0;
            cout << "Singly Linked List of Students:" << endl;
            cout << "--------------------------------" << endl;
            while (temp != NULL) {
                cout << "USN: " << temp->USN << endl;
                cout << "Name: " << temp->Name << endl;
                cout << "Branch: " << temp->Branch << endl;
                cout << "Semester: " << temp->Sem << endl;
                cout << "Phone Number: " << temp->PhNo << endl;
                cout << "--------------------------------" << endl;
                temp = temp->next;
                count++;
            }
            cout << "Total number of students: " << count << endl;
        }
    }
};

int main() {
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
    LinkedList studentList;
    int choice;
    string USN, Name, Branch, PhNo;
    int Sem;

    do {
        cout << "Menu" << endl;
        cout << "1. Insert a student at the front" << endl;
        cout << "2. Insert a student at the end" << endl;
        cout << "3. Delete a student from the front" << endl;
        cout << "4. Delete a student from the end" << endl;
        cout << "5. Display the list and count the number of students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter USN: ";
                cin >> USN;
                cout << "Enter Name: ";
                cin >> Name;
                cout << "Enter Branch: ";
                cin >> Branch;
                cout << "Enter Semester: ";
                cin >> Sem;
                cout << "Enter Phone Number: ";
                cin >> PhNo;
                studentList.insertFront(USN, Name, Branch, Sem, PhNo);
                break;
            case 2:
                cout << "Enter USN: ";
                cin >> USN;
                cout << "Enter Name: ";
                cin >> Name;
                cout << "Enter Branch: ";
                cin >> Branch;
                cout << "Enter Semester: ";
                cin >> Sem;
                cout << "Enter Phone Number: ";
                cin >> PhNo;
                studentList.insertEnd(USN, Name, Branch, Sem, PhNo);
                break;
            case 3:
                studentList.deleteFront();
                break;
            case 4:
                studentList.deleteEnd();
                break;
            case 5:
                studentList.display();
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
