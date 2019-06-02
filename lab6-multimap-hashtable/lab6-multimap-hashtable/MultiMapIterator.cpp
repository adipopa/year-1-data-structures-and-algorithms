#include "MultiMapIterator.h"

// MultiMapIterator constructor.
// The BC = AC = Theta(1), WC = Theta(m). The overall complexity of the MultiMapIterator(const MultiMap & c) method is O(m).
MultiMapIterator::MultiMapIterator(const MultiMap & c) : c(c) {
	this->ht = c.ht;
	this->currentPos = 0;
	while (this->currentPos < this->ht.capacity && ht.T[this->currentPos] == NULL) {
		this->currentPos++;
	}
	if (this->currentPos < this->ht.capacity) {
		this->currentNode = this->ht.T[this->currentPos];
	}
	else {
		this->currentNode = NULL;
	}
}

// Method for resetting the iterator to the first element of the MultiMapIterator.
// The BC = AC = Theta(1), WC = Theta(m). The overall complexity of the first() method is Theta(m).
void MultiMapIterator::first() {
	this->currentPos = 0;
	while (this->currentPos < this->ht.capacity && ht.T[this->currentPos] == NULL) {
		this->currentPos++;
	}
	if (this->currentPos < this->ht.capacity) {
		this->currentNode = this->ht.T[this->currentPos];
	}
	else {
		this->currentNode = NULL;
	}
}

// Method for advancing the iterator to the next element of the MultiMapIterator.
// The BC = AC = Theta(1), WC = Theta(m). The overall complexity of the next() method is O(m).
void MultiMapIterator::next() {
	if (!this->valid()) {
		throw std::runtime_error("Invalid iterator.");
	}
	this->currentNode = this->currentNode->next;
	if (this->currentNode == NULL) {
		this->currentPos++;
		while (this->currentPos < this->ht.capacity && ht.T[this->currentPos] == NULL) {
			this->currentPos++;
		}
		if (this->currentPos < this->ht.capacity) {
			this->currentNode = this->ht.T[this->currentPos];
		}
		else {
			this->currentNode = NULL;
		}
	}
}

// Method for checking if the validator is valid.
// The BC = WC = AC = Theta(1). The overall complexity of the valid() method is Theta(1).
bool MultiMapIterator::valid() const {
	return this->currentNode != NULL && this->currentPos < this->ht.capacity;
}

// Method for retrieving the current element from the iterator's position.
// The BC = WC = AC = Theta(1). The overall complexity of the getCurrent() method is Theta(1).
TElem MultiMapIterator::getCurrent() const {
	if (!this->valid()) {
		throw std::runtime_error("Invalid iterator.");
	}
	return this->currentNode->info;
}
