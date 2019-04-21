#pragma once

typedef int TElem;
typedef bool(*Relation) (TElem e1, TElem e2);

#define INIT_CAPACITY 200;

class Heap {
private:
	int capacity, length;
	TElem* elems;
	Relation relation;

public:
	Heap(Relation rel);

	void addToHeap(TElem elem);

	void resizeHeap();

	void bubbleUp(int p);

	TElem removeFromHeap();

	void bubbleDown(int p);

	void bubbleDownRecursive(int p);

	int size();

	~Heap();
};

