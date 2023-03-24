#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
vector<vector<int>> root(1);
vector<vector<pair<int,int>>> dir(6);
vector<int> cmd(10);

int _max = 0;

void initBoard() {
	int id = 0;
	for (int i = 0; i <= 20; i++) root[0].push_back(i * 2);
	for (int i = 0; i < 5; i++) root[0].push_back(0);
	root.push_back({10,13,16,19,25,30,35,40,0});
	root.push_back({20,22,24,25,30,35,40,0});
	root.push_back({30,28,27,26,25,30,35,40,0});
	root.push_back({ 25,30,35,40,0,0,0,0,0 });
	root.push_back({ 40,0,0,0,0,0 });
	for (int i = 0; i < root.size(); i++)
		for (int j = 0; j < root[i].size(); j++)
			dir[i].push_back({ i, j });
	dir[0][5] = { 1, 0 };
	dir[0][10] = { 2, 0 };
	dir[0][15] = { 3 , 0 };
	dir[0][20] = { 5, 0 };
	dir[3][4] = dir[2][3] = dir[1][4] = { 4,0 };
	dir[3][5] = dir[2][4] = dir[1][5] = { 4,1 };
	dir[3][6] = dir[2][5] = dir[1][6] = { 4,2 };
	dir[4][3] = dir[0][20] = dir[1][7] = dir[2][6] = dir[3][7] = { 5, 0 };
}

void dfs(vector<pair<int, int>> pos, int yet, int cur, int score) {
	if (cur >= 10) {
		if (_max < score) _max = score;
		return;
	}
	for (int i = 0; i < yet; i++) {
		if (root[pos[i].first][pos[i].second] == 0) continue;
		pair<int, int> go = dir[pos[i].first][pos[i].second + cmd[cur]];
		bool able = true;
		for (int j = 0; j < pos.size(); j++)
			if (pos[j] == go) {
				able = false;
				break;
			}
		if (able) {
			if (root[go.first][go.second] == 0) go = { 0,0 };
			vector<pair<int, int>> p = pos;
			p[i] = go;
			dfs(p, yet, cur + 1, score + root[go.first][go.second]);
		}
	}
	if (yet < 4) {
		pair<int, int> go = dir[0][cmd[cur]];
		bool able = true;
		for (int j = 0; j < 4; j++)
			if (pos[j] == go) {
				able = false;
				break;
			}
		if (able) {
			vector<pair<int, int>> p = pos;
			p[yet] = go;
			dfs(p, yet + 1, cur + 1, score + root[go.first][go.second]);
		}

	}
}

int main() {
	initBoard();
	vector<pair<int, int>> pos(4);
	int yet = 0;
	for (int i = 0; i < 10; i++)scanf(" %d", &cmd[i]);
	dfs(pos, 0, 0, 0);
	printf("%d", _max);
}
