#include <iostream>

using namespace std;

struct tnode {
    int field;
    tnode* right;
    tnode* left;
};

tnode* tree = NULL;

void add(int field, tnode** branch) {
    if ((*branch) == NULL) {
        *branch = new tnode;
        (*branch)->field = field;
        (*branch)->left = NULL;
        (*branch)->right = NULL;
        return;
    }
    if (field >= (*branch)->field) {
        add(field, &(*branch)->right);
    }
    else {
        add(field, &(*branch)->left);
    }
}

tnode* findbranch(tnode** branch) {
    if ((*branch)->left != NULL) {
        findbranch(&(*branch)->left);
    }
    else {
        return (*branch);
    }
}

void remove(int field, tnode** branch) {
    if ((*branch) == NULL) {
        cout << "Its nothing to remove" << endl;
        return;
    }
    if (field > (*branch)->field) {
        remove(field, &(*branch)->right);
    }
    else if (field < (*branch)->field) {
        remove(field, &(*branch)->left);
    }
    else if (field == (*branch)->field) {
        if (((*branch)->left == NULL) && ((*branch)->right == NULL)) {
            (*branch) = NULL;
        }
        else if (((*branch)->left == NULL) && ((*branch)->right != NULL)) {
            (*branch)->field = ((*branch)->right)->field;
            (*branch)->left = ((*branch)->right)->left;
            (*branch)->right = ((*branch)->right)->right;
        }
        else if (((*branch)->left != NULL) && ((*branch)->right == NULL)) {
            (*branch)->field = ((*branch)->left)->field;
            (*branch)->right = ((*branch)->left)->right;
            (*branch)->left = ((*branch)->left)->left;
        }
        else if (((*branch)->left != NULL) && ((*branch)->right != NULL)) {
            if (((*branch)->right)->left == NULL) {
                (*branch)->field = ((*branch)->right)->field;
                (*branch)->right = ((*branch)->right)->right;
            }
            else {
                (*branch)->field = (findbranch(&(*branch)->right))->field;
                remove((*branch)->field, &(*branch)->right);
            }
        }
    }
}

void findelement(int field, tnode* branch) {
    if (branch == NULL) {
        cout << "There are no elements" << endl;
        return;
    }
    if (field == branch->field) {
        cout << "The element is found: ";
        cout << field << endl;
    }
    else if (field > branch->field) {
        cout << branch->field << endl;
        findelement(field, branch->right);
    }

    else {
        cout << branch->field << endl;
        findelement(field, branch->left);
    }
}

void infix(tnode* branch) {
    if (branch == NULL) {
        cout << "There are no elements" << endl;
        return;
    }
    if (branch->left != NULL) {
        infix(branch->left);
    }
    cout << branch->field << endl;
    if (branch->right != NULL) {
        infix(branch->right);
    }
}


void prefix(tnode* branch) {
    if (branch == NULL) {
        cout << "There are no elements" << endl;
        return;
    }
    cout << " " << branch->field  << endl;

    if (branch->left != NULL) {
        prefix(branch->left);
    }
    if (branch->right != NULL) {
        prefix(branch->right);
    }
}

void postfix(tnode* branch) {
    if (branch == NULL) {
        cout << "There are no elements" << endl;
        return;
    }
    if (branch->left != NULL) {
        postfix(branch->left);
    }
    if (branch->right != NULL) {
        postfix(branch->right);
    }
    cout << branch->field  << endl;
}


int main() {
    int option = 0;

    while (option != 5) {
        cout << "" << endl;
        cout << "Input option >>" << endl;
        cout << "1) Add element" << endl;
        cout << "2) Delete element" << endl;
        cout << "3) Print elements" << endl;
        cout << "4) Find element" << endl;
        cout << "5) Stop" << endl;
        cin >> option;
        cout << "" << endl;
        if (option == 1) {
            int field = 0;
            cout << "Input element >>" << endl;
            cin >> field;
            add(field, &tree);
            cout << "" << endl;
        }
        else if (option == 2) {
            int field = 0;
            cout << "Input element >>" << endl;
            cin >> field;
            remove(field, &tree);
            cout << "" << endl;
        }
        else if (option == 3) {
            int showoption = 10;
            while (showoption != 0) {
                cout << "Input option >>" << endl;
                cout << "1) Infix form" << endl;
                cout << "2) Prefix form" << endl;
                cout << "3) Postfix form" << endl;
                cin >> showoption;
                cout << "" << endl;
                if (showoption == 1) {
                    infix(tree);
                    cout << "";
                    showoption = 0;
                }
                else if (showoption == 2) {
                    prefix(tree);
                    cout << "" << endl;
                    showoption = 0;
                }
                else if (showoption == 3) {
                    postfix(tree);
                    cout << "" << endl;
                    showoption = 0;
                }
            }
        }
        else if (option == 4) {
            string str_;
            int count_n = 0;
            char field__str;
            cin >> field__str;
            char* field_str = &field__str;
            for (int i = 0; i < sizeof(field__str); i++) {
                if ((int(field_str[i]) >= 48) && (int(field_str[i]) <= 57)) {
                    count_n ++;
                    str_ += field_str[i];
                }
            }
            if (count_n == sizeof(field__str)) {
                int field = atoi(str_.c_str());
                cout << "Input element >>" << endl;
                findelement(field, tree);
                cout << "" << endl;
            }
            else {
                cout << "ne vvodite bukvi" << endl;
            }

        }
    }
    return 0;
}
