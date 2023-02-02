#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> m;
vector<vector<int>> cost;

int dp(int y, int x, int c) {
	if (y < 0 || y >= m.size()) return 0;
	if (x < 0 || x >= m[0].size()) return 0;
	if (m[y][x] <= c) return 0;
	if (cost[y][x] != -1) return cost[y][x];
	return cost[y][x] = dp(y - 1, x, m[y][x]) + dp(y + 1, x, m[y][x]) + dp(y, x - 1, m[y][x]) + dp(y, x + 1, m[y][x]);
}


int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	cost = m = vector<vector<int>>(M, vector<int>(N, -1));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &m[i][j]);
	cost[0][0] = 1;
	printf("%d",dp(M - 1, N - 1, 0));

}
