#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void calcDist(pair<int, int> st, vector<vector<bool>> m, vector<vector<int>>& dist) {
	queue<pair<int, pair<int, int>>> q;
	dist = vector<vector<int>>(m.size(), vector<int>(m.size(), 999999));
	int d, r, c, N = m.size();
	q.push({ 0, st });
	while (!q.empty()) {
		d = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();
		if (m[r][c]) continue;
		m[r][c] = true;
		dist[r][c] = d;
		if (r + 1 < N && !m[r + 1][c]) q.push({ d + 1, {r + 1, c} });
		if (r - 1 >= 0 && !m[r - 1][c]) q.push({ d + 1, {r - 1, c} });
		if (c + 1 < N && !m[r][c + 1]) q.push({ d + 1, {r, c + 1} });
		if (c - 1 >= 0 && !m[r][c - 1]) q.push({ d + 1, {r, c - 1} });
	}
}

int main() {
	int N, M, fuel, num;
	scanf("%d%d%d", &N, &M, &fuel);
	vector<vector<bool>> m(N, vector<bool>(N));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			m[i][j] = num;
		}
	vector<vector<int>> dist(N, vector<int>(N));

	pair<int, int> bj;
	scanf("%d %d", &bj.first, &bj.second);
	bj.first--; bj.second--;
	pair<int, int> st, dst;
	map<pair<int, int>, pair<int, int>> cst;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &st.first, &st.second, &dst.first, &dst.second);
		st.first--; st.second--;
		dst.first--; dst.second--;
		cst[st] = dst;
	}
	while (!cst.empty()) {
		calcDist(bj, m, dist);
		pair<int, int> dcst;
		int d = 999999;
		for (auto it : cst) {
			int r = it.first.first, c = it.first.second;
			int di = abs(dist[r][c] - dist[bj.first][bj.second]);
			if (d > di) {
				d = di;
				dcst = it.first;
			}
		}
		calcDist(dcst, m, dist);
		int mov = abs(dist[dcst.first][dcst.second] - dist[cst[dcst].first][cst[dcst].second]);
		if (d + mov > fuel) {
			printf("-1");
			return 0;
		}
		fuel -= (d - mov);
		bj = cst[dcst];
		cst.erase(dcst);

	}
	printf("%d", fuel);
}
