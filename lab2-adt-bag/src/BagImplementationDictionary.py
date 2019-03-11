class Bag:

    def __init__(self):
        self.__elems = {}

    # adds an element to the bag
    def add(self, e):
        if e in self.__elems:
            self.__elems[e] += 1
        else:
            self.__elems[e] = 1

    # removes one occurrence of an element from a bag
    # returns true if an element was removed, false otherwise (if e was not part of the bag)
    def remove(self, e):
        if e in self.__elems:
            if self.__elems[e] > 1:
                self.__elems[e] -= 1
            else:
                del self.__elems[e]
            return True
        else:
            return False

    # checks if an element appears is the bag
    def search(self, e):
        return e in self.__elems

    # returns the number of occurrences for an element in the bag
    def nrOccurrences(self, e):
        if e in self.__elems:
            return self.__elems[e]
        return 0

    # returns the number of elements from the bag
    def size(self):
        length = 0
        for elemKey in self.__elems.keys():
            length += self.__elems[elemKey]
        return length

    # returns an iterator for this bag
    def iterator(self):
        return BagIterator(self)

    # checks if the bag is empty
    def isEmpty(self):
        return len(self.__elems.keys()) == 0


class BagIterator:

    def __init__(self, bag):
        self.__itElems = list(bag._Bag__elems.keys())
        self.__itFreq = list(bag._Bag__elems.values())
        self.__currentIndex = 0
        self.__currentFreq = 1

    def first(self):
        self.__currentIndex = 0
        self.__currentFreq = 1

    def next(self):
        if self.valid():
            if self.__currentFreq < self.__itFreq[self.__currentIndex]:
                self.__currentFreq += 1
            else:
                self.__currentIndex += 1
                self.__currentFreq = 1
        else:
            raise ValueError

    def valid(self):
        return self.__currentIndex < len(self.__itElems) and self.__currentFreq <= self.__itFreq[self.__currentIndex]

    def getCurrent(self):
        if self.valid():
            return self.__itElems[self.__currentIndex]
        else:
            raise ValueError
