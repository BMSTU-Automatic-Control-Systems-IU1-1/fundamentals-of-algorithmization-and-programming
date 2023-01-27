#include <iostream>
using namespace std;

const int N = 26;
const int MAX_ITEM_SIZE = 50;

struct HashItem{
    string items[MAX_ITEM_SIZE];
    int currentSize = 0;

    void push(string str){
        items[currentSize] = str;
        currentSize++;
    }
    bool find(string str){
        for (int i = 0; i < currentSize; i++){
            if(items[i] == str){
                return true;
            }
        }
        return false;
    }
};


struct MyHashTable{
    HashItem values[N];

    int hash (string str){
        int result = int(str[0]) - int('A');
        cout << str[0] << " " << result << endl;
        return result;
    }

    /*void push(string str){
        values[hash(str)] = str;
    }*/

    void push(string str){
        values[hash(str)].push(str);
    }

    bool find(string str){
       if (values[hash(str)].find(str)){
           return true;
       }
       return false;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    MyHashTable hashTable;

    hashTable.push("AAA");
    hashTable.push("AAB");

    cout << hashTable.find("AAA") << endl;
    cout << hashTable.find("AAB") << endl;

    return 0;
}
