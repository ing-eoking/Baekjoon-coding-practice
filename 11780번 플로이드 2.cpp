#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

#define INF 100000001

int main() {
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);
	vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF)), p(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) { cost[i][i] = 0; p[i][i] = i; }
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (cost[a][b] > c) {
			cost[a][b] = c;
			p[a][b] = a;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (cost[i][k] + cost[k][j] < cost[i][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
					p[i][j] = p[k][j];
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", cost[i][j] >= INF ? 0 : cost[i][j]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> answer;
			int cur = j;
			if (i == j || cost[i][j] >= INF) {
				printf("0\n");
				continue;
			}
			while (cur != i) {
				answer.push_back(cur);
				cur = p[i][cur];
			}
			if (!answer.empty()) answer.push_back(i);
			printf("%d", answer.size());
			for (int idx = answer.size() - 1; idx >= 0; idx--)
				printf(" %d", answer[idx]);
			printf("\n");
		}
	}

}
