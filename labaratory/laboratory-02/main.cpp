#include <iostream>
#include <string>

using namespace std;

struct Data {
	char Data;
};

struct Stack {
	Data digit;
	Stack* next;
};

Stack* top = nullptr;

Stack* push(Data digit);
void pop();
void printStack();
void findElement(char element);
void CorrectString();

int main() {
	int StartCommand = -1;
	do {
		cout << "enter \"0\" to EXIT" << endl;
		cout << "enter \"1\" to check PUSH COMMAND" << endl;
		cout << "enter \"2\" to check POP COMMAND" << endl;
		cout << "enter \"3\" to check FIND ELEMENT COMMAND" << endl;
		cout << "enter \"4\" to check CORRECT STRING COMMAND" << endl;

		cin >> StartCommand;

		switch (StartCommand) {
		case 0: break;
		case 1: {
			char pushNumber = ' ';
			do {
				printStack();
				cout << "enter the number(symbol) you want to add to Stack (not 0)" << endl;
				cin >> pushNumber;

				Data digit;
				digit.Data = pushNumber;
				if (pushNumber != '0') push(digit);
			} while (pushNumber != '0');
			cout << "\n";
			break;
		}
		case 2: {
			pop();
			cout << "\n";
			break;
		}
		case 3: {
			char elementToSearch;
			cout << "Enter the number(symbol) you want to find: ";
			cin >> elementToSearch;
			findElement(elementToSearch);
			cout << "\n";
			break;
		}
		case 4: {
			top = nullptr;
			CorrectString();
			cout << "\n";
			break;
		}
		default: {
			cout << "Unknown command!" << endl;
			cout << "\n";
			break;
		}
		}
	}while(StartCommand != 0);
	return 0;
}


Stack* push(Data digit) {
	Stack* ptr = new Stack;

	ptr->digit = digit;
	ptr->next = top;
	top = ptr;
	return ptr;
}

void pop() {
	if (top == nullptr) return;
	Stack* ptr = top->next;
	cout << "Digit " << top->digit.Data << " was deleted " << endl;
	delete top;
	top = ptr;
}

void printStack() {
	Stack* current = top;
	while (current != nullptr) {
		cout << current->digit.Data << " " << current << endl;
		current = current->next;
	}
}


void findElement(char element) {
	bool isFound = false;
	Stack* current = top;
	while (current != nullptr) {
		if (current->digit.Data == element) {
			cout << current->digit.Data << " " << current << endl;
			isFound = true;
			break;
		}
		current = current->next;
	}
	if (!isFound) cout << "This item is not found in the Stack" << endl;
}


void CorrectString() {
	char openingBrackets[3] = { '(' , '[' , '{' };
	char closingBrackets[3] = { ')' , ']' , '}' };
	cout << "Enter the brackets string: ";
	string UserString;
	cin >> UserString;

	bool isCorrect = true;

    if (UserString.size() <= 1) {
        isCorrect = false;
    }

	for (int i = 0; i < UserString.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (UserString[i] == openingBrackets[j]) {
				Data symbol;
				symbol.Data = openingBrackets[j];
				push(symbol);
			}
			else if (UserString[i] == closingBrackets[j]) {
				if (top == nullptr) break;
				else {
					char topSymbol = top->digit.Data;
					pop();
					if (topSymbol != openingBrackets[j]) isCorrect = false;
				}
			}
		}
	}
	if (isCorrect && (top == nullptr)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
}