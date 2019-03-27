#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <stdexcept>

// SortedBagIterator constructor.
// // The BC = WC = AC = Theta(1). The overall complexity of the SortedBagIterator(const SortedBag& c) method is Theta(1).
SortedBagIterator::SortedBagIterator(const SortedBag& c) : c(c) {
	currentElem = c.elems;
	currentIt = 0;
}

// Method for resetting the iterator to the first element of the bag.
// // The BC = WC = AC = Theta(1). The overall complexity of the first() method is Theta(1).
void SortedBagIterator::first() {
	currentElem = c.elems;
	currentIt = 0;
}

// Method for advancing the iterator to the next element of the bag.
// // The BC = WC = AC = Theta(1). The overall complexity of the next() method is Theta(1).
void SortedBagIterator::next() {
	if (!valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	currentIt++;
	currentElem++;
}

// Method for checking if the validator is valid.
// The// The BC = WC = AC = Theta(1). The overall complexity of the valid() method is Theta(1).
bool SortedBagIterator::valid() const {
	return currentIt < c.len;
}

// Method for retrieving the current element from the iterator's position.
// // The BC = WC = AC = Theta(1). The overall complexity of the getCurrent() method is Theta(1).
TComp SortedBagIterator::getCurrent() const {
	if (!valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	return *currentElem;
}
