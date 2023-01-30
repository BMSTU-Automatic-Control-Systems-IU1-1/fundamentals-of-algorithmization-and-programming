#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;
const int N = 10;

struct Group {
    string numOfGroup[N];
    string prep[N];
    bool cond[N];
};

struct Student {
    string firstname[N];
    string secondname[N];
    int age[N], mark[N];
    Group group;
    bool cond[N];
};

Group newGroup(Group groups) {
    ofstream fGroups("groups.txt", ios::app);
    string gr, prep;
    cout << "Группа № ";
    cin >> gr;
    cout << "Имя преподавателя ";
    cin >> prep;
    if (gr != "end") {
        for (int i = 0; i < N; i++) {
            if (groups.numOfGroup[i] == "") {
                groups.numOfGroup[i] = gr;
                groups.prep[i] = prep;
                break;
            }
        }
        fGroups << gr << " " << prep << endl;
    }
    return groups;
}

Student newStudent(Group groups, Student students, int stNum) {
    ofstream fStudents("students.txt", ios::app);
    string stFName, stSName, stGroup;
    bool isAdded = false;
    int stAge, stMark;
    cout << "Имя студента ";
    cin >> stFName;
    if (stFName != "end") {
        cout << "Фамилия студента ";
        cin >> stSName;
        cout << "Возраст студента ";
        cin >> stAge;
        cout << "Оценка студента ";
        cin >> stMark;
        cout << "Группа студента ";
        cin >> stGroup;
        for (int i = 0; i < N; i++)
            if (groups.numOfGroup[i] == stGroup) {
                students.firstname[stNum] = stFName;
                students.secondname[stNum] = stSName;
                students.age[stNum] = stAge;
                students.mark[stNum] = stMark;
                students.group.numOfGroup[stNum] = stGroup;
                fStudents << stFName << " " << stSName << " " << stAge << " " << stMark << " " << stGroup << endl;
                isAdded = true;
                break;
            }
        if (!isAdded) cout << "Такой группы не существует!\n" << endl;
    }
    return students;
}

void openSt();
void openGr();
void search(Student student, Group group);

int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream fGroups("groups.txt");
    ofstream fStudents("students.txt");
    ifstream infSt("students.txt", ios::app);
    ifstream infGr("groups.txt", ios::app);
    Group groups;
    Student students;
    int stNum = 0, grNum = 0;
    for (int i = 0; i < N; i++) groups.numOfGroup[i] = "";
    if ((!fStudents) || (!fGroups))
    {
        cerr << "File could not be opened for writing" << endl;
        exit(1);
    }

    int command;
    do {
        cout << "Список команд:\n1. Добавить группу\n2. Добавить студента\n3. Файл студентов\n4. Файл групп\n5. Поиск\n Команда: ";
        cin >> command;
        switch (command) {
            case 1: groups = newGroup(groups);
                break;
            case 2: students = newStudent(groups, students, stNum);
                stNum++;
                break;
            case 3:
                openSt();
                break;
            case 4:
                openGr();
                break;
            case 5:
                //students = initSt(students);
                search(students, groups);
                break;
            default: if (command!= 0) cout << "Wrong answer" << endl;
        }
        cout << endl;
    } while (command != 0);

    return 0;
}

void openGr() {
    ifstream infGr("groups.txt", ios::app);
    cout << endl;
    int i = 0;
    while (infGr) {
        string strInput;
        getline(infGr, strInput);
        cout << "          " << strInput << endl;
    }
    infGr.close();
}

void search(Student student, Group group) {
    ifstream infSt("students.txt", ios::app);
    ifstream infGr("groups.txt", ios::app);
    string file, cond[3], fields[N], order;
    char cfields[100], conditions[100];
    int limit = 0;
    cin.getline(cfields, 100);
    cout << "SELECT ";
    cin.getline(cfields, 100);
    cout << "FROM ";
    cin >> file;
    cin.getline(conditions, 100);
    cout << "WHERE ";
    cin.getline(conditions, 100);
    if (file != "Группы") {
        cout << "ORDER BY ";
        cin >> order;
    }
    cout << "LIMIT ";
    cin >> limit;
    cout << endl;

    if (limit == 0) {
        limit = 100;
    }

    int iter = 0;
    char* pch = strtok(cfields, " ,");
    while (pch != NULL)
    {
        fields[iter] = pch;
        iter++;
        pch = strtok(NULL, " ,");
    }

    int iter1 = 0;
    char* pch1 = strtok(conditions, " ");
    while (pch1 != NULL)
    {
        cond[iter1] = pch1;
        iter1++;
        pch1 = strtok(NULL, " ");
    }

    //cond[0] - Имя, фамилия, возраст, оценка или группа
    //cond[1] - > < = >= <=
    //cond[2] - Число или "Значение"

    for (int i = 0; i < N; i++) {
        student.cond[i] = 0;
        group.cond[i] = 0;
    }

    int flag = 0;
    if ((cond[0] == "Имя") || (cond[0] == "Фамилия") || (cond[0] == "Группа")) {
        if (cond[1] == "=") {
            if (cond[0] == "Имя") while (student.firstname[flag] != ""){
                    if (student.firstname[flag] == cond[2])
                        student.cond[flag] = 1;
                    flag++;
                }
            if (cond[0] == "Фамилия") while (student.firstname[flag] != ""){
                    if (student.secondname[flag] == cond[2])
                        student.cond[flag] = 1;
                    flag++;
                }
            if (cond[0] == "Группа") while (student.firstname[flag] != ""){
                    if (student.group.numOfGroup[flag] == cond[2])
                        student.cond[flag] = 1;
                    flag++;
                }
        }
    }
    else if (cond[0] == "Преподаватель"){
        if (cond[1] == "=") {
            while (group.numOfGroup[flag] != "") {
                if (group.prep[flag] == cond[2])
                    group.cond[flag] = 1;
                flag++;
            }
        }
    }
    else if (cond[0] == "Возраст") {
        int res = stoi(cond[2]);
        if (cond[1] == ">") {
            while (student.firstname[flag] != "") {
                if (student.age[flag] > res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == "<") {
            while (student.firstname[flag] != "") {
                if (student.age[flag] < res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == "=") {
            while (student.firstname[flag] != "") {
                if (student.age[flag] == res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == ">=") {
            while (student.firstname[flag] != "") {
                if (student.age[flag] >= res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == "<=") {
            while (student.firstname[flag] != "") {
                if (student.age[flag] <= res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
    }
    else if (cond[0] == "Оценка") {
        int res = stoi(cond[2]);
        if (cond[1] == ">") {
            while (student.firstname[flag] != "") {
                if (student.mark[flag] > res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == "<") {
            while (student.firstname[flag] != "") {
                if (student.mark[flag] < res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == "=") {
            while (student.firstname[flag] != "") {
                if (student.mark[flag] == res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == ">=") {
            while (student.firstname[flag] != "") {
                if (student.mark[flag] >= res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
        if (cond[1] == "<=") {
            while (student.firstname[flag] != "") {
                if (student.mark[flag] <= res)
                    student.cond[flag] = 1;
                flag++;
            }
        }
    }

    if (cond[0] == "-") {
        for (int i = 0; i < N; i++) {
            student.cond[i] = 1;
            group.cond[i] = 1;
        }
    }

    if (order != "-") {
        if (order == "Возраст") {
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < N - 1; i++) {
                    if ((student.age[i] < student.age[i + 1]) and (student.age[i+1] > 0)) {
                        int vr1 = student.age[i];
                        student.age[i] = student.age[i + 1];
                        student.age[i + 1] = vr1;
                        int vr2 = student.mark[i];
                        student.mark[i] = student.mark[i + 1];
                        student.mark[i + 1] = vr2;
                        string vr3 = student.firstname[i];
                        student.firstname[i] = student.firstname[i + 1];
                        student.firstname[i + 1] = vr3;
                        string vr4 = student.secondname[i];
                        student.secondname[i] = student.secondname[i + 1];
                        student.secondname[i + 1] = vr4;
                        string vr5 = student.group.numOfGroup[i];
                        student.group.numOfGroup[i] = student.group.numOfGroup[i + 1];
                        student.group.numOfGroup[i + 1] = vr5;
                    }
                }
            }
        }
        if (order == "Оценка") {
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < N-1; i++) {
                    if ((student.mark[i] < student.mark[i + 1]) and (student.mark[i+1] > 0)) {
                        int vr1 = student.age[i];
                        student.age[i] = student.age[i + 1];
                        student.age[i + 1] = vr1;
                        int vr2 = student.mark[i];
                        student.mark[i] = student.mark[i + 1];
                        student.mark[i + 1] = vr2;
                        string vr3 = student.firstname[i];
                        student.firstname[i] = student.firstname[i + 1];
                        student.firstname[i + 1] = vr3;
                        string vr4 = student.secondname[i];
                        student.secondname[i] = student.secondname[i + 1];
                        student.secondname[i + 1] = vr4;
                        string vr5 = student.group.numOfGroup[i];
                        student.group.numOfGroup[i] = student.group.numOfGroup[i + 1];
                        student.group.numOfGroup[i + 1] = vr5;
                    }
                }
            }
        }
    }

    int s = 0;
    if ((file == "Студенты") || (file == "студенты")) {
        int i = 0;
        while (student.firstname[i] != "") {
            if (s < limit) {
                for (int j = 0; j < iter; j++) {
                    if (student.cond[i] == 1) {
                        if (fields[j] == "Имя") cout << student.firstname[i] << " ";
                        if (fields[j] == "Фамилия") cout << student.secondname[i] << " ";
                        if (fields[j] == "Возраст") cout << student.age[i] << " ";
                        if (fields[j] == "Оценка") cout << student.mark[i] << " ";
                        if (fields[j] == "Группа") cout << student.group.numOfGroup[i] << " ";
                    }
                }
                if (student.cond[i] == 1) cout << endl;
                i++;
                s++;
            }
            else i++;
        }
    }

    if ((file == "Группы") || (file == "группы")) {
        int i = 0;
        while (group.numOfGroup[i] != "") {
            if (s < limit) {
                for (int j = 0; j < iter; j++) {
                    if (group.cond[i] == 1) {
                        if (fields[j] == "Группа") cout << group.numOfGroup[i] << " ";
                        if (fields[j] == "Преподаватель") cout << group.prep[i] << " ";
                    }
                }
                if (group.cond[i] == 1) cout << endl;
                i++;
                s++;
            }
            else i++;
        }
    }
}

void openSt() {
    ifstream infSt("students.txt", ios::app);
    cout << endl;
    while (infSt) {
        string strInput;
        getline(infSt, strInput);
        cout << "          " << strInput << endl;
    }
    infSt.close();
}