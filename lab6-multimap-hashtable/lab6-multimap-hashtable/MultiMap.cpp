#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <iostream>

// MultiMap constructor.
// The BC = WC = AC = Theta(1). The complexity of the MultiMap() method is Theta(1).
MultiMap::MultiMap() {
	this->ht.capacity = INIT_CAPACITY;
	this->ht.size = 0;
	this->ht.T = new HashTableNode[this->ht.capacity];
	for (int i = 0; i < this->ht.capacity; i++) {
		this->ht.T[i].head = NULL;
	}
}

// Method for adding an element in the MultiMap's hashtable.
// The BC = AC = Theta(1), WC = Theta(m). The overall complexity of the add(TKey c, TValue v) method is O(m) (amortized O(1)).
void MultiMap::add(TKey c, TValue v) {
	if (this->ht.size / this->ht.capacity > 42) {
		this->resize();
	}

	int position = this->hashDivisionFn(c);

	Node* newNode = new Node();
	newNode->info = std::make_pair(c, v);
	newNode->next = this->ht.T[position].head;
	this->ht.T[position].head = newNode;

	this->ht.size++;
}

// Method for removing an element from the MultiMap's hashtable.
// The BC = WC = AC = Theta(1), since WC and AC depend on the ratio between n and m, which in the end is constant.
// The overall complexity of the remove(TKey c, TValue v) method is Theta(1).
bool MultiMap::remove(TKey c, TValue v) {
	int position = this->hashDivisionFn(c);
	Node* currentNode = this->ht.T[position].head;
	Node* prevNode = NULL;
	while (currentNode != NULL && !(currentNode->info.first == c && currentNode->info.second == v)) {
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode != NULL) {
		if (prevNode == NULL) {
			this->ht.T[position].head = this->ht.T[position].head->next;
		}
		else {
			prevNode->next = currentNode->next;
			currentNode->next = NULL;
		}
		delete currentNode;
		this->ht.size--;
		return true;
	}
	return false;
}

// Method for searching for an element is in the MultiMap's hashtable.
// The BC = WC = AC = Theta(1), since WC and AC depend on the ratio between n and m, which in the end is constant.
// The overall complexity of the search(TKey c) method is Theta(1).
vector<TValue> MultiMap::search(TKey c) const {
	std::vector<TValue> values;

	int position = this->hashDivisionFn(c);
	Node* currentNode = this->ht.T[position].head;
	while (currentNode != NULL) {
		if (currentNode->info.first == c) {
			values.push_back(currentNode->info.second);
		}
		currentNode = currentNode->next;
	}

	return values;
}

// Method for getting the size of the MultiMap.
// The BC = WC = AC = Theta(1). The overall complexity of the size() method is Theta(1).
int MultiMap::size() const {
	return this->ht.size;
}

// Method for checking if the MultiMap is empty or not.
// The BC = WC = AC = Theta(1). The overall complexity of the isEmpty() method is Theta(1).
bool MultiMap::isEmpty() const {
	return this->ht.size == 0;
}

// Method for getting an iterator for the current MultiMap.
// The BC = WC = AC = Theta(1). The overall complexity of the iterator() method is Theta(1).
MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

// Method for assuring the correctness of a key.
// The BC = WC = AC = Theta(1). The overall complexity of the hashCode(TKey key) method is Theta(1).
int MultiMap::hashCode(TKey key) const {
	return abs(int(key));
}

// Method for generating a hash position by division between a hash code and the capacity of the hashtable.
// The BC = WC = AC = Theta(1). The overall complexity of the hashDivisionFn(TKey key) method is Theta(1).
int MultiMap::hashDivisionFn(TKey key) const {
	return this->hashCode(key) % this->ht.capacity;
}

// Method for resizing the MultiMap's hashable.
// The BC = WC = AC = Theta(m). The overall complexity of the resize() method is Theta(m).
void MultiMap::resize() {
	int oldCapacity = this->ht.capacity;
	this->ht.capacity *= 2;
	cout << "Resized hashtable capacity to " << this->ht.capacity << ".\n";
	HashTableNode* newT = new HashTableNode[this->ht.capacity];
	for (int i = 0; i < this->ht.capacity; i++) {
		newT[i].head = NULL;
	}
	Node* prevNode = NULL;
	for (int i = 0; i < oldCapacity; i++) {
		Node* currentNode = this->ht.T[i].head;
		while (currentNode != NULL) {
			prevNode = currentNode;

			int position = this->hashDivisionFn(currentNode->info.first);

			Node* newNode = new Node();
			newNode->info = currentNode->info;
			newNode->next = newT[position].head;
			newT[position].head = newNode;

			currentNode = currentNode->next;
			delete prevNode;
		}
	}
	delete[] this->ht.T;
	this->ht.T = newT;
}

// MultiMap destructor.
// The BC = WC = AC = Theta(n). The overall complexity of the ~MultiMap() method is Theta(n).
MultiMap::~MultiMap() {
	for (int i = 0; i < this->ht.capacity; i++) {
		Node* currentNode = this->ht.T[i].head;
		Node* prevNode = NULL;
		while (currentNode != NULL) {
			prevNode = currentNode;
			currentNode = currentNode->next;
			delete prevNode;
		}
	}
	delete[] this->ht.T;
}
