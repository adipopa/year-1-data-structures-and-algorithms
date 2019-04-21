#include "P2.h"

// Method for merging k sorted vectors into a single sorted vector (considering a relation R over the elements).
// The method uses a Heap data structure for arranging the elements in all k vectors and building the result vector.
// The BC = Theta(k*n), WC = Theta((k*n)^2), AC = Theta(k*n*log2(k*n)), where k = the length of inputVectors, n = the length of
// one of the input vectors. The overall complexity of the mergeVectors(vector<vector<TElem>> inputVectors, Relation rel) method is O(k*n*log2(k*n)).
vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel) {
	Heap heap{ rel };

	for (auto it = inputVectors.begin(); it != inputVectors.end(); it++) {
		vector<TElem> currentVector = (vector<TElem>)*it;
		for (auto innerIt = currentVector.begin(); innerIt != currentVector.end(); innerIt++) {
			TElem currentElem = (TElem)*innerIt;
			heap.addToHeap(currentElem);
		}
	}

	vector<TElem> mergedVector = vector<TElem>();
	int heapSize = heap.size();
	for (int i = 0; i < heapSize; i++) {
		TElem deletedElem = heap.removeFromHeap();
		mergedVector.push_back(deletedElem);
	}

	return mergedVector;
}
