#include "DSU.h"
#include <vector>
#include <iostream>

int main() {
	std::cout << "Write array size: ";
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> mass(N, std::vector<int>(N));

	std::cout << "Write the elements: " << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> mass[i][j];
		}
	}

	DSU island(N * N);

	for (int i = 0; i < N; i++) {       
		for (int j = 0; j < N; j++) {
			if (mass[i][j] == 1) {
				int index = i * N + j;

				if (j != 0 && mass[i][j-1] == 1) {     //левый
					int left_index = i * N + (j - 1);
					island.unite(index, left_index);
				}


				if (i != 0 && mass[i-1][j] == 1) {    //верхний
					int top_index = (i - 1) * N + j;
					island.unite(index, top_index);
				}
			}
		}
	}


	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mass[i][j] == 1) {
				int index = i * N + j;

				if (island.find(index) == index) {
					count++;
				}
			}
		}
	}

	std::cout << "Number of islands: " << count << std::endl;


	return 0;
}