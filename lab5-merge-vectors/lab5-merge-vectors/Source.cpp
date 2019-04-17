#include "TestP2.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>

using namespace std;
using namespace std::chrono;

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// Run the set of tests from TestP2.cpp
	testP2();
	cout << "P2 Tests Passed.\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Total runtime: " << duration << " ms.\n";

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}