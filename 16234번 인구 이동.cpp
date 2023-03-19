#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> m;
int N, L, R;

vector<vector<bool>> visit;

bool bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	pair<int, int> cur;
	int sum = 0;
	vector<pair<int, int>> hist;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (!visit[cur.first][cur.second]) continue;
		sum += m[cur.first][cur.second];
		hist.push_back(cur);
		visit[cur.first][cur.second] = false;
		if (visit[cur.first - 1][cur.second] &&
			abs(m[cur.first - 1][cur.second] - m[cur.first][cur.second]) >= L &&
			abs(m[cur.first - 1][cur.second] - m[cur.first][cur.second]) <= R)
			q.push({ cur.first - 1, cur.second });
		if (visit[cur.first + 1][cur.second] &&
			abs(m[cur.first + 1][cur.second] - m[cur.first][cur.second]) >= L &&
			abs(m[cur.first + 1][cur.second] - m[cur.first][cur.second]) <= R)
			q.push({ cur.first + 1, cur.second });
		if (visit[cur.first][cur.second - 1] &&
			abs(m[cur.first][cur.second - 1] - m[cur.first][cur.second]) >= L &&
			abs(m[cur.first][cur.second - 1] - m[cur.first][cur.second]) <= R)
			q.push({ cur.first, cur.second - 1 });
		if (visit[cur.first][cur.second + 1] &&
			abs(m[cur.first][cur.second + 1] - m[cur.first][cur.second]) >= L &&
			abs(m[cur.first][cur.second + 1] - m[cur.first][cur.second]) <= R)
			q.push({ cur.first, cur.second + 1 });
	}
	for (auto i : hist)
		m[i.first][i.second] = sum / (hist.size());
	if (hist.size() > 1) return true;
	else return false;
}

int main() {
	scanf("%d%d%d", &N, &L, &R);
	m = vector<vector<int>>(N+2, vector<int>(N+2, 999999));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) scanf("%d", &m[i][j]);
	bool tf = true;
	int t;
	for (t = 0; tf; t++) {
		tf = false;
		visit = vector<vector<bool>>(N + 2, vector<bool>(N + 2, true));
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if(visit[r][c]) tf = tf | bfs(r, c);
			}
		}
	}

	printf("%d", t - 1);
}
