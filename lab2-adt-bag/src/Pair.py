class Pair:

    def __init__(self, elem, freq):
        self.__pair = [elem, freq]

    def getElem(self):
        return self.__pair[0]

    def setElem(self, elem):
        self.__pair[0] = elem

    def getFreq(self):
        return self.__pair[1]

    def setFreq(self, freq):
        self.__pair[1] = freq
