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
    setlocale(LC_ALL, "Russian");

    int StartCommand = -1;
    do {
        cout << "Введите \"0\" чтобы выйти" << endl;
        cout << "Введите \"1\" для добавления в стэк" << endl;
        cout << "Введите \"2\" для удаления из стэка" << endl;
        cout << "Введите \"3\" для нахождения элемента" << endl;
        cout << "введите \"4\" для распечатывания стэка" << endl;
        cout << "Введите \"5\" для проверки последовательности скобочек на правильность" << endl;

        cin >> StartCommand;

        switch (StartCommand) {
            case 0: break;
            case 1: {
                char pushNumber = ' ';
                do {
                    printStack();
                    cout << "Введите число(символ) который вы хотите добавить в стэк и 0 для прекращения:" << endl;
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
                cout << "Ввидите число(симвл), который вы хотите найти: ";
                cin >> elementToSearch;
                findElement(elementToSearch);
                cout << "\n";
                break;
            }
            case 4:
                cout << "Стэк:" << endl;
                printStack();
                cout << "\n";
                break;
            case 5: {
                top = nullptr;
                CorrectString();
                cout << "\n";
                break;
            }
            default: {
                cout << "Неизвестная команда!" << endl;
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
    cout << "Число " << top->digit.Data << " был удалён" << endl;
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
    if (!isFound) cout << "Этого элемента нет в стэке" << endl;
}


void CorrectString() {
    char openingBrackets[3] = { '(' , '[' , '{' };
    char closingBrackets[3] = { ')' , ']' , '}' };
    cout << "Введите последовательность ваших скобочек: ";
    string UserString;
    cin >> UserString;

    bool isCorrect = true;

    if (UserString.size() <= 1){
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


