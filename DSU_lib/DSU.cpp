

#include <stdexcept>
#include "DSU.h"
#include <vector>

DSU::DSU(int size) : _size(size) {
	_parent = new int[_size];
	_rank = new int[_size];
	for (int i = 0; i < _size; i++) {
		_parent[i] = i;
		_rank[i] = 0;
	}
}

DSU:: ~DSU() {
	delete[] _parent;
	delete[] _rank;
}

int DSU::find(int x) {
	if (_parent[x] != x) {
	_parent[x] = find(_parent[x]); 
	}
	return _parent[x];
}

void DSU::unite(int x1, int x2) {
	int x_1 = _rank[find(x1)];
	int x_2 = _rank[find(x2)];
	if (x_1 < x_2) {
		_parent[x1] = find(x2);
	}
	else {
		if (x_1 == x_2) {
			_rank[find(x1)]++;
		}
		_parent[x2] = find(x1);
	}
}