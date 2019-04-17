// 18. ADT SortedMap – using a DLLA with (key, value) pairs ordered based on a relation on the keys.
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedMap.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>

using namespace std;
using namespace std::chrono;

bool relation(TKey c1, TKey c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}

void testAddIfNotPresent() {
	SortedMap sm(relation);
	sm.add(1, 7);
	sm.add(3, 4);
	sm.add(4, 1);
	sm.add(7, 9);

	SortedMap sm2(relation);
	sm2.add(1, 2);
	sm2.add(1, 4);
	sm2.add(2, 4);
	sm2.add(3, 6);
	sm2.add(5, 3);
	sm2.add(6, 8);
	sm2.add(7, 2);

	int cnt = sm.addIfNotPresent(sm2);
	assert(cnt == 3);
	assert(sm.size() == 7);
	assert(sm.search(1) == 7);
	assert(sm.search(2) == 4);
	assert(sm.search(3) == 4);
	assert(sm.search(4) == 1);
	assert(sm.search(5) == 3);
	assert(sm.search(6) == 8);
	assert(sm.search(7) == 9);
}

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// Run the set of tests from ShortTest.cpp
	testAll();
	cout << "All Short Tests Passed.\n";

	// Run the set of tests from ExtendedTest.cpp
	testAllExtended();
	cout << "All Extended Tests Passed.\n";

	// Test addIfNotPresent(SortedMap& sm) method.
	testAddIfNotPresent();
	cout << "addIfNotPresent(SortedMap& sm) Test Passed.\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Total runtime: " << duration << " ms.\n";

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}