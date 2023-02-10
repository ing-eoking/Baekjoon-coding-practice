#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, M, u, v;
	scanf("%d %d", &N, &M);
	bitset<101> edge[101];
	bitset<101> visited;
	while (M--) {
		scanf("%d %d", &u, &v);
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0 && edge[u][i]) {
				visited[i] = 1;
				edge[1][i] = 1;
				q.push(i);
			}
		}
	}
	printf("%d", edge[1].count());
}
