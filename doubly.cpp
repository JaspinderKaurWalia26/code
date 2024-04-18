#include <iostream>
using namespace std;

// Employee structure
struct Employee {
    int SSN;
    string Name;
    string Dept;
    string Designation;
    double Sal;
    long long PhNo;
    Employee* prev;
    Employee* next;
};

// Doubly Linked List class
class DLL {
private:
    Employee* head;
    int count;

public:
    // Constructor
    DLL() {
        head = NULL;
        count = 0;
    }

    // Function to create a new employee node
    Employee* createEmployee(int ssn, string name, string dept, string designation, double sal, long long phno) {
        Employee* newEmployee = new Employee;
        newEmployee->SSN = ssn;
        newEmployee->Name = name;
        newEmployee->Dept = dept;
        newEmployee->Designation = designation;
        newEmployee->Sal = sal;
        newEmployee->PhNo = phno;
        newEmployee->prev = NULL;
        newEmployee->next = NULL;
        return newEmployee;
    }

    // Function to insert an employee at the end of the DLL
    void insertEnd(int ssn, string name, string dept, string designation, double sal, long long phno) {
        Employee* newEmployee = createEmployee(ssn, name, dept, designation, sal, phno);
        if (head == NULL) {
            head = newEmployee;
        } else {
            Employee* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newEmployee;
            newEmployee->prev = current;
        }
        count++;
        cout << "Employee inserted at the end successfully." << endl;
    }

    // Function to display the DLL and count the number of nodes
    void display() {
        if (head == NULL) {
            cout << "DLL is empty." << endl;
            return;
        }

        Employee* current = head;
        cout << "DLL Status:" << endl;
        while (current != NULL) {
            cout << "SSN: " << current->SSN << ", Name: " << current->Name << ", Dept: " << current->Dept
                 << ", Designation: " << current->Designation << ", Salary: " << current->Sal
                 << ", Phone Number: " << current->PhNo << endl;
            current = current->next;
        }
        cout << "Total number of nodes in DLL: " << count << endl;
    }

    // Function to insert an employee at the front of the DLL
    void insertFront(int ssn, string name, string dept, string designation, double sal, long long phno) {
        Employee* newEmployee = createEmployee(ssn, name, dept, designation, sal, phno);
        if (head == NULL) {
            head = newEmployee;
        } else {
            newEmployee->next = head;
            head->prev = newEmployee;
            head = newEmployee;
        }
        count++;
        cout << "Employee inserted at the front successfully." << endl;
    }

    // Function to delete an employee from the end of the DLL
    void deleteEnd() {
        if (head == NULL) {
            cout << "DLL is empty. No employee to delete." << endl;
            return;
        }

        Employee* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            head = NULL;
        }

        delete current;
        count--;
        cout << "Employee deleted from the end successfully." << endl;
    }

    // Function to delete an employee from the front of the DLL
    void deleteFront() {
        if (head == NULL) {
            cout << "DLL is empty. No employee to delete." << endl;
            return;
        }

        Employee* current = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }

        delete current;
        count--;
        cout << "Employee deleted from the front successfully." << endl;
    }
};

int main() {
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
    DLL dll;
    int choice, ssn;
    string name, dept, designation;
    double sal;
    long long phno;

    do {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Insert Employee at the End" << endl;
        cout << "2. Display DLL Status and Count" << endl;
        cout << "3. Insert Employee at the Front" << endl;
        cout << "4. Delete Employee from the End" << endl;
       cout << "5. Delete Employee from the Front" << endl;
        cout << "6. Demonstrate DLL as Double Ended Queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Employee Details:" << endl;
                cout << "SSN: ";
                cin >> ssn;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Dept: ";
                getline(cin, dept);
                cout << "Designation: ";
                getline(cin, designation);
                cout << "Salary: ";
                cin >> sal;
                cout << "Phone Number: ";
                cin >> phno;
                dll.insertEnd(ssn, name, dept, designation, sal, phno);
                break;

            case 2:
                dll.display();
                break;

            case 3:
                cout << "\nEnter Employee Details:" << endl;
                cout << "SSN: ";
                cin >> ssn;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Dept: ";
                getline(cin, dept);
                cout << "Designation: ";
                getline(cin, designation);
                cout << "Salary: ";
                cin >> sal;
                cout << "Phone Number: ";
                cin >> phno;
                dll.insertFront(ssn, name, dept, designation, sal, phno);
                break;

            case 4:
                dll.deleteEnd();
                break;

            case 5:
                dll.deleteFront();
                break;

            case 6:
                // Demonstrate DLL as Double Ended Queue
                cout << "Demonstrating DLL as Double Ended Queue:" << endl;
                cout << "Inserting Employees at the End: " << endl;
                dll.insertEnd(1001, "John", "IT", "Manager", 5000.0, 1234567890);
                dll.insertEnd(1002, "Alice", "HR", "Assistant", 3000.0, 9876543210);
                dll.display();
                cout << "Deleting Employee from the Front: " << endl;
                dll.deleteFront();
                dll.display();
                break;

            case 7:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
