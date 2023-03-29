#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
set<pair<pair<int, int>, pair<int, int>>> wall;
int R, C, K;

void dfs(int r, int c, int cur, int d, vector<vector<int>> & v) {
	if (r < 0 || r >= R || c < 0 || c >= C) return;
	if (cur < 1) return;
	v[r][c] = cur;
	int mr = r + dir[d][0], mc = c + dir[d][1];

	if (wall.find({ {r, c}, { mr, mc } }) == wall.end()) dfs(mr, mc, cur - 1, d, v);
	mr = r - dir[d][1]; mc = c - dir[d][0];
	int mmr = mr + dir[d][0], mmc = mc + dir[d][1];

	if (wall.find({ {r,c}, {mr, mc} }) == wall.end() &&
		wall.find({ { mr, mc }, {mmr, mmc} }) == wall.end())
		dfs(mmr, mmc, cur - 1, d, v);
	mr = r + dir[d][1]; mc = c + dir[d][0];
	mmr = mr + dir[d][0]; mmc = mc + dir[d][1];

	if (wall.find({ {r,c}, {mr, mc} }) == wall.end() &&
		wall.find({ {mr, mc}, {mmr, mmc} }) == wall.end())
		dfs(mmr, mmc, cur - 1, d, v);
}
void adjust(vector<vector<int>>& room) {
	vector<vector<int>> temp = room;
	for (int i = 0; i < room.size(); i++)
		for (int j = 0; j < room[0].size(); j++) {
			int sm = 0;
			for (int a = 0; a < 4; a++) {
				int ar = i + dir[a][0], ac = j + dir[a][1];
				if (ar >= 0 && ar < room.size() && ac >= 0 && ac < room[0].size()) {
					if (room[i][j] > room[ar][ac] && wall.find({ {i,j}, {ar, ac} }) == wall.end()) {
						int bet = (room[i][j] - room[ar][ac]) / 4;
						temp[ar][ac] += bet;
						sm += bet;
					}
				}
			}
			temp[i][j] -= sm;
		}
	room = temp;
}
void side(vector<vector<int>>& room) {
	int A = room.size(), B = room[0].size();
	for (int j = 1; j < B - 1; j++) {
		if (room[0][j] > 0) room[0][j]--;
		if (room[A - 1][j] > 0) room[A - 1][j]--;
	}
	for (int i = 1; i < A - 1; i++) {
		if (room[i][0] > 0) room[i][0]--;
		if (room[i][B - 1] > 0) room[i][B - 1]--;
	}
	if (room[0][0] > 0) room[0][0]--;
	if (room[0][B - 1] > 0) room[0][B - 1]--;
	if (room[A - 1][0] > 0) room[A - 1][0]--;
	if (room[A - 1][B - 1] > 0) room[A - 1][B - 1]--;
}

int main() {
	scanf("%d %d %d", &R, &C, &K);
	vector<vector<int>> room(R, vector<int>(C));
	vector<pair<int, int>> warm, survey;
	int choco = 0;
	for(int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &room[i][j]);
			if (room[i][j] > 0 && room[i][j] < 5) warm.push_back({ i,j });
			if (room[i][j] == 5) survey.push_back({ i, j });
		}
	int num;
	scanf("%d", &num);
	int x, y, t;
	while (num--) {
		scanf("%d %d %d", &x, &y, &t);
		if (t == 0) {
			wall.insert({ {x - 2, y - 1}, { x - 1, y - 1 }});
			wall.insert({ {x - 1, y - 1}, { x - 2, y - 1 }});
		}
		if (t == 1) {
			wall.insert({ {x - 1, y - 1}, { x - 1, y }});
			wall.insert({ {x - 1, y}, { x - 1, y - 1 }});
		}
	}

	vector<vector<vector<int>>> add(warm.size(), vector<vector<int>>(R, vector<int>(C)));
	for (int i = 0; i < add.size(); i++) {
		int r = warm[i].first, c = warm[i].second;
		int d = room[r][c] - 1;
		int mr = r+ dir[d][0], mc = c + dir[d][1];
		dfs(mr, mc, 5, d, add[i]);
	}
	vector<vector<int>> adding(R, vector<int>(C));
	for (int w = 0; w < add.size(); w++)
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				adding[i][j] += add[w][i][j];
	room = vector<vector<int>>(R, vector<int>(C));
	bool search = true;
	while (search) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				room[i][j] += adding[i][j];
		
		adjust(room);
		side(room);
		choco++;
		if (choco > 100) break;
		search = false;
		for (auto i : survey) {
			if (room[i.first][i.second] < K) {
				search = true;
				break;
			}
		}

	}
	printf("%d", choco);
}
