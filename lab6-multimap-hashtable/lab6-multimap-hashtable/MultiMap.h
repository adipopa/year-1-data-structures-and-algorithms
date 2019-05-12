#pragma once

#include <vector>
#include <utility>


using namespace std;


typedef int TKey;

typedef int TValue;


typedef std::pair<TKey, TValue> TElem;


typedef int(*TFunction)(TKey key);


#define INIT_CAPACITY 32


typedef struct Node {
	TElem info;
	Node* next;
} Node;

typedef struct HashTableNode {
	Node* head;
} HashTableNode;

typedef struct HashTable {
	HashTableNode* T;
	int capacity, size;
} HashTable;

class MultiMapIterator;

class MultiMap {

	friend class MultiMapIterator;

private:

	/* representation of the MultiMap */

	HashTable ht;

	int hashCode(TKey key) const;
	int hashDivisionFn(TKey key) const;

	void resize();

public:

	//constructor

	MultiMap();



	//adds a key value pair to the multimap

	void add(TKey c, TValue v);



	//removes a key value pair from the multimap

	//returns true if the pair was removed (if it was in the multimap) and false otherwise

	bool remove(TKey c, TValue v);



	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty

	vector<TValue> search(TKey c) const;



	//returns the number of pairs from the multimap

	int size() const;



	//checks whether the multimap is empty

	bool isEmpty() const;



	//returns an iterator for the multimap

	MultiMapIterator iterator() const;



	//descturctor

	~MultiMap();





};



