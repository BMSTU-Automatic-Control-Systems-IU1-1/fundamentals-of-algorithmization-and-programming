#include <iostream>
using namespace std;

struct tnode {
    int field;
    tnode *left;
    tnode *right;

};

tnode* search(tnode *tree, int field) {
    if (tree == nullptr) {
        cout << "Error! Field not found.";
        return nullptr;
    }
    if (tree->field == field) {
        cout << ' ' << field << ' ';
        return tree;
    }
    cout << tree->field << " -> ";
    if (tree->field > field) {
        search(tree->left, field);
    } else {
        search(tree->right, field);
    }
}

void Add(int x, tnode *&tree) {
    if (tree == nullptr) {
        tree = new tnode;
        tree->field = x;
        tree->left = nullptr;
        tree->right = nullptr;
        return;
    } else if (x < tree->field) {
        Add(x, tree->left);
    } else if (x >= tree->field) {
        Add(x, tree->right);
    }
}

tnode* find_parent(tnode* tree, int field, tnode *sub) {
    if (tree == sub) {
        return nullptr;
    }
    if (tree->field >= field) {
        if (tree->left->field == field) {
            return tree;
        }
        find_parent(tree->left, field, sub);
    } else {
        if (tree->right->field == field) {
            return tree;
        }
        find_parent(tree->right, field, sub);
    }
}

tnode* find_most_left(tnode *tree) {
    while (tree->left != nullptr) {
        tree = tree->left;
    }
    return tree;
}

void delete_element(tnode *&tree, int field) {
    tnode* sub_tree = search(tree, field);
    if (sub_tree == nullptr) {
        return;
    }


    tnode* parent = find_parent(tree, field, sub_tree);

    if (sub_tree->right == nullptr && sub_tree->left == nullptr) {
        if (parent != nullptr) {
            if (parent->left != nullptr && parent->left->field == field) {
                parent->left = nullptr;
            } else if (parent->right != nullptr && parent->right->field == field) {
                parent->right = nullptr;
            }
            delete sub_tree;
        } else {
            delete sub_tree;
            tree = nullptr;
            return;
        }

    } else if (sub_tree->right == nullptr && sub_tree->left != nullptr) {
        tnode *pointer_to_del = sub_tree;
        sub_tree = sub_tree->left;
        if (parent != nullptr) {
            if ((parent->right != nullptr) && (parent->left->field == field)) {
                delete parent->left;
                parent->left = sub_tree;
            } else if ((parent->right != nullptr) && (parent->right->field == field)) {
                delete parent->right;
                parent->right = sub_tree;
            }
        } else {
            tree = sub_tree;
            delete pointer_to_del;
        }
    } else if (sub_tree->right != nullptr && sub_tree->left == nullptr) {
        tnode *pointer_to_del = sub_tree;
        sub_tree = sub_tree->right;
        if (parent != nullptr) {
            if ((parent->left != nullptr) && (parent->left->field == field)) {
                delete parent->left;
                parent->left = sub_tree;
            } else if ((parent->right != nullptr) && (parent->right->field == field)) {
                delete parent->right;
                parent->right = sub_tree;
            }
        } else {
            tree = sub_tree;
            delete pointer_to_del;
        }
    } else if (sub_tree->right != nullptr && sub_tree->left != nullptr) {
        if (sub_tree->right->left == nullptr) {
            tnode *parent_sub_tree = sub_tree;
            sub_tree = sub_tree->right;
            if (parent != nullptr) {
                if ((parent->left != nullptr) && (parent->left->field == field)) {
                    parent->left = sub_tree;
                    sub_tree->left = parent_sub_tree->left;
                } else if ((parent->right != nullptr) && (parent->right->field == field)) {
                    parent->right = sub_tree;
                    sub_tree->left = parent_sub_tree->left;
                }
            } else {
                tree = sub_tree;
                tree->left = parent_sub_tree->left;
            }
            delete parent_sub_tree;
        } else {
            tnode *leftest_tree = find_most_left(sub_tree->right);
            leftest_tree->left = sub_tree->left;
            tnode *parent_sub_tree = sub_tree;
            sub_tree = sub_tree->right;
            if (parent != nullptr) {
                if ((parent->left != nullptr) && (parent->left->field == field)) {
                    parent->left = sub_tree;
                } else if ((parent->right != nullptr) && (parent->right->field == field)) {
                    parent->right = sub_tree;
                }
            } else {
                tree = sub_tree;
            }
            delete parent_sub_tree;
            cout << ' ';
        }
    }
}

void prefix_print(tnode *tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->field << ' ';
    prefix_print(tree->left);
    prefix_print(tree->right);
}

void infix_print(tnode *tree) {
    if (tree == nullptr) {
        return;
    }
    infix_print(tree->left);
    cout << tree->field << ' ';
    infix_print(tree->right);
}

void postfix_print(tnode *tree) {
    if (tree == nullptr) {
        return;
    }
    postfix_print(tree->left);
    postfix_print(tree->right);
    cout << tree->field << ' ';
}

int main() {
    tnode *tree = nullptr;
    cout << "Choose action:\n1. Add node\n2. Delete node\n3. Find node\n4. Print tree\n0. Exit\n";
    string input;
    while (true) {
        getline(cin, input);
        if (input == "1") {
            int field;
            cin >> field;
            cin.ignore();
            Add(field, tree);
        } else if (input == "2") {
            int field;
            cin >> field;
            cin.ignore();
            delete_element(tree, field);
            cout << '\n';
        } else if (input == "3") {
            int field;
            cin >> field;
            cin.ignore();
            search(tree, field);
            cout << '\n';
        } else if (input == "4") {
            cout << "Chose print method:\na. Infix\nb. Prefix\nc. Postfix\n";
            getline(cin,input);
            if (input == "a") {
                infix_print(tree);
                cout << '\n';
            } else if (input == "b") {
                prefix_print(tree);
                cout << '\n';
            } else if (input == "c") {
                postfix_print(tree);
                cout << '\n';
            }
        } else if (input == "0") {
            break;
        }
    }
}
