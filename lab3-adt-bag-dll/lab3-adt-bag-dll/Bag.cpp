#include "Bag.h"
#include "BagIterator.h"

// Bag constructor.
// The BC = WC = AC = Theta(1). The complexity of the Bag(Relation r) method is Theta(1).
Bag::Bag() {
	bagDll = new DLL();
	bagDll->head = NULL;
	bagDll->tail = NULL;
}

// Method for adding an element in the Bag's DLL.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the add(TElem e) method is O(n).
void Bag::add(TElem e) {
	DLLNode* newNode = bagDll->head;
	while (newNode != NULL) {
		if (newNode->elem == e) {
			newNode->freq++;
			return;
		}
		newNode = newNode->next;
	}
	// Otherwise, add the element at the end of the DLL.
	insertLast(e);
}

// Method for removing an element from the Bag's DLL.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the remove(TElem e) method is O(n).
bool Bag::remove(TElem e) {
	DLLNode* currentNode = bagDll->head;
	while (currentNode != NULL) {
		if (currentNode->elem == e) {
			// Decrease the element's freq.
			currentNode->freq--;
			// If the freq has reached 0 for the current element, delete it from the DLL.
			if (currentNode->freq == 0) {
				deleteNode(currentNode);
			}
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

// Method for inserting an element at the end of the DLL.
// The BC = WC = AC = Theta(1). The overall complexity of the insertLast(TElem e) method is Theta(1).
void Bag::insertLast(TElem e) {
	DLLNode* newNode = new DLLNode();
	newNode->elem = e;
	newNode->freq = 1;
	newNode->next = NULL;
	newNode->prev = bagDll->tail;
	if (bagDll->head == NULL) {
		bagDll->head = newNode;
		bagDll->tail = newNode;
	}
	else {
		bagDll->tail->next = newNode;
		bagDll->tail = newNode;
	}
}

// Method for deleting a node from the DLL.
// The BC = WC = AC = Theta(1). The overall complexity of the deleteNode(DLLNode* currentNode) method is Theta(1).
void Bag::deleteNode(DLLNode* currentNode) {
	if (currentNode == bagDll->head) {
		bagDll->head = currentNode->next;
	}

	if (currentNode == bagDll->tail) {
		bagDll->tail = currentNode->prev;
	}

	if (currentNode->next != NULL) {
		currentNode->next->prev = currentNode->prev;
	}

	if (currentNode->prev != NULL) {
		currentNode->prev->next = currentNode->next;
	}

	delete currentNode;
}

// Method for searching for an element is in the Bag's DLL.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the search(TElem e) method is O(n).
bool Bag::search(TElem e) const {
	DLLNode* currentNode = bagDll->head;
	while (currentNode != NULL) {
		if (currentNode->elem == e) {
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

// Method for getting the nrOfOccurances of an element from the Bag's DLL.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the nrOccurrences(TElem e) method is O(n).
int Bag::nrOccurrences(TElem e) const {
	DLLNode* currentNode = bagDll->head;
	while (currentNode != NULL) {
		if (currentNode->elem == e) {
			return currentNode->freq;
		}
		currentNode = currentNode->next;
	}
	return 0;
}

// Method for getting the size of the Bag.
// The BC = WC = AC = Theta(n). The overall complexity of the size() method is Theta(n).
int Bag::size() const {
	int count = 0;
	DLLNode* currentNode = bagDll->head;
	while (currentNode != NULL) {
		count += currentNode->freq;
		currentNode = currentNode->next;
	}
	return count;
}

// Method for getting an iterator for the current Bag.
// The BC = WC = AC = Theta(1). The overall complexity of the iterator() method is Theta(1).
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

// Method for checking if the Bag is empty or not.
// The BC = WC = AC = Theta(1). The overall complexity of the isEmpty() method is Theta(1).
bool Bag::isEmpty() const {
	return size() == 0;
}

// Bag destructor.
// The BC = WC = AC = Theta(n). The overall complexity of the ~Bag() method is Theta(n).
Bag::~Bag() {
	DLLNode* currentNode = bagDll->head;
	while (currentNode != bagDll->tail) {
		currentNode = currentNode->next;
		delete currentNode->prev;
	}
	delete currentNode;
	delete bagDll;
}

void bagUnion(Bag& b, Bag& b1, Bag& b2) {
	BagIterator it1 = b1.iterator();
	while (it1.valid()) {
		TElem e = it1.getCurrent();
		if (b.search(e) == false) {
			b.add(e);
		}
		it1.next();
	}

	BagIterator it2 = b2.iterator();
	while (it2.valid()) {
		TElem e = it2.getCurrent();
		if (b.search(e) == false) {
			b.add(e);
		}
		it2.next();
	}
}

void bagIntersection(Bag& b, Bag& b1, Bag& b2) {
	BagIterator it = b1.iterator();
	while (it.valid()) {
		TElem e = it.getCurrent();
		if (b2.search(e) == true) {
			b.add(e);
		}
		it.next();
	}
}