#include <iostream>
using namespace std;

struct List{
    int data;
    List *next;
};

List* addNewItem(List *start, int a);
List* swapItem (List* start, int number);

int main() {
    setlocale(LC_ALL, "Russian");

    List *start = nullptr;
    int task = -1;
    do {
        cout << "input number >>";
        cin >> task;
        if (task > 0){
            start = addNewItem(start, task);
        }
    } while (task >= 0);

    int number;
    cout << "Введите число, которое хотите заменить: ";
    cin >> number;
    swapItem (start, number);

    while(start != nullptr){
        cout << start << " " << start->data << endl;   // ToDo вывод ячейки
        start = start -> next;
    }
    return 0;
}

List *swapItem (List* start, int number){
    while (start != nullptr) {
        int min1 = start->data;
        if (min1 == number){
             start->data = 0;
        }
        start = start->next;
    }
}

List *addNewItem(List * start, int a){
    List *newItem = new List;
    newItem->data = a;
    newItem->next = start;
    return newItem;
}