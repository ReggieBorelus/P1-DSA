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
#include <vector>

using namespace std;

#endif //PROJECT1_AVL_TREE_H

struct Node { // Node Structure and it's attributes along with it's parameterized constructor
    string UFID;
    string name;
    int height;
    Node* left;
    Node* right;

    Node(const string &UFID, const string &name) {
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
    map<string, Node*> ID; // A Map  to hold the ids for quick lookup
public:
    vector<string> preOrder;
    vector<string> inOrder;
    vector<string> postOrder;
    AVLTree() { // Constructor
        root = nullptr;
    };

    ~AVLTree() = default;

    bool Insert(string const &UFID, string const &name) {
        if (!all_of(name.begin(), name.end(), [](unsigned char const c) {  //Checks if all characters in the name parameter is alphabetical or a space
            return isalpha(c) || c == ' '  || c ==  '"';
        })  || !validUFID(UFID)) {
            cout << "unsuccessful\n";
            return false;
        }
        if (ID.find(UFID) != ID.end()) { //Does a lookup in a map to save time to see if an ID is already in tree. Trading off time for space.
            cout << "unsuccessful\n";
            return false;
        }
        root = InsertHelper(root, UFID, name);
        cout << "successful\n";
        return true;
    }

    Node* InsertHelper(Node* node, string UFID, string const &name) {

        if (node == nullptr) { //If there are no nodes in the tree, create a new Node as the root
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

    bool Remove(const string &UFID) {
        if (ID.find(UFID) == ID.end()) {
            cout << "unsuccessful\n";
            return false;
        }
        root = removeHelper(root, UFID);
        ID.erase(UFID);
        cout << "successful\n";
        return true;
    }

    Node* removeHelper(Node* node, string UFID) {
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

    bool Search(const string &UFID) {
        Node* node = traversalHelper(root, UFID);
        if (node == nullptr) {
            cout << "unsuccessful\n";
            return false;
        }
        if (node->UFID != UFID) {
            return false;
        }
        if (node->UFID == UFID) {
            cout << node->name<< "\n";
        }
        return true;
    }

    bool SearchName(const string &name) {
        if (!NameSearchHelper(root, name)) {
            cout << "unsuccessful\n";
            return false;
        }
        return true;
    }

    void printInorder(Node* node) {
        inOrder.clear();
        inorderHelper(node);
        if (!inOrder.empty()) {
            cout << inOrder[0];
        }
        for (unsigned int j = 1; j < inOrder.size(); j++) {
            cout << ", " << inOrder[j];
        }
        cout << endl;
    }

    void printPreorder(Node* node) {
        preOrder.clear();
        preorderHelper(node);
        if (!preOrder.empty()) {
            cout << preOrder[0];
        }
        for (unsigned int  j = 1; j < preOrder.size(); j++) {
            cout << ", " << preOrder[j];
        }
        cout << endl;
    }


    void printPostorder(Node* node) {
        postOrder.clear();
        postorderHelper(node);
        if (!postOrder.empty()) {
            cout << postOrder[0];
        }
        for (unsigned int  j = 1; j < postOrder.size(); j++) {
            cout << ", " << postOrder[j];
        }
        cout << endl;
    }

    void printLevelCount() {
        if (root == nullptr) {
            cout <<  "0\n";
            return;
        }
        cout << root->height << "\n";
    }

    void removeInorder(string n) { // Since the Nodes are kept in a map, we can advance an iterator to the nth element of the map. Maps are sorted by key so it would remove the right inorder node
        int k = stoi(n);
        auto it = ID.begin();
        unsigned int n_unsigned = k;
        if (k < 0  || n_unsigned >= ID.size()) {
            cout << "unsuccessful\n";
            return;
        }
        advance(it, k);
        root = removeHelper(root, it->first);
        ID.erase(it);
        cout << "successful\n";
    }

    int getHeight(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height ;
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

        temp->right = node; //Now we move our nodes around
        node->left = tempRight;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1; // Now we update the height of both nodes
        temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;

        return temp;
    }

    Node* rotateLeft(Node* node) { // It's the same logic as above but in a different direction.
        Node* temp = node->right;
        Node* tempLeft = temp->left;

        temp->left = node;
        node->right = tempLeft;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;

        return temp;
    }

    Node* traversalHelper(Node* node, const string UFID) { //A helper to help traverse the BST to find an ID. Since every UFID is unique, once the ID is found it does not have to call itself again.
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

    bool NameSearchHelper(Node* node, const string &name) { // A helper to find all names in a tree. Since names can occur multiple times, it has to call itself until the entire tree is searched.
        if (node == nullptr) {
            return false;
        }

        bool found = false;
        found = found|NameSearchHelper(node->left, name);
        if (node->name == name) {
            cout << node->UFID << "\n";
            found = true;
        }
        found = found|NameSearchHelper(node->right, name);
        return found;
    }

    Node* getRootNode() {
        return root;
    }

    bool validUFID(const string &UFID) {
        return (UFID.length() == 8 && all_of(UFID.begin(), UFID.end(), ::isdigit));
    }

    void inorderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderHelper(node->left);
        inOrder.push_back(node->name);
        inorderHelper(node->right);
    }

    void preorderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        preOrder.push_back(node->name);
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    void postorderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderHelper(node->left);
        postorderHelper(node->right);
        postOrder.push_back(node->name);
    }

};


