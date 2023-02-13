#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	vector<int> game_map(101, 0);
	vector<int> dist(101, 2147483647);
	queue<int> q;
	int N, M, st, ed, u;
	scanf("%d%d", &N, &M);
	while (N--) {
		scanf("%d %d", &st, &ed);
		game_map[st] = ed - st;
	}
	while (M--) {
		scanf("%d %d", &st, &ed);
		game_map[st] = ed - st;
	}
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 1; u + i <= 100 && i <= 6; i++) {
			if (dist[u + i + game_map[u + i]] > dist[u] + 1) {
				dist[u + i + game_map[u + i]] = dist[u] + 1;
				q.push(u + i + game_map[u + i]);
			}
		}
	}
	printf("%d", dist[100]);

}
