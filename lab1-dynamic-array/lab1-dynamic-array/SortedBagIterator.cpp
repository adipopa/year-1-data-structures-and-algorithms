#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <stdexcept>

// SortedBagIterator constructor.
SortedBagIterator::SortedBagIterator(const SortedBag& c) : c(c) {
	currentElem = c.elems;
	currentIt = 0;
}

// Method for resetting the iterator to the first element of the bag.
// The complexity of the first() method is O(1).
void SortedBagIterator::first() {
	currentElem = c.elems;
	currentIt = 0;
}

// Method for advancing the iterator to the next element of the bag.
// The complexity of the next() method is O(1).
void SortedBagIterator::next() {
	if (valid()) {
		currentIt++;
		currentElem++;
	} else {
		throw std::runtime_error("Invalid Iterator");
	}
}

// Method for checking if the validator is valid.
// The complexity of the valid() method is O(1).
bool SortedBagIterator::valid() const {
	return currentIt < c.len;
}

// Method for retrieving the current element from the iterator's position.
// The complexity of the getCurrent() method is O(1).
TComp SortedBagIterator::getCurrent() const {
	if (valid()) {
		return *currentElem;
	}
	else {
		throw std::runtime_error("Invalid Iterator");
	}
}
