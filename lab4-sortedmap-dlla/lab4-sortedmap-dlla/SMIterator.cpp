#include "SMIterator.h"

// SMIterator constructor.
// The BC = WC = AC = Theta(1). The overall complexity of the SMIterator(const SortedMap& sm) method is Theta(1).
SMIterator::SMIterator(const SortedMap& sm) : sm(sm) {
	this->dlla = sm.dlla;
	this->currentElement = sm.dlla.head;
}

// Method for resetting the iterator to the first element of the SortedMap.
// The BC = WC = AC = Theta(1). The overall complexity of the first() method is Theta(1).
void SMIterator::first() {
	this->currentElement = sm.dlla.head;
}

// Method for advancing the iterator to the next element of the SortedMap.
// The BC = WC = AC = Theta(1). The overall complexity of the next() method is Theta(1).
void SMIterator::next() {
	if (!this->valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	this->currentElement = this->dlla.nodes[this->currentElement].next;
}

// Method for checking if the validator is valid.
// The BC = WC = AC = Theta(1). The overall complexity of the valid() method is Theta(1).
bool SMIterator::valid() const {
	return this->currentElement != -1;
}

// Method for retrieving the current element from the iterator's position.
// The BC = WC = AC = Theta(1). The overall complexity of the getCurrent() method is Theta(1).
TElem SMIterator::getCurrent() const {
	if (!this->valid()) {
		throw std::runtime_error("Invalid iterator");
	}
	return this->dlla.nodes[this->currentElement].info;
}
