#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL; // Replace nullptr with NULL
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) // Replace nullptr with NULL
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root == NULL) // Replace nullptr with NULL
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) // Replace nullptr with NULL
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) // Replace nullptr with NULL
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
    Node* root = NULL; // Replace nullptr with NULL
    int choice, key;
    bool exit = false;

    // Create the BST
    int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; ++i)
        root = insert(root, values[i]);

    while (!exit) {
        cout << "\nMenu:\n";
        cout << "1. Traverse the BST in Inorder\n";
        cout << "2. Traverse the BST in Preorder\n";
        cout << "3. Traverse the BST in Postorder\n";
        cout << "4. Search for an element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Enter the element to search: ";
                cin >> key;
                if (search(root, key) != NULL) // Replace nullptr with NULL
                    cout << key << " is found in the BST.\n";
                else
                    cout << key << " is not found in the BST.\n";
                break;
            case 5:
                exit = true;
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice.\n";
        }
    }

    return 0;
}

