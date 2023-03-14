#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M, mini = 999999;
vector<string> board;
pair<int, int> hole;


void dfs(pair<int, int> red, pair<int, int> blue, int cur) {
	if (blue == hole || cur > 10) return;
	if (red == hole) {
		if (mini > cur) mini = cur;
		return;
	}
	pair<int, int> u_r = red, d_r = red, l_r = red, r_r =red, tmp;
	pair<int, int> u_b = blue, d_b = blue, l_b = blue, r_b = blue;
	bool tf = false;
	while (true) {
		tf = false;
		tmp = { u_r.first - 1, u_r.second };
		if (u_r.first - 1 > 0 && board[u_r.first - 1][u_r.second] != '#' && u_r != hole) {
			if ((u_b != hole && tmp != u_b) || u_b == hole) {
				u_r.first--;
				tf = true;
			}
		}
		tmp = { u_b.first - 1, u_b.second };
		if (u_b.first - 1 > 0 && board[u_b.first - 1][u_b.second] != '#' && u_b != hole) {
			if ((u_r != hole && tmp != u_r) || u_r == hole) {
				u_b.first--;
				tf = true;
			}
		}
		if (!tf) break;
	}
	while (true) {
		tf = false;
		tmp = { d_r.first + 1, d_r.second };
		if (d_r.first + 2 < N && board[d_r.first + 1][d_r.second] != '#' && d_r != hole) {
			if ((d_b != hole && tmp != d_b) || d_b == hole) {
				d_r.first++;
				tf = true;
			}
		}
		tmp = { d_b.first + 1, d_b.second };
		if (d_b.first + 2 < N && board[d_b.first + 1][d_b.second] != '#' && hole != d_b) {
			if ((d_r != hole && tmp != d_r) || d_r == hole) { d_b.first++; tf = true; }
		}
		if (!tf) break;
	}
	while (true) {
		tf = false;
		tmp = { l_r.first, l_r.second - 1 };
		if (l_r.second - 1 > 0 && board[l_r.first][l_r.second - 1] != '#' && hole != l_r) {
			if ((l_b != hole && tmp != l_b) || l_b == hole) {
				l_r.second--;
				tf = true;
			}
		}
		tmp = { l_b.first, l_b.second - 1 };
		if (l_b.second - 1 > 0 && board[l_b.first][l_b.second - 1] != '#' && hole != l_b) {
			if ((l_r != hole && tmp != l_r) || l_r == hole) {
				tf = true; l_b.second--;
			}
		}
		if (!tf) break;
	}

	while (true) {
		tf = false;
		tmp = { r_r.first, r_r.second + 1 };
		if (r_r.second + 2 < M && board[r_r.first][r_r.second + 1] != '#' && hole != r_r) {
			if ((r_b != hole && tmp != r_b) || r_b == hole){r_r.second++;
			tf = true;
			}
		}
		tmp = { r_b.first, r_b.second + 1 };
		if (r_b.second + 2 < M && board[r_b.first][r_b.second + 1] != '#' && hole != r_b) {
			if ((r_r != hole && tmp != r_r) || r_r == hole) { r_b.second++; tf = true; }
		}
		if (!tf) break;
	}
	if(u_r != red || u_b != blue) dfs(u_r, u_b, cur + 1);
	if(d_r != red || d_b != blue) dfs(d_r, d_b, cur + 1);
	if(l_r != red || l_b != blue) dfs(l_r, l_b, cur + 1);
	if(r_r != red || r_b != blue) dfs(r_r, r_b, cur + 1);

}

int main() {
	scanf("%d%d", &N, &M);
	char buf[11];
	pair<int, int> red, blue;
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		board.push_back(buf);
		for (int j = 0; j < M; j++)
			if (board[i][j] == 'R') red = { i, j };
			else if (board[i][j] == 'B') blue = { i, j };
			else if (board[i][j] == 'O') hole = { i,j };
	}


	dfs(red, blue, 0);
	if (mini < 999999)printf("%d", mini);
	else printf("-1");

}
