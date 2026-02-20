#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "AVL_Tree.h"


// uncomment and replace the following with your own headers
// #include "AVL.h"

using namespace std;



TEST_CASE("Name validation", "[validity]") {
	AVLTree tree;
	REQUIRE(tree.Insert("17001148", "re2") ==  false);
	REQUIRE(tree.Insert("17001148", "a11y") == false);
	REQUIRE(tree.Insert("17001148", "G00mba") ==  false);
	REQUIRE(tree.Insert("17001148", "Ma55") == false);
	REQUIRE(tree.Insert("17001148", "m@rk") == false);
}

TEST_CASE()
