#include "array.h"
#include "object.h"
#include "string.h"
#include <assert.h>
#include <stdlib.h>
#include <iostream>

bool fequals_(float a, float b) {
	return fabs(a-b) < a * 0.001;
}

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
	StringArray* sa3 = new StringArray(1);

	sa1->add(0, s1);
	sa2->add(0, s1);

	assert(sa1->equals(sa2));
	assert(sa1->hash() == sa2->hash());
	assert(sa1->size() == 1);
	assert(sa1->get(0)->equals(s1));

	sa1->add(0, s2);
	sa3->add(0, s2);
	
	assert(sa1->size() == 1);
	assert(!sa1->equals(sa2));

	sa1->add(1, s1);
	sa3->add(1, s1);

	assert(sa1->hash() == sa2->hash());
	assert(sa1->size() == 2);
	assert(sa1->get(0)->equals(s2));
	assert(sa1->get(1)->equals(s1));
	sa1->pushback(s3);
	assert(sa1->size() == 4);
	assert(sa1->get(2)->equals(s3));
	assert(sa1->hash() == s3->hash());

	sa1->remove(0);
	assert(sa1->get(0) == NULL);

	delete s1;
	delete s2;
	delete s3;

	delete sa1;
	delete sa2;
	delete sa3;
	printf("Passed StringArray tests\n");
}

void testIntArray() {

	IntArray* ia1 = new IntArray(1);
	IntArray* ia2 = new IntArray(1);
	IntArray* ia3 = new IntArray(3);

	ia1->add(0, 1);
	ia2->add(0, 1);
	assert(ia1->equals(ia2));
	assert(ia1->size() == 1);
	assert(ia1->get(0) == 1);
	ia1->add(0, 2);
	assert(ia1->size() == 1);
	assert(ia1->get(0) == 2);
	assert(!ia1->equals(ia2));
	ia1->add(1, 2);
	assert(ia1->size() == 2);
	assert(ia1->get(0) == 2);
	assert(ia1->get(1) == 2);
	ia1->pushback(3);
	assert(ia1->size() == 4);
	assert(ia1->get(2) == 3);

	ia3->add(0, 2);
	ia3->add(1, 2);
	ia3->add(2, 3);

	assert(ia1->equals(ia3));
	assert(ia1->hash() == ia3->hash());

	ia1->remove(0);
	assert(ia1->get(0) == NULL);

	delete ia1;
	delete ia2;
	delete ia3;
	printf("Passed IntArray tests\n");
}

void testBoolArray() {

	BoolArray* ba1 = new BoolArray(1);
	BoolArray* ba2 = new BoolArray(1);
	BoolArray* ba3 = new BoolArray(3);

	ba1->add(0, false);
	ba2->add(0, false);
	assert(ba1->equals(ba2));
	assert(ba1->size() == 1);
	assert(ba1->get(0) == false);
	ba1->add(0, true);
	assert(ba1->size() == 1);
	assert(ba1->get(0) == true);
	assert(!ba1->equals(ba2));
	ba1->add(1, true);
	assert(ba1->size() == 2);
	assert(ba1->get(0) == true);
	assert(ba1->get(1) == true);
	ba1->pushback(false);
	assert(ba1->size() == 4);
	assert(ba1->get(2) == (false));

	ba3->add(0, true);
	ba3->add(1, true);
	ba3->add(2, false);
	assert(ba1->equals(ba3));
	assert(ba1->hash() == ba3->hash());

	ba1->remove(0);
	assert(ba1->get(0) == NULL);


	delete ba1;
	delete ba2;
	delete ba3;
	printf("Passed BoolArray tests\n");
}

void testFloatArray() {
	FloatArray* fa1 = new FloatArray(1);
	FloatArray* fa2 = new FloatArray(1);
	FloatArray* fa3 = new FloatArray(3);

	fa1->add(0, 1.212);
	fa2->add(0, 1.212);
	assert(fa1->equals(fa2));
	assert(fa1->size() == 1);
	assert(fequals_(fa1->get(0), 1.212));
	fa1->add(0, 2.34);
	assert(fa1->size() == 1);
	assert(fequals_(fa1->get(0), 2.34));
	assert(!fa1->equals(fa2));
	fa1->add(1, 4.32);
	assert(fa1->size() == 2);
	assert(fequals_(fa1->get(0), 2.34));
	assert(fequals_(fa1->get(1), 4.32));
	fa1->pushback(1.01);
	assert(fa1->size() == 4);
	assert(fequals_(fa1->get(2), 1.01));

	fa3->add(0, 2.34);
	fa3->add(1, 4.32);
	fa3->add(2, 1.01);

	assert(fa1->equals(fa3));
	assert(fa1->hash() == fa3->hash());


	fa1->remove(0);
	assert(fa1->get(0) == NULL);

	delete fa1;
	delete fa2;
	delete fa3;
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
