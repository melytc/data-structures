// Test made by Hector Rincon.

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// testing:
// 	[] operator get
// 	pushBack
// 	push
// 	int first
// 	int size
// 	void empty
// 	bool isEmpty
// 	frontBackSplit
// 	insertAt
// 	int pop()

// bool isEmpty()
TEST_CASE("isEmpty operation correctly returns whether a list is empty", "[LinkedList]"){
	LinkedList<int> a;
	REQUIRE(a.isEmpty());
	a.pushBack(10);
	a.pushBack(20);
	a.pushBack(30);
	REQUIRE_FALSE(a.isEmpty());
}

// [] operator
TEST_CASE("[] operator returns the correct value for position i", "[LinkedList]") {
	LinkedList<int> a;
	CHECK_THROWS(a[0]);
	a.pushBack(10);
	a.pushBack(20);
	a.pushBack(30);
	REQUIRE_THROWS(a[-1]);
	REQUIRE(a[2]== 30);
	REQUIRE(a[1] == 20);
	REQUIRE(a[0] == 10);
}

// void pushBack(int)
TEST_CASE("pushBack() correctly appends to the end of the list", "[LinkedList]") {
	LinkedList<int> a;
	REQUIRE(a.root == NULL);
	a.pushBack(10);
	REQUIRE(a.root != NULL);
	REQUIRE(a[0] == 10);
	a.pushBack(20);
	REQUIRE(a[1] == 20);
	a.pushBack(30);
	REQUIRE(a[2] == 30);
	a.pushBack(40);
	REQUIRE(a[3] == 40);
	REQUIRE(a.size() == 4);
	a.pushBack(50);
	a.pushBack(60);
	a.pushBack(70);
	a.pushBack(80);
	REQUIRE(a.size() == 8);
}

// void push(int)
TEST_CASE("push() correctly adds to the beginning of the list", "[LinkedList]") {
	LinkedList<int> a;
	a.push(10);
	REQUIRE(a.first() == 10);
	a.push(20);
	REQUIRE(a.first() == 20);
	a.push(30);
	REQUIRE(a.root->data == 30);
	REQUIRE(a.size() == 3);
}

// int first()
TEST_CASE("first() returns the first element of the list", "[LinkedList]") {
	LinkedList<int> a;
	REQUIRE(a.root == NULL);
	a.pushBack(10);
	REQUIRE(a.root->data == a.first());	
	a.pushBack(20);
	REQUIRE(a.root->data == a.first());	
}

// int size()
TEST_CASE("size() returns the correct size of the list", "[LinkedList]") {
	LinkedList<int> a;
	REQUIRE(a.size() == 0);
	a.pushBack(10);
	REQUIRE(a.size() == 1);
	a.pushBack(10);
	a.pushBack(10);
	a.pushBack(10);
	a.pushBack(10);
	a.pushBack(10);
	a.pushBack(10);
	a.pushBack(10);
	REQUIRE(a.size() == 8);
	a.pop();
	REQUIRE(a.size() == 7);
	a.push(10);
	REQUIRE(a.size() == 8);
	a.push(9);
	REQUIRE(a.size() == 9);
	a.makeEmpty();
	REQUIRE(a.size() == 0);
}

// void empty()
TEST_CASE("empty() correctly destroys the list and sets root to NULL", "[LinkedList]") {
	LinkedList<int> a;
	a.pushBack(10);	
	a.pushBack(20);	
	a.pushBack(30);	
	REQUIRE(a.root != NULL);
	REQUIRE(a.size() != 0);
	a.makeEmpty();
	REQUIRE(a.size() == 0);
	REQUIRE(a.root == NULL);
}


/* // FrontBackSplit()
TEST_CASE("FrontBackSplit() correctly returns the two halves", "[LinkedList]") {
	LinkedList<int> a;
	a.pushBack(10);
	a.pushBack(20);
	a.pushBack(30);
	a.pushBack(40);
	// General test case for even-numbered lists
	node<int> *x = new node<int>();
	node<int> *y = new node<int>();
	a.frontBackSplit(&x, &y);
	REQUIRE(x->data == 10);
	REQUIRE(x->next->data == 20);
	REQUIRE(x->next->next == NULL);
	REQUIRE(y->data == 30);
	REQUIRE(y->next->data == 40);
	REQUIRE(y->next->next == NULL);

	// Case for length() == 1
	// cout << "FBSplit: Handle the case when length is 1 (both should point to the root)." << endl;
	a.makeEmpty();
	a.pushBack(10);
	a.frontBackSplit(&x, &y);
	
	REQUIRE(x->data == 10);
	REQUIRE(x == y);
	REQUIRE(y->data == 10);
	REQUIRE(x->next == NULL);
	REQUIRE(y->next == NULL);

	// Clean up
	delete x;
	delete y;
	x = NULL;
	y = NULL;

} */
/* TEST_CASE("FrontBackSplit(): in odd-numbered lists the extra element is in the front list", "[LinkedList]") {
	LinkedList<int> a;
	a.pushBack(10);
	a.pushBack(20);
	a.pushBack(30);
	node<int> * x = new node<int>();
	node<int> * y = new node<int>();

	a.frontBackSplit(&x, &y);
	REQUIRE(x->data == 10);
	REQUIRE(x->next->data == 20);
	REQUIRE(y->data == 30);
	REQUIRE(y->next == NULL);

} */

// void insertAt(int, int)
TEST_CASE("insertAt(i) correctly inserts a new item at position i \n(provided i is in the range [0, length])", "[LinkedList]") {
	LinkedList<int> a;
	a.pushBack(10);
	a.insertAt(1, 20);
	REQUIRE(a.size() == 2);
	REQUIRE(a[1] == 20);
	a.insertAt(1, 15);
	REQUIRE(a.size() == 3);
	REQUIRE(a[1] == 15);
	a.insertAt(0, 200);
	REQUIRE(a[0] == 200);
	REQUIRE(a.first() == 200);
}

// int pop()
TEST_CASE("pop() correctly returns the first element", "[LinkedList]") {
	LinkedList<int> x;
	x.pushBack(1);
	x.pushBack(2);
	x.pushBack(3);
	int a = x.pop();
	int b = x.pop();
	int c = x.pop();
	REQUIRE(a == 1);
	REQUIRE(b == 2);
	REQUIRE(c == 3);
	REQUIRE(x.size() == 0);
	REQUIRE(x.isEmpty());
}

TEST_CASE("pop() correctly removes the first element from the list", "[LinkedList]") {
	LinkedList<int> x;
	x.pushBack(10);
	x.push(20);
	x.pop();
	REQUIRE(x.size() == 1);
	REQUIRE(x.first() == 10);
}
