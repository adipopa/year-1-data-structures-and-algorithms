#include "SortedBag.h"
#include "SortedBagIterator.h"

//implementation of the operations from SortedBag.h

// SortedBag constructor.
// The BC = WC = AC = Theta(1). The complexity of the SortedBag(Relation r) method is Theta(1).
SortedBag::SortedBag(Relation r) {
	cap = 20;
	len = 0;
	elems = new TComp[20];
	rel = r;
}

// Method for adding an element at the right position in the SortedBag's elems array.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The overall complexity of the add(TComp e) method is O(n).
void SortedBag::add(TComp e) {
	// If the length of the bag is equal to its capacity, resize it.
	if (len == cap) {
		resize();
	}

	// The variable i will store the position where the next element needs to be inserted at (to respect the given relation).
	int i = 0;
	while (i < len && rel(elems[i], e)) {
		i++;
	}

	// Shift all the elements from len to i + 1 one position to the right.
	for (int j = len; j > i; j--) {
		elems[j] = elems[j - 1];
	}

	// Insert the new element at the correct position.
	elems[i] = e;

	// Increment the length of the bag.
	len++;
}

// Method for resizing the dynamic array.
// The BC = WC = AC = Theta(n). The overall complexity of the resize() method is Theta(n).
void SortedBag::resize() {
	cap *= 2;
	TComp *newElems = new TComp[cap];
	for (int i = 0; i < len; i++) {
		newElems[i] = elems[i];
	}
	delete[] elems;
	elems = newElems;
}

// Method for removing an element from the bag.
// The BC = WC = AC = Theta(n). The complexity of the remove(TComp e) method is Theta(n).
bool SortedBag::remove(TComp e) {
	int i = 0;
	while (i < len && rel(elems[i], e)) {
		if (elems[i] == e) {
			len--;
			for (int j = i; j < len; j++) {
				elems[j] = elems[j + 1];
			}
			return true;
		}
		i++;
	}
	return false;
}

// Method for searching if an element exists in the bag.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The complexity of the search(TComp e) method is O(n).
bool SortedBag::search(TComp e) const {
	int i = 0;
	while (i < len && rel(elems[i], e)) {
		if (elems[i] == e) {
			return true;
		}
		i++;
	}
	return false;
}

// Method for retrieving the number of occurences of an element in the bag.
// The BC = Theta(1), WC = Theta(n), AC = Theta(n). The complexity of the nrOccurrences(TComp e) method is O(n).
int SortedBag::nrOccurrences(TComp e) const {
	int count = 0;
	int i = 0;
	while (i < len && rel(elems[i], e)) {
		if (elems[i] == e) {
			count++;
		}
		i++;
	}
	return count;
}

// Methor for retrieving the size of the bag.
// The BC = WC = AC = Theta(1). The complexity of the size() method is Theta(1).
int SortedBag::size() const {
	return len;
}

// Method for retrieving an iterator for the bag.
// The BC = WC = AC = Theta(1). The complexity of the iterator() method is Theta(1).
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

// Method for checking if the bag is empty.
// The BC = WC = AC = Theta(1). The complexity of the isEmpty() method is Theta(1).
bool SortedBag::isEmpty() const {
	return len == 0;
}

// SortedBag destructor.
// The BC = WC = AC = Theta(1). The complexity of the ~SortedBag() method is Theta(1).
SortedBag::~SortedBag() {
	delete[] elems;
}
