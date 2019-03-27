#pragma once

#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

typedef int TElem;

typedef struct DLLNode {
	TElem elem;
	int freq = 0;
	DLLNode *next;
	DLLNode *prev;
} DLLNode;

typedef struct DLL {
	DLLNode* head;
	DLLNode* tail;
} DLL;

class BagIterator;

class Bag {

	friend class BagIterator;

private:

	/*representation of Bag*/

	DLL* bagDll;

	void insertLast(TElem e);
	void deleteNode(DLLNode* currentNode);

public:

	//constructor

	Bag();


	//adds an element to the bag

	void add(TElem e);



	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);

	

	//checks if an element appearch is the bag

	bool search(TElem e) const;



	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e) const;



	//returns the number of elements from the bag

	int size() const;



	//returns an iterator for this bag

	BagIterator iterator() const;



	//checks if the bag is empty

	bool isEmpty() const;



	//destructor

	~Bag();

};

void bagUnion(Bag& b, Bag& b1, Bag& b2);