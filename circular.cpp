#include <iostream>
using namespace std;


struct Node {
    int coeff;
    int exp;
    Node* next;
};


void insert(Node** head, int coeff, int exp) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->exp = exp;

    if (*head == NULL) {
        
        *head = newNode;
        newNode->next = newNode;
    } else {
        
        Node* last = (*head)->next;
        while (last->next != *head)
            last = last->next;

        last->next = newNode;
        newNode->next = *head;
    }
}


void display(Node* head) {
    if (head == NULL) {
        cout << "Polynomial is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;

        if (temp != head)
            cout << " + ";
    } while (temp != head);

    cout << endl;
}


Node* addPolynomials(Node* poly1, Node* poly2) {
    if (poly1 == NULL && poly2 == NULL)
        return NULL;
    if (poly1 == NULL)
        return poly2;
    if (poly2 == NULL)
        return poly1;

    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    do {
        if (temp1->exp == temp2->exp) {
            insert(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            insert(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            insert(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 && temp2 != poly2);

    
    while (temp1 != poly1) {
        insert(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    
    while (temp2 != poly2) {
        insert(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
	
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
	cout<<endl;
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* polySum = NULL;

    
    insert(&poly1, 2, 3);
    insert(&poly1, 3, 2);
    insert(&poly1, 4, 1);

    
    insert(&poly2, 1, 3);
    insert(&poly2, 2, 2);
    insert(&poly2, 3, 0);

    
    cout << "Polynomial 1: ";
    display(poly1);

    
    cout << "Polynomial 2: ";
    display(poly2);

    
    polySum = addPolynomials(poly1, poly2);

    
    cout << "Sum of the polynomials: ";
    display(polySum);

    return 0;
}
