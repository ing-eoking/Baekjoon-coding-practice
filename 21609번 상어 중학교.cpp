#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> block;
vector<vector<vector<bool>>> visit(2);

int N, M;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

pair<int, int> dfs(int i, int j, const int& cur) {
	if (i < 0 || i >= N || j < 0 || j >= N) return { 0,0 };
	if (block[i][j] < 0 || visit[0][i][j]) return { 0,0 };
	if (block[i][j] != cur && block[i][j] != 0) return { 0,0 };
	visit[0][i][j] = true;
	if(block[i][j] > 0) visit[1][i][j] = true;
	pair<int, int> tmp, all = { 0,0 };
	if (block[i][j] == cur) all = { 1, 0 };
	else all = { 1, 1 };
	for (int a = 0; a < 4; a++) {
		tmp = dfs(i + dir[a][0], j + dir[a][1], cur);
		all.first += tmp.first;
		all.second += tmp.second;
	}
	return all;
}
void rmdfs(int i, int j, const int& cur) {
	if (i < 0 || i >= N || j < 0 || j >= N) return;
	if (block[i][j] < 0) return;
	if (block[i][j] != cur && block[i][j] > 0) return;
	block[i][j] = -2;
	for (int a = 0; a < 4; a++)
		rmdfs(i + dir[a][0], j + dir[a][1], cur);
}
void gravity() {
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (block[i][j] == -2) {
				for (int k = i - 1; k >= 0; k--) {
					if (block[k][j] !=  -1) 
						swap(block[k+1][j], block[k][j]);
					else break;
				}
			}
		}
}
void rotate() {
	vector<vector<int>> temp(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = block[j][N - 1 - i];
	block = temp;
}


int main() {
	int score = 0;
	scanf("%d %d", &N, &M);
	block = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &block[i][j]);
	while (true) {
		visit[0] = visit[1] = vector<vector<bool>>(N, vector<bool>(N));
		map<pair<int, int>, vector<pair<int, int>>> g;
		pair<int, int> tg;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) 
				if (block[i][j] > 0 && !visit[0][i][j]) {
					visit[0] = visit[1];
					tg = dfs(i, j, block[i][j]);
					if(tg.first > 1) g[tg].push_back({ i, j });
				}
		
		if (g.empty()) break;
		auto it = --g.end();
		int num = it->first.first;
		score += num * num;
		int r = it->second.back().first, c = it->second.back().second;
		int cur = block[r][c];
		rmdfs(r, c, cur);
		gravity();
		rotate();
		gravity();
	}
	printf("%d", score);
}
