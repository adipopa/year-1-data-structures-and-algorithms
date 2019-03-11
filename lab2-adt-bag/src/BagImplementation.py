# -*- coding: utf-8 -*-
"""
Created on Tue Feb 19 15:48:58 2019

@author: Zsu
"""
from Pair import Pair


class Bag:

    # creates a new, empty Bag
    def __init__(self):
        self.__pairsList = []

    # adds a new element to the Bag
    # The complexity for the add(self, e) method is:
    # Best case: O(1) if the element already exists and we find it at the first position if the list
    # Worst case: O(n) when the element doesn't exist or it is found at the last position
    # Average case: O(n)
    # Overall case: O(n)
    def add(self, e):
        for i in range(len(self.__pairsList)):
            if self.__pairsList[i].getElem() == e:
                freq = self.__pairsList[i].getFreq()
                self.__pairsList[i].setFreq(freq + 1)
                return True
        self.__pairsList.append(Pair(e, 1))

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    # The complexity for the remove(self, e) method is:
    # Best case:
    def remove(self, e):
        for i in range(len(self.__pairsList)):
            if self.__pairsList[i].getElem() == e:
                freq = self.__pairsList[i].getFreq()
                self.__pairsList[i].setFreq(freq - 1)
                if self.__pairsList[i].getFreq() == 0:
                    del self.__pairsList[i]
                return True
        return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    def search(self, e):
        for i in range(len(self.__pairsList)):
            if self.__pairsList[i].getElem() == e:
                return True
        return False

    # counts and returns the number of times the element e appears in the bag
    def nrOccurrences(self, e):
        for i in range(len(self.__pairsList)):
            if self.__pairsList[i].getElem() == e:
                return self.__pairsList[i].getFreq()
        return 0

    # returns the size of the Bag (the number of elements)
    def size(self):
        count = 0
        for i in range(len(self.__pairsList)):
            count += self.__pairsList[i].getFreq()
        return count

    # returns True if the Bag is empty, False otherwise
    def isEmpty(self):
        return len(self.__pairsList) == 0

    # returns a BagIterator for the Bag
    def iterator(self):
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        self.__b = b

        self.__currentIt = 0
        self.__currentFreq = 1

    # returns True if the iterator is valid
    def valid(self):
        return self.__currentIt < len(self.__b._Bag__pairsList)

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    def getCurrent(self):
        if self.valid():
            return self.__b._Bag__pairsList[self.__currentIt].getElem()
        else:
            raise ValueError

    # moves the iterator to the next element
    #throws ValueError if the iterator is not valid
    def next(self):
        if self.valid():
            if self.__currentFreq < self.__b._Bag__pairsList[self.__currentIt].getFreq():
                self.__currentFreq += 1
            else:
                self.__currentIt += 1
                self.__currentFreq = 1
        else:
            raise ValueError

    # sets the iterator to the first element from the Bag
    def first(self):
        self.__currentIt = 0
        self.__currentFreq = 1
