#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

bitset<100000> visited;
map<int, set<int, greater<int>>> m;
vector<int> ord;
int cur = 1;

void bfs(int r) {
	visited.reset();
	visited[r] = 1;
	queue<int> q;
	q.push(r);
	int u;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		ord[u] = cur++;
		for(int v : m[u]) {
			if (visited[v] == 0) {
				visited[v] = 1;
				q.push(v);
			}
		}
	}

}

int main()
{
	int N, M, R, u, v;
	scanf("%d%d%d", &N, &M, &R);
	ord = vector<int>(N + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		m[v].insert(u);
		m[u].insert(v);
	}
	bfs(R);
	for (int i = 1; i <= N; i++)
		printf("%d\n", ord[i]);
}
