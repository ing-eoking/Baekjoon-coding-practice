#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int mov[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };

int N, M;
vector<vector<vector<int>>> visit;
vector<string> m;

int bfs() {
	queue<pair<pair<int,int>, int>> q;
	pair<pair<int, int>, int> u;
	int y, x, z, ax, ay;
	q.push({{0,0}, 0});
	visit[0][0][0] = 1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		y = u.first.first;
		x = u.first.second;
		z = u.second;
		if (y == N - 1 && x == M - 1) return visit[y][x][z];
		for (int i = 0; i < 4; i++) {
			ay = y + mov[i][0];
			ax = x + mov[i][1];
			if(0 <= ax && ax < M && 0 <= ay && ay < N )
				if (m[ay][ax] == '0' && visit[ay][ax][z] == 0) {
					visit[ay][ax][z] = visit[y][x][z] + 1;
					q.push({ {ay, ax}, z });
				}
				else if (m[ay][ax] == '1' && z == 0) {
					visit[ay][ax][z + 1] = visit[y][x][z] + 1;
					q.push({ {ay, ax}, (z + 1) });
				}
		}
	}
	return -1;
}
int main()
{
	char buf[1001];
	scanf("%d%d", &N, &M);
	visit = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(2)));
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		m.push_back(buf);
	}
	printf("%d", bfs());

}
