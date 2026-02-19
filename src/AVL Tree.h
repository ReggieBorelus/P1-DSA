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

    Node(const int &UFID, const string &name) {
        this->UFID = UFID;
        this->name = name;
        this->height = 0;
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
        Node* newNode = new Node(UFID, name);
        if (root == nullptr) {
            root = newNode;
        }
        ID[UFID] = newNode;



        return true;
    }

    bool Remove(const int &UFID) {
        if (root == nullptr) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        if (ID.find(UFID) != ID.end()) {

            cout << "Successful" << endl;
        }
        else {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        return true;
    }

    void Search(const string &name) {
        if (root ==  nullptr) {
            cerr << "Unsuccessful" << endl;
        }
         for (auto it = ID.begin(); it != ID.end(); ++it) {
            if (it->second->name == name) {
                cout << it->second->name << endl;
            }
            else {
                cerr << "Unsuccessful" << endl;
            }
        }
    }

    void printInorder() {

    }

    void printPreorder() {

    }

    void printPostorder() {

    }

    void printLevelCount() {

    }

    void removeInorder(int n) {

    }


};


//     void sort() {
//         Node* &temp = root;
//
//         for (int i = 0; i < ID.size(); i++) {
//             for (auto it = ID.begin(); it != ID.end(); it++) {
//                 if (it->second->UFID < temp -> UFID) {
//                     temp->left = it->second;
//                     temp = it->second;
//                 }
//                 else if (it ->second -> UFID > temp -> UFID) {
//                     temp->right = it -> second;
//                     temp = it -> second;
//                 }
//             }
//         }
//     }