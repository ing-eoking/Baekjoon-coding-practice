#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>

using namespace std;

int N;

multiset<int> s;
vector<vector<int>> space;
bitset<20> visit[20];

pair<int, int> shark = { 0,0 };
int height = 2, eat = 0;

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ shark, 0 });
	for (int i = 0; i < N; i++) visit[i].reset();
	pair<pair<int, int>, int> temp;
	int r, c, d;
	while (!q.empty()) {
		vector<pair<int, int>> v;
		d = q.front().second;
		while (!q.empty() && q.front().second == d) {
			v.push_back(q.front().first);
			q.pop();
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			r = v[i].first;
			c = v[i].second;
			if (space[r][c] > 0 && space[r][c] < height) {
				s.erase(s.find(space[r][c]));
				space[r][c] = 0;
				shark.first = r;
				shark.second = c;
				if (height < 7 && eat < height) {
					eat++;
					if (eat == height) {
						height++;
						eat = 0;
					}
				}
				return d;
			}
			visit[r][c] = true;
			if (r > 0 && !visit[r - 1][c] && space[r - 1][c] <= height)
				q.push({ {r - 1, c}, d + 1 });
			if (c > 0 && !visit[r][c - 1] && space[r][c - 1] <= height)
				q.push({ {r, c - 1}, d + 1 });
			if (c < N - 1 && !visit[r][c + 1] && space[r][c + 1] <= height)
				q.push({ {r, c + 1}, d + 1 });
			if (r < N - 1 && !visit[r + 1][c] && space[r + 1][c] <= height)
				q.push({ {r + 1, c}, d + 1 });
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);
	space = vector<vector<int>>(N, vector<int>(N));
	int fish = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &space[i][j]);
			if (space[i][j] > 0) {
				if (space[i][j] == 9) {
					shark = { i,j };
					space[i][j] = 0;
				}
				else s.insert(space[i][j]);
			}
		}
	int t = 0, time = 0;
	while (!s.empty() && height > *s.begin() && (t = bfs())) {
		time += t;
	}
	printf("%d", time);

}
