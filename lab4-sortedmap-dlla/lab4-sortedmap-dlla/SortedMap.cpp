#include "SortedMap.h"
#include "SMIterator.h"

// SortedMap constructor.
// The BC = WC = AC = Theta(1). The complexity of the SortedMap(Relation r) method is Theta(1).
SortedMap::SortedMap(Relation r) {
	this->dlla.capacity = INIT_CAPACITY;
	this->dlla.head = -1;
	this->dlla.tail = -1;
	this->dlla.firstEmpty = 0;
	this->dlla.size = 0;
	this->dlla.nodes = new DLLANode[this->dlla.capacity];

	for (int i = 0; i < this->dlla.capacity - 1; i++) {
		this->dlla.nodes[i].next = i + 1;
	}
	this->dlla.nodes[this->dlla.capacity - 1].next = -1;

	for (int i = 1; i < this->dlla.capacity; i++) {
		this->dlla.nodes[i].prev = i - 1;
	}
	this->dlla.nodes[0].prev = -1;

	this->relation = r;
}

// Method for adding an element in the SortedMap's DLLA.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the add(TKey c, TValue v) method is O(n).
TValue SortedMap::add(TKey c, TValue v) {
	int currentNode = this->dlla.head;
	int currentPos = 0;
	while (currentNode != -1 && currentPos < this->size() && this->dlla.nodes[currentNode].info.first != c &&
		this->relation(this->dlla.nodes[currentNode].info.first, c)) {
		currentNode = this->dlla.nodes[currentNode].next;
		currentPos++;
	}

	if (currentNode != -1 && this->dlla.nodes[currentNode].info.first == c) {
		TValue oldValue = this->dlla.nodes[currentNode].info.second;
		this->dlla.nodes[currentNode].info.second = v;
		return oldValue;
	}

	this->insertPosition(std::make_pair(c, v), currentPos);
	this->dlla.size++;
	return NULL_TVALUE;
}

// Method for removing an element from the SortedMap's DLLA.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the remove(TKey c) method is O(n).
TValue SortedMap::remove(TKey c) {
	int currentNode = this->dlla.head;
	int prevNode = -1;
	while (currentNode != -1 && (this->dlla.nodes[currentNode].info.first == c || relation(this->dlla.nodes[currentNode].info.first, c))) {
		if (this->dlla.nodes[currentNode].info.first == c) {
			TValue oldValue = this->dlla.nodes[currentNode].info.second;
			if (currentNode == this->dlla.head) {
				this->dlla.head = this->dlla.nodes[currentNode].next;
			}
			if (currentNode == this->dlla.tail) {
				this->dlla.tail = this->dlla.nodes[currentNode].prev;
			}
			if (this->dlla.nodes[currentNode].next != -1) {
				this->dlla.nodes[prevNode].next = this->dlla.nodes[currentNode].prev;
			}
			if (this->dlla.nodes[currentNode].prev != -1) {
				this->dlla.nodes[prevNode].next = this->dlla.nodes[currentNode].next;
			}
			this->free(currentNode);
			this->dlla.size--;
			return oldValue;
		}
		prevNode = currentNode;
		currentNode = this->dlla.nodes[currentNode].next;
	}
	return NULL_TVALUE;
}

// Method for searching for an element is in the SortedMap's DLLA.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the search(TKey c) method is O(n).
TValue SortedMap::search(TKey c) const {
	int currentNode = this->dlla.head;
	while (currentNode != -1 && (this->dlla.nodes[currentNode].info.first == c || relation(this->dlla.nodes[currentNode].info.first, c))) {
		if (this->dlla.nodes[currentNode].info.first == c) {
			return this->dlla.nodes[currentNode].info.second;
		}
		currentNode = this->dlla.nodes[currentNode].next;
	}
	return NULL_TVALUE;
}

// Method for getting the size of the SortedMap.
// The BC = WC = AC = Theta(1). The overall complexity of the size() method is Theta(1).
int SortedMap::size() const {
	return this->dlla.size;
}

// Method for checking if the SortedMap is empty or not.
// The BC = WC = AC = Theta(1). The overall complexity of the isEmpty() method is Theta(1).
bool SortedMap::isEmpty() const {
	return this->size() == 0;
}

// Method for getting an iterator for the current SortedMap.
// The BC = WC = AC = Theta(1). The overall complexity of the iterator() method is Theta(1).
SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

// Method for allocating a new element will and return its position.
// The BC = WC = AC = Theta(1). The overall complexity of the allocate() method is Theta(1).
int SortedMap::allocate() {
	int newElem = this->dlla.firstEmpty;
	if (newElem != -1) {
		this->dlla.nodes[this->dlla.firstEmpty].prev = -1;
		this->dlla.firstEmpty = this->dlla.nodes[this->dlla.firstEmpty].next;
		this->dlla.nodes[newElem].next = -1;
		this->dlla.nodes[newElem].prev = -1;
	}
	return newElem;
}

// Method for freeing an element from a position.
// The BC = WC = AC = Theta(1). The overall complexity of the free(int pos) method is Theta(1).
void SortedMap::free(int pos) {
	this->dlla.nodes[pos].next = this->dlla.firstEmpty;
	this->dlla.nodes[pos].prev = -1;
	this->dlla.nodes[this->dlla.firstEmpty].prev = pos;
	this->dlla.firstEmpty = pos;
}

// Method for resizing the SortedMap's DLLA.
// The BC = WC = AC = Theta(n). The overall complexity of the resize() method is Theta(n).
void SortedMap::resize() {
	DLLANode* newNodes = new DLLANode[this->dlla.capacity * 2];
	for (int i = 0; i < this->dlla.capacity; i++) {
		newNodes[i] = this->dlla.nodes[i];
	}

	for (int i = this->dlla.capacity; i < 2 * this->dlla.capacity - 1; i++) {
		newNodes[i].next = i + 1;
	}
	newNodes[this->dlla.capacity * 2 - 1].next = -1;

	for (int i = this->dlla.capacity + 1; i < 2 * this->dlla.capacity; i++) {
		newNodes[i].prev = i - 1;
	}
	newNodes[this->dlla.capacity].prev = -1;

	this->dlla.firstEmpty = this->dlla.capacity;
	this->dlla.capacity *= 2;

	delete[] this->dlla.nodes;

	this->dlla.nodes = newNodes;
}

// Method for inserting an element at a given position in the DLLA.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the insertPosition(TElem elem, int pos) method is O(n).
void SortedMap::insertPosition(TElem elem, int pos) {
	int newElem = allocate();
	if (newElem == -1) {
		resize();
		newElem = allocate();
	}
	this->dlla.nodes[newElem].info = elem;
	if (pos == 0) {
		if (this->dlla.head == -1) {
			this->dlla.head = newElem;
			this->dlla.tail = newElem;
		} else {
			this->dlla.nodes[newElem].next = this->dlla.head;
			this->dlla.nodes[this->dlla.head].prev = newElem;
			this->dlla.head = newElem;
		}
	}
	else {
		int nodeC = this->dlla.head;
		int posC = 0;
		while (nodeC != -1 && posC < pos - 1) {
			nodeC = this->dlla.nodes[nodeC].next;
			posC++;
		}
		if (nodeC != -1) {
			int nodeNext = this->dlla.nodes[nodeC].next;
			this->dlla.nodes[newElem].next = nodeNext;
			this->dlla.nodes[newElem].prev = nodeC;
			this->dlla.nodes[nodeC].next = newElem;
			if (nodeNext == -1) {
				this->dlla.tail = newElem;
			}
			else {
				this->dlla.nodes[nodeNext].prev = newElem;
			}
		}
	}
}

// SortedMap destructor.
// The BC = WC = AC = Theta(1). The overall complexity of the ~SortedMap() method is Theta(1).
SortedMap::~SortedMap() {
	delete[] this->dlla.nodes;
}
