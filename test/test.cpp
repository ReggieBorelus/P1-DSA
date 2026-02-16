// // #include <catch2/catch_test_macros.hpp>
// // #include <iostream>
// // #include "GatorBST.h"
// //
// //
// // // uncomment and replace the following with your own headers
// // // #include "AVL.h"
// //
// // using namespace std;
// //
// //
// // // the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
// // TEST_CASE("Example Test Name - Change me!", "[flag]"){
// // 	// instantiate any class members that you need to test here
// // 	int one = 1;
// //
// // 	// anything that evaluates to false in a REQUIRE block will result in a failing test
// // 	REQUIRE(one == 0); // fix me!
// //
// // 	// all REQUIRE blocks must evaluate to true for the whole test to pass
// // 	REQUIRE(false); // also fix me!
// // }
// //
// // TEST_CASE("Test 2", "[flag]"){
// // 	// you can also use "sections" to share setup code between tests, for example:
// // 	int one = 1;
// //
// // 	SECTION("num is 2") {
// // 		int num = one + 1;
// // 		REQUIRE(num == 2);
// // 	};
// //
// // 	SECTION("num is 3") {
// // 		int num = one + 2;
// // 		REQUIRE(num == 3);
// // 	};
// //
// // 	// each section runs the setup code independently to ensure that they don't affect each other
// // }
// //
// // // you must write 5 unique, meaningful tests for credit on the testing portion of this project!
// //
// // // the provided test from the template is below.
// //
// // TEST_CASE("Example BST Insert", "[flag]"){
// // 	/*
// // 		MyAVLTree tree;   // Create a Tree object
// // 		tree.Insert(3);
// // 		tree.Insert(2);
// // 		tree.Insert(1);
// // 		std::vector<int> actualOutput = tree.TraverseInorder();
// // 		std::vector<int> expectedOutput = {1, 2, 3};
// // 		REQUIRE(expectedOutput.size() == actualOutput.size());
// // 		REQUIRE(actualOutput == expectedOutput);
// // 	*/
// // }
// //
// // TEST_CASE("Input Validation Test" , "[validity]") {
// // 	MyAVLTree tree;
// // 	REQUIRE_FALSE(tree.Insert()nsert("R3ggi3", 10)) ;
// // 	REQUIRE_FALSE(tree.Insert("Reggie", "10"));
// // 	REQUIRE_FALSE(tree.Insert("55", 10 ));
// // 	REQUIRE_FALSE(tree.Insert("Reggie"));
// // 	REQUIRE_FALSE(tree.Insert(10));
// // }
// //
// // TEST_CASE("Tree Rotation Test", "[validity][rotation]") {
// // 	vector<int> expected = {20, 10, 30};
// // 	MyAVLTree tree;  //LL rotation
// // 	tree.Insert("Roggo", 30);
// // 	tree.Insert("Reg", 20);
// // 	tree.Insert("Reggie", 10);
// // 	for (int i = 0; i < expected.size(); i++) {
// // 		REQUIRE(tree.TraversePreorder[i] == expected[i]);
// // 	}
// // 	MyAVLTree tree2; // RR rotation
// // 	tree2.Insert("Reggie", 10);
// // 	tree2.Insert("Reg", 20);
// // 	tree2.Insert("Roggo", 30);
// // 	for (int i = 0; i < expected.size(); i++) {
// // 		REQUIRE(tree2.TraversePreorder[i] == expected[i]);
// // 	}
// // 	MyAVLTree tree3; // LR Rotation
// // 	tree3.Insert("Roggo", 30);
// // 	tree3.Insert("Reggie", 10);
// // 	tree3.Insert("Reg", 20);
// // 	for (int i = 0; i < expected.size(); i++) {
// // 		REQUIRE(tree3.TraversePreorder[i] == expected[i]);
// // 	}
// // 	MyAVLTree tree4; // RL Rotation
// // 	tree4.Insert("Reggie", 10);
// // 	tree4.Insert("Roggo", 30);
// // 	tree4.Insert("Reg", 20);
// // 	for (int i = 0; i < expected.size(); i++) {
// // 		REQUIRE(tree4.TraversePreorder[i] == expected[i]);
// // 	}
// // }
// //
// // TEST_CASE("Batch Insertion and Removal", "[Insertion][functionality]") {
// // 	MyAVLTree tree;
// // 	std::vector<int> vals;
// //
// // 	for (int i = 0; i < 100; i++) {
// // 		tree.Insert("Reggie", i);
// // 		vals.push_back(i);
// // 	}
// //
// // 	for (int i = 0; i < 10; i++) {
// // 		tree.Remove(100-i);
// // 		vals.erase(vals.end()-i);
// // 	}
// //
// // 	REQUIRE(vals.size() == 90);
// // 	for (int i = 0; i < vals.size(); i++) {
// // 		REQUIRE(tree.TraverseInorder()[i] == i);
// // 	}
// //
// // }
//
// #include "catch2/catch_test_macros.hpp"
// TEST_CASE(){
//     REQUIRE(true == true);
// }