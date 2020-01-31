#include "array.h"
#include "object.h"
#include "string.h"
#include <assert.h>
#include <stdlib.h>
#include <iostream>

void testArray() {
    Object* o1 = new Object();
    Object* o2 = new Object();
	Array* t1 = new Array(1);

	assert(t1->size() == 1);
	t1->add(0, o1);
	assert(t1->size() == 1);
	
	t1->remove(0);
	assert(t1->size() == 1);
	t1->pushback(o1);
	assert(t1->size() == 2);
	assert(t1->get(1)->equals(o1));
	
	delete o1;
	delete o2;
	delete t1;

	printf("Passed Array tests\n");
}

void testStringArray() {
	String* s1 = new String("Hello");
	String* s2 = new String("World");
	String* s3 = new String("Testing");

	StringArray* sa1 = new StringArray(1);
	StringArray* sa2 = new StringArray(1);

	sa1->add(0, s1);
	sa2->add(0, s1);
	assert(sa1->equals(sa2));
	assert(sa1->size() == 1);
	assert(sa1->get(0)->equals(s1));
	sa1->add(0, s2);
	assert(sa1->size() == 1);
	assert(!sa1->equals(sa2));
	sa1->add(1, s1);
	assert(sa1->size() == 2);
	assert(sa1->get(0)->equals(s2));
	assert(sa1->get(1)->equals(s1));

	delete s1;
	delete s2;
	delete s3;

	delete sa1;
	delete sa2;
	printf("Passed StringArray tests\n");
}

void testIntArray() {
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;

	IntArray* ia1 = new IntArray(1);
	IntArray* ia2 = new IntArray(1);



	delete ia1;
	delete ia2;
	printf("Passed IntArray tests\n");
}

void testBoolArray() {
	BoolArray* ba1 = new BoolArray(1);
	BoolArray* ba2 = new BoolArray(1);

	delete ba1;
	delete ba2;
	printf("Passed BoolArray tests\n");
}

void testFloatArray() {
	FloatArray* fa1 = new FloatArray(1);
	FloatArray* fa2 = new FloatArray(1);



	delete fa1;
	delete fa2;
	printf("Passed FloatArray tests\n");
}

int main() {
    testArray();
    testStringArray();
    testIntArray();
    testBoolArray();
    testFloatArray();
    return 0;
}

// /**
//  * ArrayTestFrame: this class represents a series of tests to verify that the Array class 
//  *                 works as inteded
//  * 
//  * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
//  */
// class ArrayTestFrame
// {
// public:
//     Object *nothing; // blank object

//     String *hello;   // String containing "hello"
//     String *goodbye; // String containing "goodbye"
//     String *zebra;   // String containing "zebra"

//     Array *empty;         // Blank Array of size 0
//     Array *tensize;       // Blank Array of size 10
//     Array *threeunsorted; // Unsorted Array of size 3 with 3 Strings in it
//     Array *threesorted;   // Sorted Array of size 3 with 3 String in it
//     Array *halfempty;     // Array of size 4 with 2 Strings in it

//     /**
//      * Constructor for the test class which sets the base values for the tests
//      */
//     ArrayTestFrame()
//     {
//         setup();
//     }

//     /**
//      * Destructor for the ArrayTestFrame. 
//      */
//     ~ArrayTestFrame()
//     {
//         delete nothing;
//         delete hello;
//         delete goodbye;
//         delete zebra;
//         delete empty;
//         delete tensize;
//         delete threeunsorted;
//         delete threesorted;
//         delete halfempty;
//     }

//     /**
//      * Sets the initial values for the fields in the class. 
//      */
//     void setup()
//     {
//         nothing = new Object();

//         hello = new String("hello");
//         goodbye = new String("goodbye");
//         zebra = new String("zebra");

//         empty = new Array(0);
//         tensize = new Array(10);
//         threeunsorted = new Array(3);
//         threesorted = new Array(3);
//         threeunsorted = new Array(3);
//         halfempty = new Array(2);

//         threesorted->add(0, goodbye);
//         threesorted->add(1, hello);
//         threesorted->add(2, zebra);

//         threeunsorted->add(0, zebra);
//         threeunsorted->add(1, hello);
//         threeunsorted->add(2, goodbye);

//         halfempty->add(0, hello);
//         halfempty->add(1, goodbye);
//     }

//     /**
//      * Exits the program with an exit code for not succesful. 
//      */
//     void FAIL()
//     {
//         exit(1);
//     }

//     /**
//      * Prints a message representing all of the tests having passed in the test method.
//      */
//     void OK(const char *m)
//     { /** print m */
//         std::cout << m << "\n";
//     }

//     /**
//      * Triggers the fail method if the passed in value is not true.
//      */
//     void t_true(bool p)
//     {
//         if (!p)
//             FAIL();
//     }

//     /**
//      * Triggers the fail method if the passed in value is not false.
//      */
//     void t_false(bool p)
//     {
//         if (p)
//             FAIL();
//     }

//     /**
//      * Series of tests to verify that the size method of the Array class works correctly. 
//      * 
//      * Prints "Size Test Passed" if all tests passed, exits otherwise. 
//      */
//     void testSize()
//     {
//         setup();
//         t_true(empty->size() == 0);
//         t_true(tensize->size() == 10);
//         OK("Size Test Passed");
//     }

//     /**
//      * Series of tests to verify that the length method of the Array class works correctly.
//      * 
//      * Prints "Length Test Passed" if all tests passed, exits otherwise. 
//      */
//     void testLength()
//     {
//         setup();
//         t_true(threeunsorted->length() == 3);
//         t_true(halfempty->length() == 2);
//         OK("Length Test Passed");
//     }

//     *
//      * Series of tests to verify that the add method of the Array class works correctly.
//      * 
//      * Prints "Add Test Passed" if all tests passed, exits otherwise.
     
//     void testAdd()
//     {
//         setup();
//         tensize->add(4, hello);
//         t_true(tensize->get(4)->equals(hello));

//         OK("Add Test Passed");
//     }

//     /**
//      * Series of tests to verify that the remove method of the Array class works correctly.
//      * 
//      * Prints "Remove Tests Passed" if all tests passed, exits otherwise.
//      */
//     void testRemove()
//     {
//         setup();
//         tensize->add(4, hello);
//         t_true(tensize->get(4)->equals(hello));

//         tensize->remove(4);
//         t_true(tensize->get(4)->equals(nothing));

//         OK("Remove Tests Passed");
//     }

//     /**
//      * Series of tests to verify that the get method of the Array class works crrectly.
//      * 
//      * Prints "Get Tests Passed" if all tests passed, exits otherwise. 
//      */
//     void testGet()
//     {
//         setup();
//         t_true(threesorted->get(1)->equals(hello));

//         OK("Get Tests Passed");
//     }

//     /**
//      * Test to verify that the Array class sorts an Array correctly if the sort method is called. 
//      * 
//      * Prints "Sort Test Passed" if the test is passed, exits otherwise.
//      */
//     void testSort()
//     {
//         setup();

//         t_true(threeunsorted->get(0)->equals(zebra));
//         t_true(threeunsorted->get(1)->equals(hello));
//         t_true(threeunsorted->get(2)->equals(goodbye));

//         threeunsorted->sort();

//         t_true(threeunsorted->get(0)->equals(goodbye));
//         t_true(threeunsorted->get(1)->equals(hello));
//         t_true(threeunsorted->get(2)->equals(zebra));

//         OK("Sort Test Passed");
//     }

//     /**
//      * Test to verify that the Array class keeps a sorted list sorted if the sort method is called on it. 
//      * 
//      * Prints "Already Sorted Array Test Passed" if the test is passed, exits otherwise. 
//      */
//     void testAlreadySorted()
//     {
//         setup();

//         t_true(threesorted->get(0)->equals(goodbye));
//         t_true(threesorted->get(1)->equals(hello));
//         t_true(threesorted->get(2)->equals(zebra));

//         threesorted->sort();

//         t_true(threesorted->get(0)->equals(goodbye));
//         t_true(threesorted->get(1)->equals(hello));
//         t_true(threesorted->get(2)->equals(zebra));

//         OK("Already Sorted Array Test Passed");
//     }

//     /**
//      * Test to verify that the equals function can tell when two arrays are equal and when they are not. 
//      * 
//      * Prints "Equals Test Passed" if the test is passed, exits otherwise.
//      */
//     void testEquals()
//     {
//         setup();
//         t_true(threeunsorted->equals(threeunsorted));
//         t_false(threeunsorted->equals(threesorted));
//         OK("Equals Test Passed");
//     }

//     /**
//      * Test to verify that the hash function returns the correct hash value when called.
//      * 
//      * Prints "Hash Test Passed" if the test is passed, exits otherwise.
//      */
//     void testHash()
//     {
//         setup();
//         t_true(threesorted->hash() == threesorted->hash());
//         t_false(threesorted->hash() == threeunsorted->hash());
//         OK("Hash Test Passed");
//     }
// };

// /**
//  * Runs the tests in the ArrayTestFrame class. 
//  */
// int main()
// {
//     ArrayTestFrame *test = new ArrayTestFrame();
//     printf(int);
//     test->testAdd();
//     test->testGet();
//     test->testLength();
//     test->testRemove();
//     test->testSize();
//     test->testSort();
//     test->testAlreadySorted();
//     test->testEquals();
//     test->testHash();
//     delete test;
//     return 0;
// };