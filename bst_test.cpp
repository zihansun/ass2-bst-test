/**
 * Testing BST - Binary Search Tree functions
 *
 * This file has series of tests for BST
 * Each test is independent and uses assert statements
 * Test functions are of the form
 *
 *      test_netidXX()
 *
 * where netid is UW netid and XX is the test number starting from 01
 *
 * Test functions can only use the public functions from BST
 * testBSTAll() is called from main in main.cpp
 * testBSTAll calls all other functions
 * @author Multiple
 * @date ongoing
 */

#include <iostream>
#include <sstream>

#include "joshassert.h"
#undef assert
#define assert JOSH_ASSERT

#include <string>

#include "bst.hpp"

using namespace std;

/**
 * Trying to avoid global variables,
 * by creating a singleton class with our visitor functions
 * stringstream SS contains the output from visitor
 */
class TreeVisitor {
 public:
  TreeVisitor() = delete;

  // insert output to SS rather than cout, so we can test it
  static stringstream SS;

  static string GetSS() {
    return SS.str();
  }

  static void ResetSS() {
    SS.str(string());
  }
  // instead of cout, insert item into a string stream
  static void visitor(const string &item) {
    SS << item;
  }

  // instead of cout, insert item into a string stream
  static void visitor(const int &item) {
    SS << item;
  }

  // instead of cout, insert item into a string stream
  static void visitor(const char &item) {
    SS << item;
  }
};

// initialize the static variable
stringstream TreeVisitor::SS;

/**
 * Test functions by Yusuf Pisan
 */

// Testing ==
void test_pisan01() {
  cout << "Starting test_pisan01" << endl;
  cout << "* Testing == and !=" << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  // == and != for empty trees
  assert(b1 == b2 && (!(b1 != b2)));
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  // == and !- for 1-node trees b1, b2, b3
  assert(b1 == b2 && (!(b1 != b2)));
  assert(b1 != b3 && (!(b1 == b3)));
  cout << "Ending test_pisan01" << endl;
}

// Testing == in detail
void test_pisan02() {
  cout << "Starting test_pisan02" << endl;
  cout << "* Testing == and != with more detail" << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");
  b2.Add("a");
  b2.Add("f");
  b2.Add("g");
  b2.Add("x");
  // == for 5-node trees b1, b2
  assert(b1 == b2 && (!(b1 != b2)));

  BST<string> b4(b3);
  // copy constructor for 1-node trees b3, b4
  assert(b3 == b4 && (!(b3 != b4)));

  BST<string> b5(b1);
  // copy constructor for 5-node trees b1, b5
  assert(b1 == b5 && (!(b5 != b1)));

  BST<string> b7("b");
  // 1-param constructor for 1-node trees b3, b7
  assert(b3 == b7 && (!(b3 != b7)));

  cout << "Ending test_pisan02" << endl;
}

// Testing traversal
void test_pisan03() {
  cout << "Starting test_pisan03" << endl;
  cout << "* Testing traversal" << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");
  b2.Add("a");
  b2.Add("f");
  b2.Add("g");
  b2.Add("x");

  TreeVisitor::ResetSS();
  b1.InorderTraverse(TreeVisitor::visitor);
  string result = "acfgx";
  assert(TreeVisitor::GetSS() == result);

  TreeVisitor::ResetSS();
  b1.PreorderTraverse(TreeVisitor::visitor);
  result = "cafgx";
  assert(TreeVisitor::GetSS() == result);

  TreeVisitor::ResetSS();
  b1.PostorderTraverse(TreeVisitor::visitor);
  result = "axgfc";
  assert(TreeVisitor::GetSS() == result);

  cout << "Ending test_pisan03" << endl;
}

/**
 * Test functions by Sample Sample
 */

// Testing samplefunctionality
void test_sample01() {
  cout << "Starting test_sample01" << endl;
  assert(true);
  cout << "Ending test_sample01" << endl;
}

// Test function (primarily Remove) by Anya Biryukova
void test_biryua() {
  BST<string> bt;
  // Removing when there's an empty BST
  bt.Remove("a");
  // Adding nodes
  bt.Add("q");
  bt.Add("u");
  bt.Add("i");
  bt.Add("c");
  bt.Add("k");
  bt.Add("l");
  bt.Add("y");
  assert(bt.NumberOfNodes() == 7);
  // Removing something that doesn't exist
  bt.Remove("z");
  assert(bt.NumberOfNodes() == 7);
  // Removing all nodes individually
  bt.Remove("i");
  assert(bt.NumberOfNodes() == 6);
  assert(!bt.Contains("i"));
  bt.Remove("q");
  assert(bt.NumberOfNodes() == 5);
  assert(!bt.Contains("q"));
  bt.Remove("c");
  bt.Remove("l");
  bt.Remove("u");
  bt.Remove("y");
  bt.Remove("k");
  assert(bt.NumberOfNodes() == 0);
  assert(bt.IsEmpty());
  cout << "Ending test_biryua" << endl;
}

void test_duy3101() {
  BST<int> b1;
  b1.Add(1);
  b1.Add(2);
  b1.Add(3);
  b1.Add(4);
  b1.Add(5);
  b1.Add(6);
  b1.Add(7);
  assert(b1.NumberOfNodes() == 7);
  assert(b1.getHeight() == 7);
  assert(!b1.IsEmpty());

  BST<int> b2 = b1;
  b2.Clear();
  assert(b2.NumberOfNodes() == 0);
  assert(b2.getHeight() == 0);
  assert(b2.IsEmpty());
  b2.Add(1);
  assert(b2.NumberOfNodes() == 1);
  assert(b2.getHeight() == 1);
  assert(!b2.IsEmpty());
  b2.Add(2);
  assert(b2.NumberOfNodes() == 2);
  assert(b2.getHeight() == 2);
  assert(!b2.IsEmpty());
  cout << "Ending test_duy3101" << endl;
}

void test_Jenna90() {
     // One-Parameter constructor
    BST<int> b1(1);
    // Adding items to BST
    b1.Add(4);
    b1.Add(8);
    b1.Add(3);
    b1.Add(12);
    b1.Add(9);
    b1.Add(-24);
    // adding duplicate item
    b1.Add(4);
    TreeVisitor::ResetSS();
    b1.InorderTraverse(TreeVisitor::visitor);
    string result = "-241348912";
    // asserting it outputs without duplicate
    assert(TreeVisitor::GetSS() == result);
    // get the height of the tree
    assert(b1.getHeight() == 5);
    // get the number of nodes in the tree
    assert(b1.NumberOfNodes() == 7);

    // removing values from BST
    // removing root
    assert(b1.Remove(1) == 1);
    // removing 1 child node
    assert(b1.Remove(4) == 1);
    // remove leaf node
    assert(b1.Remove(9) == 1);
    // remove leaf node
    assert(b1.Remove(0) == 0);

    // reset stringstream
    TreeVisitor::ResetSS();
    b1.InorderTraverse(TreeVisitor::visitor);
    result = "-243812";
    // testing that the removal works
    assert(TreeVisitor::GetSS() == result);
    // BST test height after removal
    assert(b1.getHeight() == 3);
    // test number of nodes in BST
    assert(b1.NumberOfNodes() == 4);

    // Yay, you did it!
    cout << "Ending test_Jenna90" << endl;
}

// Test array constructor on pre-sorted list
void test_lizzypld() {
    // create local scope array
    string arr[6]{"a", "b", "c", "x", "y", "z"};
    // construct tree
    BST<string> arrayTree1(arr, 6);
    // test that array is not empty
    assert(!arrayTree1.IsEmpty());
    // test that array has all 6 items
    assert(arrayTree1.NumberOfNodes() == 6);
    // test that array is balanced correctly per assignment specifications
    assert(arrayTree1.getHeight() == 3);

    // create another tree from same array
    BST<string> arrayTree2(arr, 6);
    // test that 2nd array is not empty
    assert(!arrayTree2.IsEmpty());
    // test that 2nd array has all 6 items
    assert(arrayTree2.NumberOfNodes() == 6);
    // test that 2nd array is balanced correctly per assignment specifications
    assert(arrayTree2.getHeight() == 3);
    // confirm that the two trees are identical
    assert(arrayTree1 == arrayTree2);
}

void test_philip12(){
  BST<int> binary(10);
  binary.Add(5);
  binary.Add(15);
  binary.Add(7);
  binary.Add(13);
  binary.Add(3);
  binary.Add(17);
  binary.Add(2);
  binary.Add(12);
  binary.Add(1);
  cout << binary << endl;
  assert(binary.getHeight() == 5);
  assert(binary.NumberOfNodes() == 10);
  cout << "Remove 10" << endl;
  binary.Remove(10);
  assert(binary.NumberOfNodes() == 9);
  binary.Rebalance();
  cout << "Rebalancing" << endl;
  cout << binary << endl;
  binary.Clear();
  assert(binary.IsEmpty());
  cout << "test_philip12 done" << endl;
}

void test_mcmelton() {
  BST<string> test1;
  test1.Add("e");
  test1.Add("f");
  test1.Add("h");
  test1.Add("g");
  test1.Add("j");
  test1.Add("c");
  test1.Add("a");
  test1.Add("b");
  cout << test1 << endl;
  test1.Remove("e");
  cout << test1 << endl;
  bool removeCheck = test1.Remove("e");
  assert(removeCheck == false);
}

void test_samford01() {
    cout << "\n\n* Starting test_samford01 *" << endl;
    //----- constructors and additions -----
    BST<string> b1;
    BST<string> b2;
    BST<string> b3;
    BST<string> b4;

    b1.Add("d");
    b1.Add("a");
    b1.Add("f");
    b1.Add("g");
    b1.Add("x");
    b1.Add("b");
    b1.Add("e");
    b1.Add("c");
    b2.Add("c");
    b2.Add("a");
    b2.Add("f");
    b2.Add("g");
    b2.Add("x");
    b3.Add("b");

    //----- isEmpty -----
    assert(b4.IsEmpty() == true);
    assert(b1.IsEmpty() == false);

    //----- getHeight -----
    assert(b4.getHeight() == 0);
    assert(b3.getHeight() == 1);
    assert(b1.getHeight() == 4);

    //----- NumberOfNodes -----
    assert(b1.NumberOfNodes() == 8);
    assert(b2.NumberOfNodes() == 5);
    assert(b3.NumberOfNodes() == 1);

    //----- Contains / Remove -----
    assert(b1.Contains("g"));
    b1.Remove("g");
    b1.Remove("f");
    b1.Remove("b");
    assert(!(b1.Contains("g")));

    //----- Rebalance -----
    b1.Rebalance();
    cout << "test_samford01 done!" << endl;
}

void test_ravsneha() {
  cout << "SNEHA'S TESTS ARE STARTING" << endl;
  BST<string> b1;
  b1.Add("s");
  b1.Add("n");
  b1.Add("e");
  b1.Add("h");
  b1.Add("a");

  BST<string> b2;
  b2.Add("s");
  b2.Add("n");
  b2.Add("e");
  b2.Add("h");
  b2.Add("a");

  //Print th
  cout << b1 << endl;
  cout << b2 << endl;

  cout << "Testing Equals Operator (true)" << endl;
  bool testBool = (b1==b2);
  assert(testBool == true);

  cout << "Testing Remove (true)" << endl;
  bool testBool1 = b1.Remove("a");
  cout << b1 << endl;
  assert(testBool1 == true);

  cout << "Testing Equals Operator (false)" << endl;
  bool testBool2 = (b1 == b2);
  assert(testBool2 == false);

  cout << "SNEHA'S TESTS ARE COMPLETE" << endl;
}

void test_Nabu99(){
  cout << "Starting tests Nabu99: " << endl;
  BST<int> tree1;
  BST<int> tree2;

  tree1.Add(1);
  tree1.Add(3);
  tree1.Add(2);
  tree1.Add(10);
  tree1.Add(7);
  tree2.Add(2);
  tree2.Add(5);
  tree2.Add(4);

  assert(tree1.IsEmpty() == false);
  assert(tree2.getHeight() == 2);
  assert(tree1.NumberOfNodes() == 5);
  cout << "End tests!!" << endl;
}

void test_dsagredo()
{
	cout << "Initiating test protocol alpha bravo foxtrot dsagredo" << endl;
	BST<string> tree;
	cout << "Testing Contains, Clear, & isEmpty methods" << endl;
	tree.Add("a");
	tree.Add("b");
	tree.Add("c");
	tree.Add("d");
	tree.Add("e");
	// Testing contains
	assert(tree.Contains("c") == true);
	assert(tree.Contains("y") == false);
	// Testing clear/isEmpty
	tree.Clear();
	assert(tree.IsEmpty() == true);
	assert(tree.Contains("c") == false);
	cout << "Ending test protocol alpha bravo foxtrot dsagredo" << endl;
}

void test_iqbalo01(){
    cout << "Starting test_iqbalo01" << endl;
    BST<int> tree1;
    BST<int> tree2;

    tree1.Add(3);
    tree1.Add(2);
    tree1.Add(4);
    tree1.Add(1);
    tree1.Add(6);
    tree1.Add(8);
    tree1.Add(5);

    tree2.Add(3);
    tree2.Add(2);
    tree2.Add(4);
    tree2.Add(1);
    tree2.Add(6);
    tree2.Add(8);
    tree2.Add(5);

    assert(tree1.IsEmpty() == false);
    assert(tree1 == tree2);
    tree1.Remove(3);
    assert(tree1 != tree2);
    cout << "Ending test_iqbalo01" << endl;
}

void test_msorvik01() {
  cout << "beginning tests" << endl;
  // creating a test tree
  BST<string> tester123;
  tester123.Add("a");
  tester123.Add("z");
  tester123.Add("c");
  tester123.Add("w");
  tester123.Add("y");
  tester123.Add("e");
  // creating a second identical test tree
  BST<string> tester345;
  tester345.Add("a");
  tester345.Add("z");
  tester345.Add("c");
  tester345.Add("w");
  tester345.Add("y");
  tester345.Add("e");
  //testing the isEmpty() function
  assert(!tester123.IsEmpty());
  assert(!tester345.IsEmpty());
  //testing the == operator
  assert(tester123 == tester345);
  cout << "testing done" << endl;
}

void test_rileyk9() {
  string arr[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O"};
  BST<string> tree(arr, 15);

  cout << tree << endl;

  tree.Clear();
  tree.Add("A");
  tree.Add("B");
  tree.Add("C");
  tree.Add("D");
  tree.Add("E");
  tree.Add("F");
  tree.Add("G");

  BST<string> tree2;
  tree2.Add("D");
  tree2.Add("F");
  tree2.Add("E");
  tree2.Add("G");
  tree2.Add("B");
  tree2.Add("A");
  tree2.Add("C");

  tree.Rebalance();

  assert(tree == tree2);

  cout << "Done test_rileyk9()" << endl;
}

void test_wot01() {
    BST<int> b1;
    BST<string> b2;
    b1.Add(6);
    b1.Add(5);
    b1.Add(4);
    b1.Add(3);
    b1.Add(2);
    b1.Add(1);

    b1.InorderTraverse(TreeVisitor::visitor);
    string result = "123456";
    assert(TreeVisitor::GetSS() == result);
    TreeVisitor::ResetSS();

    b1.PostorderTraverse(TreeVisitor::visitor);
    assert(TreeVisitor::GetSS() == result);
    TreeVisitor::ResetSS();

    b1.PreorderTraverse(TreeVisitor::visitor);
    result = "654321";
    assert(TreeVisitor::GetSS() == result);
    TreeVisitor::ResetSS();

    // Testing Rebalance for ints
    std::cout << "b1 before rebalance:" << std::endl;
    std::cout << b1 << std::endl;
    b1.Rebalance();
    std::cout << "b1 after rebalance:" << std::endl;
    std::cout << b1 << std::endl;
    b2.Add("b");
    b2.Add("c");
    b2.Add("d");
    b2.Add("a");
    b2.Add("x");

    b2.InorderTraverse(TreeVisitor::visitor);
    assert(TreeVisitor::GetSS() == "abcdx");
    TreeVisitor::ResetSS();

    b2.PostorderTraverse(TreeVisitor::visitor);
    assert(TreeVisitor::GetSS() == "axdcb");
    TreeVisitor::ResetSS();

    b2.PreorderTraverse(TreeVisitor::visitor);
    assert(TreeVisitor::GetSS() == "bacdx");
    TreeVisitor::ResetSS();

    // Testing Rebalance for strings
    std::cout << "b2 before rebalance:" << std::endl;
    std::cout << b2 << std::endl;
    b2.Rebalance();
    b2.Rebalance();
    std::cout << "b2 after rebalance:" << std::endl;
    std::cout << b2 << std::endl;
    assert(b2.IsEmpty() == false);
    b2.Remove("b");
    std::cout << "b2 without b:" << std::endl;
    std::cout << b2 << std::endl;
}

// tests the clear operation of BST
void test_rwarren201() {
    cout << "Starting testBSTClear..." << endl;

    BST<int> b1;
    b1.Add(4);
    b1.Add(2);
    b1.Add(3);
    b1.Add(1);
    b1.Add(5);
    assert(b1.NumberOfNodes() == 5);
    b1.Clear();
    assert(b1.IsEmpty());

    cout << "...Done testBSTClear" << endl;
}

// Tests by Josh Max
void test_joshumax() {
    cout << "Starting " << __func__ << endl;
    // Type construction
    BST<int> bi;
    BST<string> bs;
    BST<bool> bb;
    BST<char> bc;

    // Integer tests
    bi.Add(1);
    bi.Add(2);
    bi.Add(4);
    bi.Add(8);
    bi.Add(16);
    bi.Add(32);
    bi.Add(32);

    TreeVisitor::ResetSS();
    bi.InorderTraverse(TreeVisitor::visitor);
    string result = "12481632";
    assert(TreeVisitor::GetSS() == result);

    // String tests
    bs.Add("a");
    bs.Add("b");
    bs.Add("c");
    bs.Add("d");
    bs.Add("e");
    bs.Add("f");
    bs.Add("g");

    TreeVisitor::ResetSS();
    bs.InorderTraverse(TreeVisitor::visitor);
    result = "abcdefg";
    assert(TreeVisitor::GetSS() == result);

    // Boolean tests (not really useful for a BST
    // but still something good to test)
    bb.Add(false);
    bb.Add(true);

    TreeVisitor::ResetSS();
    bc.InorderTraverse(TreeVisitor::visitor);
    result = "01"; // Print them out as (0,1)
    assert(TreeVisitor::GetSS() == result);

    // Char tests
    bc.Add('h');
    bc.Add('i');
    bc.Add('j');
    bc.Add('k');
    bc.Add('l');
    bc.Add('m');
    bc.Add('n');

    TreeVisitor::ResetSS();
    bc.InorderTraverse(TreeVisitor::visitor);
    result = "hijklmn";
    assert(TreeVisitor::GetSS() == result);

    // Done
    cout << "Ending " << __func__ << endl;

void test_jhpp114() {
  cout << "Starting test_jhpp114" << endl;
  cout << "Test add, numberOfNode function" << endl;
  BST<int> b1;
  b1.Add(1);
  assert(b1.NumberOfNodes() == 1);
  b1.Add(2);
  b1.Add(3);
  b1.Add(4);
  b1.Add(5);
  b1.Add(6);
  assert(b1.Contains(1));
  assert(b1.Contains(2));
  assert(b1.Contains(6));
  assert(!b1.Contains(8));
  cout << "Contain pass" << endl;
  assert(b1.NumberOfNodes() == 6);
  cout << "Pass number of nodes" << endl;
  assert(b1.getHeight() == 6);
  cout << "Testing isEmpty, clear, != operator" << endl;
  cout << "Pass Get Height" << endl;
  assert(b1.IsEmpty() == 0);
  cout << "Pass isEmpty" << endl;
  b1.Clear();
  assert(b1.IsEmpty() == 1);
  assert(b1.NumberOfNodes() == 0);
  cout << "Pass clear" << endl;
  BST<int> b2;
  b2.Add(1);
  assert(b1 != b2);
  cout << "pass !=" << endl;
  cout << "Ending test_jhpp114" << endl;
}

void test_Brian-Hou() {
    cout << "Testing Constructor passing in an array and int" << endl;
    cout << "Also tests InorderTraveral in the process!" << endl;
    string testArray[5] = {"3", "2", "1", "4", "5"};
    int testArrayLength = 5;
    BST<string> b2(testArray, testArrayLength);
    expectedResult = "12345";
    TreeVisitor::ResetSS();
    b2.InorderTraverse(TreeVisitor::visitor);
    assert(TreeVisitor::GetSS() == expectedResult);

    cout << "b2 is now : " << endl;
    cout << b2 << endl;
}

void test_jstew701() {
  cout << "Starting test_jstew701" << endl;
  cout << "* Testing Add, Contains, and Clear" << endl;
  BST<string> b1;
  BST<string> b2;

  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");

  b2.Add("c");
  b2.Add("a");
  b2.Add("e");
  b2.Add("d");

  assert(b1.Contains("a"));
  assert(b1.Contains("f"));
  assert(b1.Contains("g"));
  assert(b1.Contains("x"));
  assert(!(b1.Contains("z")));
  assert(b2.Contains("c"));
  assert(b2.Contains("a"));
  assert(b2.Contains("e"));
  assert(b2.Contains("d"));
  assert(!(b2.Contains("z")));

  b1.Clear();
  assert(b1.IsEmpty());
  cout << "Ending test_jstew701" << endl;
}

//Tests from Drew Kwak. 	
void test_drewtre(){
  cout << "========================= My Tests =========================\n" << endl; 
  BST<string> a1;
  BST<string> a2;
  BST<string> a3; 

  assert(a3 == a3);

  cout << "a3 is an empty tree" << endl; 
  // == and != for empty trees
  assert(a1 == a2 && (!(a1 != a2)));
  a1.Add("c");
  a2.Add("c");
  // == and !- for 1-node trees a1, a2, a3
  assert(a1 == a2 && (!(a1 != a2)));
  a1.Add("a");
  a1.Add("f");
  a1.Add("g");
  a1.Add("x");
  a2.Add("a");
  a2.Add("f");
  a2.Add("g");
  a2.Add("x");

  // Testing various functions. 
  cout << "a1 NumberOfNodes: "  << a1.NumberOfNodes() << endl; 
  cout << "a3 NumberOfNodes: "  << a3.NumberOfNodes() << endl; 
  cout << "a1 GetHeight: "      << a1.getHeight()     << endl; 
  cout << "a3 GetHeight: "      << a3.getHeight()     << endl; 
  cout << "a1 isEmpty: "        << a1.IsEmpty()       << endl; 
  cout << "a3 isEmpty: "        << a3.IsEmpty()       << endl; 
  cout << "a1 Contains a: "     << a1.Contains("a")   << endl; 
  cout << "a1 Contains z: "     << a1.Contains("z")   << endl; 

  BST<string> a4(a1);
  cout << "Testing copy constructor, a4 copies a1"    << endl; 
  cout << "a4 is: " << endl;
  cout << a4 << endl;

  cout << "Clearing a4\n";
  a4.Clear(); 
  assert(a4.IsEmpty() == 1);
  cout << "Testing if a4 is empty: " << a4.IsEmpty()  << endl; 
  cout << "a4 is: " << endl;
  cout << a4 << endl;
  

  assert(a3 != a1); 
  assert(a4 == a3);
  cout << "a3 == a1 is: "       << (a3 == a1)         << endl; 
  cout << "a4 == a3 is: "       << (a4 == a3)         << endl;
  cout << "a3 != a1 is: "       << (a3 != a1)         << endl; 
  cout << "a4 != a3 is: "       << (a4 != a3)         << endl;

  cout << "\n"; 
}

void test_jacoba25() {
  cout << "Jacob's tests are starting" << endl;
  int arr[7] = {1, 2, 3, 4, 5, 6, 7};
  BST<int> tree(arr, 7);

  assert(tree.isEmpty() == false);
  assert(tree.getHeight() == 3);
  assert(tree.contains(1));
  assert(tree.contains(7));
  assert(!tree.contains(8));
}

// checking for adding duplicates
void test_hsokol8() {
  BST<int> b1;
  BST<int> b2;

  assert (b1 == b2);
  b1.Add(4);
  assert (b1 != b2);
  b2.Add(4);
  assert (b1 == b2);
  b2.Add(4);
  assert (b1 == b2);
  b2.Remove(4);
  assert (b1 != b2);
}
	
void test_codyt23(){
    // Create degenerate tree
    BST<double> CodysTree;
    CodysTree.Add(.9);
    CodysTree.Add(.8);
    CodysTree.Add(.7);
    CodysTree.Add(.6);
    CodysTree.Add(.5);
    CodysTree.Add(.4);
    CodysTree.Add(.3);
    CodysTree.Add(.2);
    CodysTree.Add(.1);
    CodysTree.Add(.01);
    CodysTree.Add(.001);
    CodysTree.Add(.0001);
    CodysTree.Add(.00001);
    CodysTree.Add(.000001);
    CodysTree.Add(-.1);

    // Validate that add worked correctly
    assert(CodysTree.getHeight() == 15);
    assert(CodysTree.IsEmpty() == false);
    assert(CodysTree.Contains(1) == false);
    assert(CodysTree.Contains(.5) == true);
    assert(CodysTree.Contains(-.1) == true);

    // Check copy constructor
    BST<double> CodysTree2 = BST<double>(CodysTree);
    assert(CodysTree.NumberOfNodes() == CodysTree2.NumberOfNodes());
    assert(CodysTree.Contains(.2) == true);
    assert(CodysTree.Contains(.0001) == true);
    assert(CodysTree2.Contains(.2) == true);
    assert(CodysTree.Contains(.0001) == true);

    // Check == (and further check copy constructor)
    assert((CodysTree == CodysTree2) == true);

    // Check Rebalance()
    CodysTree.Rebalance();
    assert(CodysTree.getHeight() == 4);
    assert(CodysTree.Contains(.2) == true);

    // Check !=
    assert((CodysTree != CodysTree2) == true);

    // Validate remove
    // Attempt to remove a value not in the tree
    CodysTree.Remove(100);
    // Remove a leaf node from the tree
    CodysTree.Remove(-.1);
    // Remove a node with 1 child
    CodysTree.Remove(.000001);
    // Remove a node with 2 children
    CodysTree.Remove(.8);
    assert(CodysTree.Contains(-.1) == false);
    assert(CodysTree.Contains(.000001) == false);
    assert(CodysTree.Contains(.8) == false);
    assert(CodysTree.Contains(.00001) == true);
    assert(CodysTree.Contains(.7) == true);
    assert(CodysTree.Contains(.9) == true);
}

void test_bazenn01() {
    cout << "Starting test_bazenn01" << endl;
    cout << "* Testing Traversal Order" << endl;
    BST<int> test;
    test.Add(8);
    test.Add(2);
    test.Add(7);
    test.Add(3);
    test.Add(9);
    test.Add(1);
    test.Add(4);
    test.Add(5);

    TreeVisitor::ResetSS();
    test.InorderTraverse(TreeVisitor::visitor);
    string result = "12345789";
    assert(TreeVisitor::GetSS() == result);

    TreeVisitor::ResetSS();
    test.PreorderTraverse(TreeVisitor::visitor);
    result = "82173459";
    assert(TreeVisitor::GetSS() == result);

    TreeVisitor::ResetSS();
    test.PostorderTraverse(TreeVisitor::visitor);
    result = "15437298";
    assert(TreeVisitor::GetSS() == result);

    cout << "Ending test_bazen01" << endl;
}

//Test by Khiam Rehman	
void test_khiam01() {
  cout << "Starting test_khiam01" << endl;
  cout << "Testing numberOfNodes()" << endl;

  BST<int> testTree;
  testTree.Add(15);
  testTree.Add(65);
  testTree.Add(17);
  testTree.Add(75);
  testTree.Add(96);
  testTree.Add(12);
  testTree.Add(45);
  testTree.Add(32);
  testTree.Add(11);
  testTree.Add(71);
  assert(testTree.NumberOfNodes() == 10);

  testTree.Remove(45);
  testTree.Remove(32);
  testTree.Remove(11);
  testTree.Remove(11);
  assert(testTree.NumberOfNodes() == 7)

  cout << "Ending test_khiam01" << endl;
}

void test_mkhsu01() {
  cout << "Starting test_mkhsu" << endl;

  BST<char> alphaTree;
  alphaTree.Add('a');
  alphaTree.Add('b');
  alphaTree.Add('c');
  alphaTree.Add('d');
  alphaTree.Add('e');
  alphaTree.Add('f');
  alphaTree.Add('g');
  alphaTree.Add('h');
  alphaTree.Add('i');
  alphaTree.Add('j');
  alphaTree.Add('k');
  alphaTree.Add('l');
  alphaTree.Add('m');
  alphaTree.Add('n');
  alphaTree.Add('o');
  alphaTree.Add('p');
  alphaTree.Add('q');
  alphaTree.Add('r');
  alphaTree.Add('s');
  alphaTree.Add('t');
  alphaTree.Add('u');
  alphaTree.Add('v');
  alphaTree.Add('w');
  alphaTree.Add('x');
  alphaTree.Add('y');
  alphaTree.Add('z');

  assert(alphaTree.NumberOfNodes() == 26);
  assert(alphaTree.getHeight() == 26);

  TreeVisitor::ResetSS();
  alphaTree.InorderTraverse(TreeVisitor::visitor);
  string result = "abcdefghijklmnopqrstuvwxyz";

  assert(TreeVisitor::GetSS() == result);

  alphaTree.Rebalance();
  assert(alphaTree.NumberOfNodes() == 26);
  assert(alphaTree.getHeight() == 5);


  string randAlpha = "ycfmhokpldnuraztiwbjqxvesg";
  const char *c_str_randAlpha = randAlpha.c_str();

  BST<char> alphaTree2(c_str_randAlpha, 26);
  assert(alphaTree2.NumberOfNodes() == 26);
  assert(alphaTree2.getHeight() == 5);

  assert(alphaTree == alphaTree2);

  BST<char> alphaTree3;
  alphaTree3.Add('n');
  alphaTree3.Add('u');
  alphaTree3.Add('g');
  alphaTree3.Add('d');
  alphaTree3.Add('k');
  alphaTree3.Add('r');
  alphaTree3.Add('x');
  alphaTree3.Add('w');
  alphaTree3.Add('z');
  alphaTree3.Add('t');
  alphaTree3.Add('p');
  alphaTree3.Add('f');
  alphaTree3.Add('b');
  alphaTree3.Add('i');
  alphaTree3.Add('m');
  alphaTree3.Add('y');
  alphaTree3.Add('s');
  alphaTree3.Add('l');
  alphaTree3.Add('e');
  alphaTree3.Add('a');
  alphaTree3.Add('h');
  alphaTree3.Add('o');
  alphaTree3.Add('v');
  alphaTree3.Add('q');
  alphaTree3.Add('j');
  alphaTree3.Add('c');

  assert(alphaTree == alphaTree3);
  assert(alphaTree3 == alphaTree2);

  cout << "Ending test_mkhsu" << endl;
}
	
// Calling all test functions
void testBSTAll() {
  test_pisan01();
  test_pisan02();
  test_pisan03();
  test_sample01();
  test_biryua();
  test_duy3101();
  test_Jenna90();
  test_lizzypld();
  test_philip12();
  test_mcmelton();
  test_samford01();
  test_ravsneha();
  test_Nabu99();
  test_dsagredo();
  test_iqbalo01();
  test_msorvik01();
  test_rileyk9();
  test_wot01();
  test_rwarren201();
  test_joshumax();
  test_jhpp114();
  test_Brian-Hou();
  test_jstew701();
  test_drewtre();
  test_jacoba25();
  test_hsokol8();
  test_codyt23();
  test_bazenn01();
  test_khiam01();
  test_mkhsu01();
}

TEST_CASE("BST Tests") {
  testBSTAll();
}
