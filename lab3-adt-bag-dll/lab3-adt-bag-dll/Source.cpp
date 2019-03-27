#define _CRTDBG_MAP_ALLOC

#include "ShortTest.h"
#include "ExtendedTest.h"
#include "Bag.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>

using namespace std;
using namespace std::chrono;

void testIntersection() {
	Bag b1;
	b1.add(5);
	b1.add(1);
	b1.add(4);
	b1.add(7);
	b1.add(-3);

	Bag b2;
	b2.add(1);
	b2.add(4);
	b2.add(3);
	b2.add(4);
	b2.add(-2);

	Bag bu;
	assert(bu.isEmpty() == true);
	bagUnion(bu, b1, b2);
	assert(bu.size() == 7);
	assert(bu.search(5) == true);
	assert(bu.search(3) == true);
	assert(bu.search(-3) == true);
	assert(bu.nrOccurrences(4) == 1);
}

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// Run the set of tests from ShortTest.cpp
	testAll();
	cout << "All Short Tests Passed.\n";

	// Run the set of tests from ExtendedTest.cpp
	testAllExtended();
	cout << "All Extended Tests Passed.\n";

	// Testing the intersection(Bag b1, Bag b1, Bag b2) method:
	testIntersection();


	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Total runtime: " << duration << " ms.\n";

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}
