#pragma once

#include "Heap.h"
#include <vector>
#include <algorithm>

using namespace std;

//merges k sorted vectors into one single vector. 
//the input vectors are sorted considering the relation and the results should be sorted in the same way.
vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel);