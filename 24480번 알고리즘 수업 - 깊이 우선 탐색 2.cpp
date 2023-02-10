#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <map>
#include <set>
#include <vector>

using namespace std;

bitset<100000> visited;
map<int, set<int, greater<int>>> m;
vector<int> ord;
int cur = 1;

void dfs(int r) {
	visited[r] = 1;
	ord[r] = cur++;
	for (int x : m[r]) {
		if (!visited[x]) dfs(x);
	}
}

int main()
{
	int N, M, R, u, v;
	scanf("%d%d%d", &N, &M, &R);
	ord = vector<int>(N + 1);
	visited.reset();
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		m[v].insert(u);
		m[u].insert(v);
	}
	dfs(R);
	for (int i = 1; i <= N; i++)
		printf("%d\n", ord[i]);
}
