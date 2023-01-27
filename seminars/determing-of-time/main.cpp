#include <iostream>
using namespace std;

struct List{
    int data;
    List *next;
};

List* addNewItem(List *start, int a);
void findMin(List* start);
void insertAfterFirst(List *start, int a);

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
    } while (task != 0);

    findMin(start);                                    // ToDo поиск минимального элемента

    cout << "Введите a: ";
    int a = 0;
    cin >> a;

    insertAfterFirst(start, a);

    while(start != nullptr){
        cout << start << " " << start->data << endl;   // ToDo вывод ячейки
        start = start -> next;
    }
    return 0;
}


void findMin(List* start){
    int min1 = 0; int min = 1000;
    while (start != nullptr) {
        int min1 = start->data;
        if (min > min1){
            min = min1;
        }
        start = start->next;
    }
    cout << "minimum: " << min << endl;
}

void insertAfterFirst(List *start, int a){
    List *newItem = new List;
    newItem->data = a;
    newItem->next = start->next;
    start->next = newItem;
}

List *addNewItem(List * start, int a){
    List *newItem = new List;
    newItem->data = a;
    newItem->next = start;                 // ToDo С помощью указателя next
    return newItem;
}
