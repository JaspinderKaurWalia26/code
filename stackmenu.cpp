#include<iostream>
using namespace std;

class stack {
	private:
		static const int max_size = 100;
		int array[max_size];
		int top;
	public:
		stack() {
			top = -1;
		}

		int push(int element) {
			if(top == max_size - 1) {
				cout << "Stack overflow!" << endl;
				return 0;
			}
			array[++top] = element;
			
		}
		int pop() {
                if (top == -1) {
                cout << "Stack underflow" << endl;
                return 0; 
    }
            int poppedElement = array[top--]; 
            cout << "Popped element: " << poppedElement << endl; 
            return poppedElement; 
}

	

		void check_overflow() {
			if(top == max_size - 1) {
				cout << "Full stack" << endl;
			}
			else {
				cout << "Stack is not full" << endl;
			}
		}

		void check_underflow() {
			if(top == -1) {
				cout << "Empty stack" << endl;
			}
		}

		void display() {
			if(top == -1) {
				cout << "Stack is empty" << endl;
			}
			else {
				cout << "Elements in the stack are:" << endl;
				for(int i = top; i >= 0; i--) {
					cout << array[i] << " ";
				}
				cout << endl;
			}
		}

		void check_palindrome() {
			if(top == -1) {
				cout << "Stack is empty, cannot check palindome" << endl;
			}
			else {
				bool isPalindrome = true;
				for(int i = 0; i <= top / 2; i++) {
					if(array[i] != array[top - i]) {
						isPalindrome = false;
						break;
					}
				}

				if(isPalindrome) {
					cout << "Stack elements form a palindrome" << endl;
				}
				else {
					cout << "Stack elements do not form a palindrome" << endl;
				}
			}
		}
};

int main() {
	stack s;
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
	int choice, element;
	while (true) {
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Check Overflow" << endl;
		cout << "4. Check Underflow" << endl;
		cout << "5. Display" << endl;
		cout << "6. Check Palindrome" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter the element to push: ";
				cin >> element;
				s.push(element);
				break;
			case 2:
				cout << "Popped element: " << s.pop() << endl;
				break;
			case 3:
				s.check_overflow();
				break;
			case 4:
				s.check_underflow();
				break;
			case 5:
				s.display();
				break;
			case 6:
				s.check_palindrome();
				break;
			case 7:
				cout << "Exiting the program." << endl;
				return 0;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}

}
