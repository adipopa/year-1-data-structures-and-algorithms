// 18. ADT MultiMap – using a using a hashtable with separate chaining in which (key, value) pairs are
// stored. If a key has multiple values, it appears in multiple pairs.
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "MultiMap.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>

using namespace std;
using namespace std::chrono;

void testKeySet() {
	MultiMap m;

	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	vector<TKey> keySet = m.keySet();
	assert(keySet.size() == 4);
	assert(keySet[0] == 1);
	assert(keySet[1] == 2);
	assert(keySet[2] == 3);
	assert(keySet[3] == 4);
}

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// Run the set of tests from ShortTest.cpp
	testAll();
	cout << "All Short Tests Passed.\n";

	// Run the set of tests from ExtendedTest.cpp
	testAllExtended();
	cout << "All Extended Tests Passed.\n";

	// Test the keySet() method.
	testKeySet();
	cout << "keySet() Test Passed.\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Total runtime: " << duration << " ms.\n";

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}