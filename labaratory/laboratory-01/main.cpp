// ToDo Solution 1
// #include <iostream>
//#include <map>
//using namespace std;
//
//int main() {
//    int len;
//    cin >> len;
//    int m[len];
//
//    for(int i = 0; i < len; i ++){
//        cin >> m[i];
//    }
//
//    map<int, int> counter;
//
//    for(int i = 0; i < len; ++i){
//        ++counter[m[i]];
//    }
//
//    for (int i = 0; i < len; ++i){
//        if (counter[m[i]] == 1){
//            cout << m[i] << ' ';
//        }
//    }
//    return 0;
//}


// ToDo Solution 2

#include <iostream>
using namespace std;
int main(){

    setlocale(LC_ALL, "Russian");  // ToDo Подключает русский язык в консоли

    int len;
    cout << "Введите длину массива: ";
    cin >> len;

    if(len == 0){
        cout << "Нет самого наименьшего элемента";         // ToDo Раздел для ответа, если у нас 0 элементов
    }
    else{
        int m[len];
        cout << "Введите сам массив: ";
        for (int i = 0; i < len; i++){
            cin >> m[i];
        }

        for (int i = 0; i < len; i++){
            int count = 0;
            for (int j = 0; j < len; j++){
                if (i != j && m[i] == m[j]){
                    count += 1;
                }
            }
            if(!count){
                cout << "Самый редкий элемент: " << m[i] << " ";
            }
        }
    }
    return 0;
}

