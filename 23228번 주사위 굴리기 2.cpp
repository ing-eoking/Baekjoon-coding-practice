#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> score;
deque<int> w({ 6,4,1,3 }), h({ 6,5,1,2 });
int N, M, K;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void bfs(int i, int j) {
	pair<int, int> cur;
	queue<pair<int, int>> q;
	vector<pair<int, int>> real;
	vector<vector<bool>> visit(N, vector<bool>(M));
	q.push({ i, j });
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (board[cur.first][cur.second] != board[i][j]) continue;
		if (visit[cur.first][cur.second]) continue;
		visit[cur.first][cur.second] = true;
		real.push_back(cur);
		if(cur.first > 0) q.push({ cur.first - 1, cur.second });
		if(cur.first < N - 1) q.push({ cur.first + 1, cur.second });
		if(cur.second > 0) q.push({ cur.first, cur.second - 1 });
		if(cur.second < M - 1) q.push({ cur.first, cur.second + 1 });
	}
	int sc = board[i][j] * real.size();

	for (auto t : real)
		score[t.first][t.second] = sc;

}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	score = vector<vector<int>>(N, vector<int>(M));
	board = vector<vector<int>>(N, vector<int>(M));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &board[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (score[i][j] == 0) bfs(i, j);
	int dx = 0, dy = 0, dd = 0, sc = 0;
	while (K--) {
		if (dx + dir[dd][1] < 0 || dx + dir[dd][1] >= M ||
			dy + dir[dd][0] < 0 || dy + dir[dd][0] >= N) dd = (dd + 2) % 4;
		switch (dd) {
		case 0:
			w.push_front(w.back());
			w.pop_back();
			h[0] = w[0]; h[2] = w[2];
			dx++;
			break;
		case 1:
			h.push_back(h.front());
			h.pop_front();
			w[0] = h[0]; w[2] = h[2];
			dy++;
			break;
		case 2:
			w.push_back(w.front());
			w.pop_front();
			h[0] = w[0]; h[2] = w[2];
			dx--;
			break;
		case 3:
			h.push_front(h.back());
			h.pop_back();
			w[0] = h[0]; w[2] = h[2];
			dy--;
			break;
		}
		sc += score[dy][dx];
		if (w[0] > board[dy][dx]) dd = (dd + 5) % 4;
		else if (w[0] < board[dy][dx]) dd = (dd + 3) % 4;
	}
	printf("%d", sc);



}
