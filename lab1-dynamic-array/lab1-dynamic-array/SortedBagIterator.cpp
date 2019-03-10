#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

// SortedBagIterator constructor.
SortedBagIterator::SortedBagIterator(const SortedBag& c) : c(c) {
	currentElem = c.elems;
	currentIt = 0;
}

// Method for resetting the iterator to the first element of the bag.
void SortedBagIterator::first() {
	currentElem = c.elems;
	currentIt = 0;
}

// Method for advancing the iterator to the next element of the bag.
void SortedBagIterator::next() {
	if (valid()) {
		currentIt++;
		currentElem++;
	} else {
		throw std::exception();
	}
}

// Method for checking if the validator is valid.
bool SortedBagIterator::valid() const {
	return currentIt < c.len;
}

// Method for retrieving the current element from the iterator's position.
TComp SortedBagIterator::getCurrent() const {
	if (valid()) {
		return *currentElem;
	}
	else {
		throw std::exception();
	}
}
