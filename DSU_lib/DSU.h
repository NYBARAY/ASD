

class DSU {
	int* _parent;
	int _size;
	int* _rank;

public:
	DSU(int _size);
	void unite(int, int);
	int find(int);
	~DSU();
};