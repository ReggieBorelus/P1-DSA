//
// Created by Jayde on 2/15/2026.
//

#ifndef PROJECT1_AVL_TREE_H
#define PROJECT1_AVL_TREE_H
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;

#endif //PROJECT1_AVL_TREE_H

struct Node {
    int UFID;
    string name;
    int height;
    Node* left;
    Node* right;

    Node(int UFID, string name) {
        this->UFID = UFID;
        this->name = name;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    };
};

class AVLTree {
private:
    Node* root;
    int height;
    map<int, Node*> ID;
public:
    AVLTree() {
        root = nullptr;
        height = 0;
    };

    ~AVLTree();

    bool Insert(int const &UFID, string const &name) {
        if (!all_of(name.begin(), name.end(), [](unsigned char const c) {
            return isalpha(c) || c == ' ';
        })) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        if (root == nullptr) {
            root = new Node(UFID, name);
        }
        ID[UFID] = new Node(UFID, name);
        return true;
    }

    bool Remove(const int &UFID) {
        if (root == nullptr) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        if () {

        }
        return true;
    }

    bool Search(const string &name) {

    }

};
