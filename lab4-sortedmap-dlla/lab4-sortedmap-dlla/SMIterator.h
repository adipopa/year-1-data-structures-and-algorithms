#pragma once

#include "SortedMap.h"
#include <stdexcept>

class SortedMap;

//unidirectional iterator for a container

class SMIterator {

	friend class SortedMap;

private:

	SMIterator(const SortedMap& sm);

	//contains a reference of the container it iterates over

	const SortedMap& sm;



	/* representation specific for the iterator*/

	DLLA dlla;
	int currentElement;

public:



	//sets the iterator to the first element of the container

	void first();



	//moves the iterator to the next element

	//throws exception if the iterator is not valid

	void next();



	//checks if the iterator is valid

	bool valid() const;



	//returns the value of the current element from the iterator

	// throws exception if the iterator is not valid

	TElem getCurrent() const;



};
