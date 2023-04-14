#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int N;
long long all = 0, sum = 0;
vector<vector<int>> edge, child;
vector<int> parent, sz;

void tree(int cur, int par) {
	for (int n : edge[cur])
		if (n != par) {
			child[cur].push_back(n);
			parent[n] = cur;
			tree(n, cur);
		}
}
void subtree(int cur) {
	sz[cur] = 1;
	for (int n : child[cur]) {
		subtree(n);
		sz[cur] += sz[n];
	}
}

void dfs(int cur) {
	for (int i : child[cur]) {
		sum += all - ((long long)N - (long long)sz[i]) * ((long long)N - (long long)sz[i] - 1) / 2;
		dfs(i);
	}
}


int main() {
	scanf("%d", &N);
	child = edge = vector<vector<int>>(N);
	parent = sz = vector<int>(N);
	int a, b;
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	tree(0, -1);
	subtree(0);
	all = (long long)N * (long long)(N - 1) / 2;
	dfs(0);
	printf("%lld", sum);

}
