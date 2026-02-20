#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "AVL_Tree.h"

using namespace std;


int main(){
	int i = 0;
	int x;
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	AVLTree tree;
	while (i < x) {
		string line;
		getline(cin, line);

		istringstream in(line);
		string command;

		in >> command;
		string name;
		string UFID;

		if (in.peek() == ' ') in.get();
		if (in.peek() == '"') {
			in >> quoted(name);
		}

		if (in >> UFID) {

		}

		if (command == "insert") {
			tree.Insert(UFID, name);
		}
		else if (command == "remove") {
			tree.Remove(UFID);
		}
		else if (command == "search" && name.empty()) {
			tree.Search(UFID);
		}
		else if (command == "search") {
			tree.SearchName(name);
		}
		else if (command == "printInorder") {
			tree.printInorder(tree.getRootNode());
		}
		else if (command == "printPreorder") {
			tree.printPreorder(tree.getRootNode());

		}
		else if (command == "printPostorder") {
			tree.printPostorder(tree.getRootNode());
		}
		else if (command == "printLevelCount") {
			cout << tree.getHeight(tree.getRootNode()) + 1 << endl;
		}
		else if (command == "removeInorder") {
			tree.removeInorder(UFID);
		}
		else {
			cout << "unsuccessful\n";
		}
		i++;
	}

	return 0;
}
