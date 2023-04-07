#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> search;
vector<vector<int>> heat;
vector<vector<int>> add;
set < pair< pair< int, int >, pair<int, int> > > wall;
int R, C, K;

int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

void dfs(int i, int j, int cur, const int & d) {
	if (i < 0 || i >= R || j < 0 || j >= C) return;
	if (cur < 1 || add[i][j] != 0) return;
	add[i][j] = cur;
	int str = i + dir[d][0], stc = j + dir[d][1];
	int r1 = i + dir[d][1], c1 = j + dir[d][0];
	int rr1 = r1 + dir[d][0], cc1 = c1 + dir[d][1];
	int r2 = i - dir[d][1], c2 = j - dir[d][0];
	int rr2 = r2 + dir[d][0], cc2 = c2 + dir[d][1];
	if (wall.find({ {i, j}, {str, stc} }) == wall.end()) dfs(str, stc, cur - 1, d);
	if (wall.find({ {i, j}, {r1, c1} }) == wall.end() &&
		wall.find({ {r1, c1}, {rr1, cc1} }) == wall.end()) dfs(rr1, cc1, cur - 1, d);
	if (wall.find({ {i, j}, {r2, c2} }) == wall.end() &&
		wall.find({ {r2, c2}, {rr2, cc2} }) == wall.end()) dfs(rr2, cc2, cur - 1, d);

}

int main() {
	scanf("%d %d %d", &R, &C, &K);
	vector<vector<int>> v(R, vector<int>(C));
	vector<vector<int>> adding = v;
	for(int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			scanf("%d", &v[i][j]);
			if (v[i][j] == 5) {
				search.push_back({ i, j });
			}
			else if (v[i][j] > 0) {
				heat.push_back({ i, j, v[i][j] - 1 });
			}
			v[i][j] = 0;
		}
	int W, x, y, t;
	scanf("%d", &W);
	while (W--) {
		scanf("%d%d%d", &x, &y, &t);
		x--; y--;
		wall.insert({ {x - !t, y + t}, {x, y} });
		wall.insert({ {x, y}, {x - !t, y + t} });
	}
	for (vector<int> i : heat) {
		add = vector < vector<int>>(R, vector<int>(C));
		dfs(i[0] + dir[i[2]][0], i[1] + dir[i[2]][1], 5, i[2]);
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				adding[r][c] += add[r][c];
	}
	int choco = 0;
	for (choco = 0; choco <= 100; choco++) {
		bool tf = true;
		for (vector<int> i : search) {
			if (v[i[0]][i[1]] < K) {
				tf = false;
				break;
			}
		}
		if (tf) break;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) v[i][j] += adding[i][j];
		vector<vector<int>> temp = v;
		for(int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if (i > 0 && wall.find({ {i - 1, j}, {i , j} }) == wall.end())
					temp[i][j] += (v[i - 1][j] - v[i][j]) / 4;
				if (i < R-1 && wall.find({ {i + 1, j}, {i , j} }) == wall.end())
					temp[i][j] += (v[i + 1][j] - v[i][j]) / 4; 
				if (j > 0 && wall.find({ {i, j - 1}, {i , j} }) == wall.end())
					temp[i][j] += (v[i][j - 1] - v[i][j]) / 4;
				if (j < C-1 && wall.find({ {i, j + 1}, {i , j} }) == wall.end())
					temp[i][j] += (v[i][j + 1] - v[i][j]) / 4;
			}
		v = temp;
		for (int i = 1; i < R - 1; i++) {
			if(v[i][0]) v[i][0]--;
			if(v[i][C - 1])v[i][C - 1]--;
		}
		for (int i = 1; i < C - 1; i++) {
			if(v[0][i]) v[0][i]--;
			if(v[R - 1][i]) v[R - 1][i]--;
		}
		if(v[0][0]) v[0][0]--;
		if(v[0][C - 1]) v[0][C - 1]--;
		if(v[R - 1][0]) v[R - 1][0]--;
		if(v[R - 1][C - 1]) v[R - 1][C - 1]--;


	}
	printf("%d", choco);
}
