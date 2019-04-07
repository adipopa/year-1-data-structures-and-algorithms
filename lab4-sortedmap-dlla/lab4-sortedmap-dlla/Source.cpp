// 18. ADT SortedMap – using a DLLA with (key, value) pairs ordered based on a relation on the keys.
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>

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