#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int front[4][2] = { {0, 1} ,{0, -1}, {-1, 0}, {1, 0} };


int main() {
	int r, c, d, N, K, time;
	scanf("%d %d", &N, &K);
	vector<vector<int>> board (N, vector<int>(N));
	vector<vector<vector<pair<int, int>>>> chess(N, vector<vector<pair<int,int>>>(N));
	vector<pair<int, int>> pot;
	int h, dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &r, &c, &d);
		pot.push_back({ r - 1, c - 1 });
		chess[r - 1][c - 1].push_back({ i, d });
	}
	for (time = 0; time < 1000; time++) {
		for (int i = 0; i < K; i++) {
			int y = pot[i].first, x = pot[i].second;
			h = 0;
			while (h < chess[y][x].size() && chess[y][x][h].first != i) h++;
			dir = chess[y][x][h].second - 1;
			pair<int, int> f = { y + front[dir][0], x + front[dir][1] };
			if (f.first >= 0 && f.first < N && f.second >= 0 && f.second < N
				&& board[f.first][f.second] != 2) {
				if (board[f.first][f.second] == 0) {
					for (int j = h; j < chess[y][x].size(); j++)
					{
						chess[f.first][f.second].push_back(chess[y][x][j]);
						pot[chess[y][x][j].first] = f;
					}
					while (!chess[y][x].empty() && chess[y][x].size() != h)chess[y][x].pop_back();
				}
				else {
					while (!chess[y][x].empty() && chess[y][x].size() != h) {
						chess[f.first][f.second].push_back(chess[y][x].back());
						pot[chess[y][x].back().first] = f;
						chess[y][x].pop_back();
					}
				}
			}
			else {
				switch (chess[y][x][h].second) {
				case 1: chess[y][x][h].second = 2; break;
				case 2: chess[y][x][h].second = 1; break;
				case 3: chess[y][x][h].second = 4; break;
				case 4: chess[y][x][h].second = 3; break;
				}
				pair<int, int> b = { y - front[dir][0], x - front[dir][1] };
				if (b.first >= 0 && b.first < N && b.second >= 0 && b.second < N
					&& board[b.first][b.second] != 2) {
					if (board[b.first][b.second] == 0) {
						for (int j = h; j < chess[y][x].size(); j++)
						{
							chess[b.first][b.second].push_back(chess[y][x][j]);
							pot[chess[y][x][j].first] = b;
						}
						while (!chess[y][x].empty() && chess[y][x].size() != h)chess[y][x].pop_back();
					}
					else {
						while (!chess[y][x].empty() && chess[y][x].size() != h) {
							chess[b.first][b.second].push_back(chess[y][x].back());
							pot[chess[y][x].back().first] = b;
							chess[y][x].pop_back();
						}
					}
				}

			}
			if (chess[pot[i].first][pot[i].second].size() >= 4) {
				printf("%d", time + 1);
				return 0;
			}
		}

	}
	printf("-1");

}
