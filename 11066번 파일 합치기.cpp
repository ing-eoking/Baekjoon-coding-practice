#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> cost;

int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		v = vector<vector<int>>(N+1, vector<int>(N+1, 999999999));
		cost = vector<int>(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &cost[i]);
			v[i][i] = 0;
			cost[i] += cost[i - 1];
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N - i; j++)
				for (int k = j; k < j + i; k++)
					v[j][j+i] = min(v[j][j+i], v[j][k] + v[k + 1][j + i] + cost[j + i] - cost[j - 1]);
		printf("%d\n", v[1][N]);

	}
}
