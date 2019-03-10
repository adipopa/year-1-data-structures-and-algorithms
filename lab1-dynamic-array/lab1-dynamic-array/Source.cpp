#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {
	// Run the set of tests from ShortTest.cpp
	testAll();

	// Run the set of tests from ExtendedTest.cpp
	testAllExtended();

	cout << "All Tests Passed.\n";
	system("pause");
	return 0;
}
