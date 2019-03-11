class Bag:

    def __init__(self):
        self.__elemsList = []
        self.__freqList = []

    # adds an element to the bag
    def add(self, e):
        if e in self.__elemsList:
            i = self.__elemsList.index(e)
            self.__freqList[i] += 1
        else:
            self.__elemsList.append(e)
            self.__freqList.append(1)

    # removes one occurrence of an element from a bag
    # returns true if an element was removed, false otherwise (if e was not part of the bag)
    def remove(self, e):
        if e in self.__elemsList:
            i = self.__elemsList.index(e)
            self.__freqList[i] -= 1
            if self.__freqList[i] == 0:
                del self.__elemsList[i]
                del self.__freqList[i]
            return True
        return False

    # checks if an element appears is the bag
    def search(self, e):
        return e in self.__elemsList

    # returns the number of occurrences for an element in the bag
    def nrOccurrences(self, e):
        if e in self.__elemsList:
            i = self.__elemsList.index(e)
            return self.__freqList[i]
        return 0

    # returns the number of elements from the bag
    def size(self):
        length = 0
        for i in range(len(self.__elemsList)):
            length += self.__freqList[i]
        return length

    # returns an iterator for this bag
    def iterator(self):
        return BagIterator(self)

    # checks if the bag is empty
    def isEmpty(self):
        return len(self.__elemsList) == 0


class BagIterator:

    def __init__(self, bag):
        self.__itElems = bag._Bag__elemsList
        self.__itFreq = bag._Bag__freqList
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
