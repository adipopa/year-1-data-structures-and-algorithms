#include "Heap.h"
#include <stdexcept>

// Heap constructor.
// The BC = WC = AC = Theta(1). The complexity of the Heap(Relation rel) method is Theta(1).
Heap::Heap(Relation rel) {
	this->capacity = INIT_CAPACITY;
	this->length = 0;
	this->elems = new TElem[this->capacity];
	this->relation = rel;
}

// Method for pushing an element into the Heap.
// The BC = Theta(1), WC = Theta(n), AC = Theta(log2n). The overall complexity of the addToHeap(TElem elem) method is O(log2n).
void Heap::addToHeap(TElem elem) {
	if (this->length == this->capacity) {
		this->resizeHeap();
	}
	this->elems[this->length] = elem;
	this->length++;
	this->bubbleUp(this->length - 1);
}

// Method for resizing the Heap.
// The BC = WC = AC = Theta(n). The overall complexity of the resizeHeap() method is Theta(n).
void Heap::resizeHeap() {
	this->capacity *= 2;
	TElem* newElems = new TElem[this->capacity];
	for (int i = 0; i < this->length; i++) {
		newElems[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = newElems;
}

// Method for restoring the heap property by swapping the value of the new node with the value of its parent node, 
// until it gets to its final place.
// The BC = Theta(1), WC = Theta(log2n), AC = Theta(log2n). The overall complexity of the bubbleUp(int p) method is O(log2n).
void Heap::bubbleUp(int p) {
	int pos = p;
	TElem elem = this->elems[p];
	int parent = p / 2;
	while (pos > 0 && this->relation(elem, this->elems[parent])) {
		this->elems[pos] = this->elems[parent];
		pos = parent;
		parent = pos / 2;
	}
	this->elems[pos] = elem;
}

// Method for popping an element from the Heap.
// The BC = Theta(1), WC = Theta(log2n), AC = Theta(log2n). The overall complexity of the addToHeap(TElem elem) method is O(log2n).
TElem Heap::removeFromHeap() {
	if (this->length == 0) {
		throw std::runtime_error("error - empty heap");
	}
	TElem deletedElem = this->elems[0];
	this->elems[0] = this->elems[this->length - 1];
	this->length--;
	this->bubbleDown(0);
	return deletedElem;
}

// Method for restoring the heap property, by swapping the new node with its maximum child, until it becomes a leaf, or until
// it will be greater than both children.
// The BC = Theta(1), WC = Theta(log2n), AC = Theta(log2n). The overall complexity of the bubbleDown(int p) method is O(log2n).
void Heap::bubbleDown(int p) {
	int pos = p;
	TElem elem = this->elems[p];
	while (pos < this->length) {
		int maxChild = -1;
		if (pos * 2 <= this->length) {
			maxChild = pos * 2;
		}
		if (pos * 2 + 1 <= this->length && this->relation(this->elems[pos * 2 + 1], this->elems[pos * 2])) {
			maxChild = pos * 2 + 1;
		}
		if (maxChild != -1 && this->relation(this->elems[maxChild], elem)) {
			TElem tmp = this->elems[pos];
			this->elems[pos] = this->elems[maxChild];
			this->elems[maxChild] = tmp;
			pos = maxChild;
		}
		else {
			pos = this->length + 1;
		}
	}
}

// Method for restoring the heap property, by swapping the new node with its maximum child, in a recursive manner, until
// it becomes a leaf, or until it will be greater than both children.
// The BC = Theta(1), WC = Theta(log2n), AC = Theta(log2n). The overall complexity of the bubbleDownRecursive(int p) method is O(log2n).
void Heap::bubbleDownRecursive(int p) {
	int minIndex;
	int leftChild = p * 2;
	int rightChild = p * 2 + 1;
	if (rightChild >= this->length) {
		if (leftChild >= this->length) {
			return;
		}
		else {
			minIndex = leftChild;
		}
	}
	else {
		if (this->relation(this->elems[leftChild], this->elems[rightChild])) {
			minIndex = leftChild;
		}
		else {
			minIndex = rightChild;
		}
	}
	if (!this->relation(this->elems[p], this->elems[minIndex])) {
		TElem temp = this->elems[minIndex];
		this->elems[minIndex] = this->elems[p];
		this->elems[p] = temp;
		this->bubbleDown(minIndex);
	}
}

// Method for retrieving the size of the Heap.
// The BC = WC = AC = Theta(1). The complexity of the size() method is Theta(1).
int Heap::size() {
	return this->length;
}

// Heap destructor.
// The BC = WC = AC = Theta(1). The complexity of the ~Heap() method is Theta(1).
Heap::~Heap() {
	delete[] this->elems;
}
