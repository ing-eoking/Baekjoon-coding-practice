#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int dir[8][2] = { {-1,0} , {-1,-1}, {0, -1}, {1, -1}, {1, 0},{1, 1}, {0, 1},{-1, 1} };
int _max = 0;

void dfs(vector<vector<pair<int, int>>> &space, pair<int, int> shark, int score) {

	map<int, pair<int, int>> fish;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (space[i][j].first > 0) fish[space[i][j].first] = { i, j };
	for (auto i : fish) {
		int id = i.first, r = i.second.first, c = i.second.second;
		pair<int, int> go;
		bool movx = true;
		for (int d = 0; d < 8; d++) {
			go = {r + dir[(space[r][c].second + d + 8) % 8][0],
				c + dir[(space[r][c].second + d + 8) % 8][1] };
			if (go.first >= 0 && go.first < 4 && go.second >= 0 && go.second < 4
				&& space[go.first][go.second].first >= 0) {
				space[r][c].second = (space[r][c].second + d + 8) % 8;
				movx = false;
				break;
			}
		}
		if (movx) continue;
		if (space[go.first][go.second].first > 0) {
			fish[id] = go;
			fish[space[go.first][go.second].first] = { r,c };
		}
		swap(space[r][c], space[go.first][go.second]);
	}
	vector<pair<int, int>> eating;
	for (int i = 1; i < 4; i++) {
		int r = shark.first + dir[space[shark.first][shark.second].second][0] * i;
		int c = shark.second + dir[space[shark.first][shark.second].second][1] * i;
		if (r < 0 || r >= 4 || c < 0 || c >= 4) break;
		if (space[r][c].first > 0) eating.push_back({r,c});
	}
	if (eating.empty()) {
		if (_max < score) _max = score;
		return;
	}
	for (auto i : eating) {
		int r = i.first, c = i.second;
		int sc = score + space[r][c].first;
		vector<vector<pair<int, int>>> temp = space;
		temp[shark.first][shark.second] = { 0,0 };
		temp[r][c].first = -1;

		dfs(temp, i, sc);
	}

}
int main() {
	vector<vector<pair<int, int>>> space(4, vector<pair<int, int>>(4));
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			scanf(" %d %d", &space[i][j].first, &space[i][j].second);
			space[i][j].second--;
		}
	
	pair<int, int> shark = {0, 0};
	int sum = space[0][0].first;
	space[0][0] = { -1, space[0][0].second };
	dfs(space, shark, sum);
	printf("%d", _max);
}
