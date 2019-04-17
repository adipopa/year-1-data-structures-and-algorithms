#include "Heap.h"
#include <stdexcept>

Heap::Heap(Relation rel) {
	this->capacity = INIT_CAPACITY;
	this->length = 0;
	this->elems = new TElem[this->capacity];
	this->relation = rel;
}

void Heap::addToHeap(TElem elem) {
	if (this->length == this->capacity) {
		this->resizeHeap();
	}
	this->elems[this->length] = elem;
	this->length++;
	this->bubbleUp(this->length - 1);
}

void Heap::resizeHeap() {
	this->capacity *= 2;
	TElem* newElems = new TElem[this->capacity];
	for (int i = 0; i < this->length; i++) {
		newElems[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = newElems;
}

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

void Heap::bubbleDown(int p) {
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

int Heap::size() {
	return this->length;
}


Heap::~Heap() {
	delete[] this->elems;
}
