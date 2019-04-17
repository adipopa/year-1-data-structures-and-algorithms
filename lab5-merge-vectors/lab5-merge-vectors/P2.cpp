#include "P2.h"

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
