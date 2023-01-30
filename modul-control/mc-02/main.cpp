#include <iostream>
#include <cstdio>

const char *FILE_NAME = "database.dat";
struct Student {
    char name[40];
    int count;
    int calories;
};

Student *createStudent();
void readFromFile();
using namespace std;
int main() {
    FILE * dataBase = fopen(FILE_NAME, "w");
    if(dataBase == NULL) {
        cout << "ошибка открытия файла" << endl;
        return 1;
    }

    int needWrite = 1;
    while(needWrite > 0) {
        Student *newStudent = createStudent();
        fwrite(newStudent, sizeof(Student), 1, dataBase);

        cout << "1 - продолжить, 0 - заврешить >> ";
        cin >> needWrite;
    }
    fclose(dataBase);

    readFromFile();



    return 0;
}

Student *createStudent() {
    setlocale(LC_ALL, "RUSSIAN");
    Student *newStudent = new Student;
    cout << "Введите: " << endl;
    cout << "Название >> ";
    cin >> newStudent->name;
    cout << "Цена >> ";
    cin >>newStudent->count;
    cout << "Калории >> ";
    cin >> newStudent->calories;

    return newStudent;
}

void readFromFile() {
    FILE  *readDataBase;
    readDataBase = fopen(FILE_NAME, "r");
    if (readDataBase == NULL) {
        return;
    }

    struct Student inputBuffer[5];
    int i = 0;
    while (fread(&inputBuffer[i], sizeof(Student), 1, readDataBase)) {
        i++;
    }
    for(int j = 0; j < i; j++) {
        if(inputBuffer[j].calories < 200) {
            printf("%s %s %d %d\n", "Блюдо", inputBuffer[j].name, inputBuffer[j].count,
                   inputBuffer[j].calories);
        }
    }
    fclose(readDataBase);

}