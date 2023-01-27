#include <iostream>
using namespace std;

void zipping(char* str, int n);   // ToDo Обозначение функции

int main() {
    char *str;                    // ToDo Заводим массив и его длину
    int n = 0;

    cout << "Input size >> ";
    cin >> n;

    str = new char[n];            // ToDo Вписываем эту строку
    cout << "Input string >> ";
    cin >> str;

    cout << "zipping: ";

    zipping(str, n);               // ToDo Выводим итоговую строку

    return 0;
}


void zipping(char* str, int n)           // ToDo Сама функция сокращения строки
{
    int count = 1;

    for (int i = 0; i < n ; i++)
        if (str [i] == str [i + 1]){
            count++;
        }
        else {
            cout << str [i] << count;
            count = 1;
        }
}
