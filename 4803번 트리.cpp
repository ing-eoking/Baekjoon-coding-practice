#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int root, int bef, vector<vector<int>> &edge, vector<bool>& visit) {
	visit[root] = true;
	for (int i : edge[root])
		if (i == bef) continue;
		else if (visit[i]) return false;
		else if(!dfs(i, root, edge, visit)) return false;
	return true;

}

int main() {
	int n, m, a, b;
	for (int c = 1; ; c++) {
		int answer = 0;
		scanf("%d %d", &n, &m);
		if (!n && !m) break;
		vector<vector<int>> edge(n + 1);
		vector<bool> visit(n+1);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) 
			if (!visit[i] && dfs(i, 0, edge, visit)) answer++;
		printf("Case %d: ", c);
		if (answer == 0) printf("No trees.\n");
		else if (answer == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", answer);
	}
}
