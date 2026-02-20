//
// Created by Jayde on 2/15/2026.
//

#ifndef PROJECT1_AVL_TREE_H
#define PROJECT1_AVL_TREE_H
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <map>

using namespace std;

#endif //PROJECT1_AVL_TREE_H

struct Node { // Node Structure and it's attributes along with it's parameterized constructor
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
    map<int, Node*> ID; // A Map  to hold the ids for quick lookup

public:
    AVLTree() {
        root = nullptr;
        height = 0;
    };

    ~AVLTree();

    bool Insert(int const &UFID, string const &name) {
        if (!all_of(name.begin(), name.end(), [](unsigned char const c) {  //Checks if all characters in the name parameter is alphabetical or a space
            return isalpha(c) || c == ' ';
        })) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        if (ID.find(UFID) == ID.end()) { //Does a lookup in a map to save time to see if an ID is already in tree. Trading off time for space.
            cerr << "Unsuccessful" << endl;
            return false;
        }
        root = InsertHelper(root, UFID, name);
        return true;
    }

    Node* InsertHelper(Node* node, int UFID, string const &name) {

        if (node == nullptr) {
            Node* newNode = new Node(UFID, name);
            ID[UFID] = newNode;
            return newNode;
        }

        if (UFID < node->UFID) {
            node->left = InsertHelper(node->left, UFID, name); //Recursively calls the InsertHelper Function to insert the node into the propper place
        }
        else if (UFID > node->UFID) {
            node->right = InsertHelper(node->right, UFID, name); //Recursively calls the InsertHelper Function to insert the node into the propper place
        }
        else {
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right )) + 1;  //Updates the height of the node to maintain balance

        int balance = getBalanceFactor(node);

        if (balance > 1 && UFID < node->left->UFID) { //LL Rotation
            return rotateRight(node);
        }
        if (balance < -1 && UFID > node->right->UFID) { //RR Rotation
            return rotateLeft(node);
        }
        if (balance > 1 && UFID > node->left->UFID) { //LR Rotation
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && UFID < node->right->UFID) { //RL Rotation
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }


    bool Remove(const int &UFID) {
        if (root == nullptr) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        if (ID.find(UFID) == ID.end()) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        root = removeHelper(root, UFID);
        ID.erase(UFID);
        return true;
    }

    Node* removeHelper(Node* node, int UFID) {
        if (node == nullptr) { //if the passed in node is nullptr, returns
            return nullptr;
        }
        if (UFID < node->UFID) { //otherwise, the function recursively calls itself to find the target node
            node->left = removeHelper(node->left, UFID);
        }
        else if (UFID > node->UFID) {
            node->right = removeHelper(node->right, UFID);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) { //if the node that is being deleted has no children, delete that node and return a nullptr
                delete node;
                return nullptr;
            }
            if ((node->left != nullptr && node->right == nullptr) || (node->right != nullptr && node->left == nullptr)) { //if the node that is being deleted has one child, temporarily store the child node, delete the node, and make the child the new node
                if (node->left != nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                if (node->right != nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
            }
            if (node->left != nullptr && node->right != nullptr) {  //if the node that is being deleted has 2 children, store the inorder successor, delete the node, make the inorder successor the node, and delete the old child
                Node* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->UFID = temp->UFID;
                node->name = temp->name;

                node->right = removeHelper(node->right, temp->UFID);
            }
        }

        node->height = max(getHeight(node->left), getHeight(node->right )) + 1;  //Updates the height of the node to maintain balance

        int balance = getBalanceFactor(node);

        if (balance > 1 && getBalanceFactor(node->left) >= 0) { //LL Rotation
            return rotateRight(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) <= 0) { //RR Rotation
            return rotateLeft(node);
        }
        if (balance > 1 && getBalanceFactor(node->left) < 0) { //LR Rotation
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) > 0) { //RL Rotation
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }


        return node;
    }

    bool Search(const int &UFID) {
        Node* node = traversalHelper(root, UFID);
        if (node == nullptr) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        if (node->UFID != UFID) {
            return false;
        }
        if (node->UFID == UFID) {
            cout << node->name << endl;
        }
        return true;
    }

    bool Search(const string &name) {
        if (!NameSearchHelper(root, name)) {
            cerr << "Unsuccessful" << endl;
            return false;
        }
        return true;
    }

    void printInorder(Node* node) {
        if (node == nullptr) {
           return;
        }
        printInorder(node->left);
        cout << node->name << " " << node->UFID<< endl;
        printInorder(node->right);
    }

    void printPreorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->name << " "  << node->UFID << endl;
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void printPostorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->name << " "  << node->UFID << endl;
    }

    void printLevelCount() {
        if (root == nullptr) {
            cout <<  "0" << endl;
            return;
        }
        cout << root->height << endl;
    }

    void removeInorder(int n) {

    }

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* node) {
        Node* temp = node->left; //We set a pointer equal to the left node of the node we want to rebalance from
        Node* tempRight = temp->right; //We set another pointer from the previous temp node that points to the right of it

        temp->right = node; //Now we move our node to the right of
        node->left = tempRight;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;

        return temp;
    }

    Node* rotateLeft(Node* node) {
        Node* temp = node->right;
        Node* tempLeft = temp->left;

        temp->left = node;
        node->right = tempLeft;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;

        return temp;
    }

    Node* traversalHelper(Node* node, const int UFID) {
        if (node == nullptr) {
            return nullptr;
        }
        if (UFID == node->UFID) {
            return node;
        }

        if (UFID < node->UFID) {
            return traversalHelper(node->left, UFID);
        }
        else {
            return traversalHelper(node->right, UFID);
        }
    }

    bool NameSearchHelper(Node* node, const string &name) {
        if (node == nullptr) {
            return false;
        }

        bool found = false;
        found = found|NameSearchHelper(node->left, name);
        if (node->name == name) {
            cout << node->UFID << endl;
            found = true;
        }
        found = found|NameSearchHelper(node->left, name);
        return found;
    }



};


