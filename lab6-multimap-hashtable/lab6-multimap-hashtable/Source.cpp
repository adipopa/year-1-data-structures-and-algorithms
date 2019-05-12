// 18. ADT MultiMap – using a using a hashtable with separate chaining in which (key, value) pairs are
// stored. If a key has multiple values, it appears in multiple pairs.
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>

using namespace std;
using namespace std::chrono;

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// Run the set of tests from ShortTest.cpp
	testAll();
	cout << "All Short Tests Passed.\n";

	// Run the set of tests from ExtendedTest.cpp
	testAllExtended();
	cout << "All Extended Tests Passed.\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Total runtime: " << duration << " ms.\n";

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}