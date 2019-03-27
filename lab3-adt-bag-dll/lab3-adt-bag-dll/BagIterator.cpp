#include "BagIterator.h"
#include "Bag.h"
#include <stdexcept>

// BagIterator constructor.
// The BC = WC = AC = Theta(1). The overall complexity of the BagIterator(const Bag& b) method is Theta(1).
BagIterator::BagIterator(const Bag& b) : b(b) {
	currentElem = b.bagDll->head;
	currentFreq = 1;
}

// Method for resetting the iterator to the first element of the bag.
// The BC = WC = AC = Theta(1). The overall complexity of the first() method is Theta(1).
void BagIterator::first() {
	currentElem = b.bagDll->head;
	currentFreq = 1;
}

// Method for advancing the iterator to the next element of the bag.
// The BC = WC = AC = Theta(1). The overall complexity of the next() method is Theta(1).
void BagIterator::next() {
	if (!valid()) {
		throw std::runtime_error("Invalid iterator");
	}

	if (currentFreq < currentElem->freq) {
		currentFreq++;
	}
	else {
		currentElem = currentElem->next;
		currentFreq = 1;
	}

}

// Method for checking if the validator is valid.
// The BC = WC = AC = Theta(1). The overall complexity of the valid() method is Theta(1).
bool BagIterator::valid() const {
	return currentElem != NULL;
}

// Method for retrieving the current element from the iterator's position.
// The BC = WC = AC = Theta(1). The overall complexity of the getCurrent() method is Theta(1).
TElem BagIterator::getCurrent() const {
	if (!valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	return currentElem->elem;
}
