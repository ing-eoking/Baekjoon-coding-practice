#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, M, K;

vector<vector<int>> cost, A;
vector<vector<vector<int>>> alive;

int main() {
	int x, y, z;
	scanf("%d%d%d", &N, &M, &K);
	cost = vector<vector<int>>(N, vector<int>(N, 5));
	A = vector<vector<int>>(N, vector<int>(N));
	alive = vector<vector<vector<int>>>(N, vector<vector<int>>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		alive[x - 1][y - 1].push_back(z);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!alive[i][j].empty()) sort(alive[i][j].begin(), alive[i][j].end());

	for (int y = 0; y < K; y++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!alive[i][j].empty()) {
					int k = 0, cur = -1, sum = 0;
					for (; k < alive[i][j].size(); k++) {
						if (alive[i][j][k] > cost[i][j]) {
							if (cur < 0) cur = k;
							sum += alive[i][j][k] / 2;
						}
						else {
							cost[i][j] -= alive[i][j][k];
							alive[i][j][k]++;
						}
					}
					cost[i][j] += sum;
					if(cur >= 0)alive[i][j].erase(alive[i][j].begin() + cur, alive[i][j].end());
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cost[i][j] += A[i][j];
				if (!alive[i][j].empty()) {
					for (int k = 0; k < alive[i][j].size(); k++) {
						if (alive[i][j][k] % 5 == 0) {
							for (int a = -1; a <= 1; a++) {
								for(int b = -1; b <= 1; b++)
									if (a != 0 || b != 0) {
										if (i + a >= 0 && i + a < N && j + b >= 0 && j + b < N) {
											alive[i + a][j + b].insert(alive[i + a][j + b].begin(), 1);
										}
									}
							}
						}
					}
				}
			}
		}
	}
	int trees = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!alive[i][j].empty()) trees += alive[i][j].size();
		}
	}
	printf("%d", trees);

}
