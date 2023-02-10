#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

int M, N, K, X, Y;
bitset<50> farm[50];
const int mov[2][4] = { {0, 0, -1, 1},
					{1, -1, 0, 0} };
void dfs(int i, int j) {
	if (i < 0 || i >= M) return;
	if (j < 0 || j >= N) return;
	if (!farm[i][j]) return;
	farm[i][j] = 0;
	for (int m = 0; m < 4; m++) 
		dfs(i + mov[0][m], j + mov[1][m]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int answer = 0;
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i < 50; i++) farm[i].reset();
		while (K--) {
			scanf("%d%d", &X, &Y);
			farm[X][Y] = 1;
		}
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				if (farm[i][j]) {
					answer++;
					dfs(i, j);
				}

		printf("%d\n", answer);
	}
}
