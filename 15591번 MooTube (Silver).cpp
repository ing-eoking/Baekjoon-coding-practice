#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000

vector<vector<pair<int, int>>> edge;

int sum = 0;

void dfs(int cur, int prev, int mini, int k) {
	if (prev >= 0 && mini >= k) sum++;
	for (auto i : edge[cur]) {
		if (i.first == prev) continue;
		dfs(i.first, cur, min(mini, i.second), k);
	}
}

int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	int p, q, r;
	edge = vector<vector<pair<int, int>>>(N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &p, &q, &r);
		p--; q--;
		edge[p].push_back({ q,r });
		edge[q].push_back({ p,r });
	}
	int k, v;
	while (Q--) {
		scanf("%d%d", &k, &v);
		sum = 0;
		dfs( v - 1, -1, INF, k);
		printf("%d\n", sum);
	}

	
}
