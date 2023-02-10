#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

bitset<1001> visited;
map<int, set<int>> m;

void dfs(int r) {
	visited[r] = 1;
	printf("%d ", r);
	for (int x : m[r]) {
		if (!visited[x]) dfs(x);
	}
}
void bfs(int r) {
	visited.reset();
	visited[r] = 1;
	queue<int> q;
	q.push(r);
	int u;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		printf("%d ", u);
		for (int v : m[u])
			if (visited[v] == 0) {
				visited[v] = 1;
				q.push(v);
			}
	}
}

int main()
{
	int N, M, V, u, v;
	scanf("%d%d%d", &N, &M, &V);
	visited.reset();
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		m[v].insert(u);
		m[u].insert(v);
	}
	dfs(V);
	printf("\n");
	visited.reset();
	bfs(V);
}
