#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int dir[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };


int main() {
	int N, M, d, s, r , c;
	scanf("%d%d", &N, &M);
	vector<vector<int>> bas(N, vector<int>(N));
	vector<vector<bool>> cloud(N, vector<bool>(N));
	cloud[N - 1][0] = cloud[N - 2][1] = cloud[N - 1][1] = cloud[N - 2][0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &bas[i][j]);
	while (M--) {
		scanf("%d %d", &d, &s); d--;
		vector<vector<bool>> temp(N, vector<bool>(N));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if (cloud[i][j]) {
					r = (i + dir[d][0] * s + 50 * N) % N;
					c = (j + dir[d][1] * s + 50 * N) % N;
					temp[r][c] = true;
					bas[r][c]++;
				}

		cloud = vector<vector<bool>>(N, vector<bool>(N));
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (temp[i][j]) {
					if (i > 0 && j > 0 && bas[i - 1][j - 1] > 0) bas[i][j]++;
					if (i > 0 && j < N - 1 && bas[i - 1][j + 1] > 0)bas[i][j]++;
					if (i < N - 1 && j > 0 && bas[i + 1][j - 1] > 0)bas[i][j]++;
					if (i < N - 1 && j < N - 1 && bas[i + 1][j + 1])bas[i][j]++;
				}
			}

		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if (bas[i][j] > 1 && !temp[i][j]) {
					bas[i][j] -= 2;
					cloud[i][j] = true;
				}

	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum += bas[i][j];
	printf("%d", sum);
}
