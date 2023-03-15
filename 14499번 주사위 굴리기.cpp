#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	int N, M, r, c, K, order;
	scanf("%d%d%d%d%d", &N, &M, &r, &c, &K);
	vector<vector<int>> m(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &m[i][j]);
	vector<int> dice(6); // top, bottom, left, right, up, down;
	dice[1] = m[r][c];
	for (int i = 0; i < K; i++) {
		scanf("%d", &order);
		switch (order) {
		case 1:
			if (c < M - 1) {
				c++;
				dice = { dice[2], dice[3], dice[1], dice[0], dice[4], dice[5] };
				if (m[r][c] == 0) m[r][c] = dice[1];
				else { dice[1] = m[r][c]; m[r][c] = 0; }
				printf("%d\n", dice[0]);
			}
			break;
		case 2:
			if (c > 0) {
				c--;
				dice = { dice[3], dice[2], dice[0], dice[1], dice[4], dice[5] };
				if (m[r][c] == 0) m[r][c] = dice[1];
				else { dice[1] = m[r][c]; m[r][c] = 0; }
				printf("%d\n", dice[0]);
			}
			break;
		case 3:
			if (r > 0) {
				r--;
				dice = { dice[5], dice[4], dice[2], dice[3], dice[0], dice[1] };
				if (m[r][c] == 0) m[r][c] = dice[1];
				else { dice[1] = m[r][c]; m[r][c] = 0; }
				printf("%d\n", dice[0]);
			}
			break;
		case 4:
			if (r < N - 1) {
				r++;
				dice = { dice[4], dice[5], dice[2], dice[3], dice[1], dice[0] };
				if (m[r][c] == 0) m[r][c] = dice[1];
				else { dice[1] = m[r][c]; m[r][c] = 0; }
				printf("%d\n", dice[0]);
			}
		}
	}


}
