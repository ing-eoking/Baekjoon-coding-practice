#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> island;
vector<vector<int>> bridge(7, vector<int>(7, 99999999));
vector<int> v;

inline int find(int root) {
	while (root != v[root]) root = v[root];
	return root;
}
bool fin() {
	int pa = find(1), pb;
	for (int i = 1; i < v.size(); i++) {
		pb = find(i);
		if (pa != pb) return false;
		v[i] = pa = pb;
	}
	return true;
}

void dfs(int i, int j, const int& idx) {
	if(island[i][j] < 0){
		island[i][j] = idx;
		dfs(i - 1, j, idx);
		dfs(i + 1, j, idx);
		dfs(i, j - 1, idx);
		dfs(i, j + 1, idx);
	}
}

int main() {
	int N, M, num, iidx = 1, pa, pb, dist = 0;
	scanf("%d%d", &N, &M);
	island = vector<vector<int>>(N + 2, vector<int>(M + 2));
	set<pair<int, pair<int, int>>> s;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) {
			scanf("%d", &island[i][j]);
			island[i][j] *= -1;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (island[i][j] < 0) {
				int a = iidx++;
				dfs(i, j, a);
			}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++){
			if (island[i][j] != 0) {
				int t = i + 1;
				while (t < N - 1 && island[t][j] == 0) t++;
				if (t < N - 1 && t > i + 2 && island[t][j] != island[i][j])
					bridge[island[i][j]][island[t][j]] = min(bridge[island[i][j]][island[t][j]], t - i - 1);
				t = i - 1;
				while (t > 0 && island[t][j] == 0) t--;
				if (t > 0 && t < i - 2 && island[t][j] != island[i][j])
					bridge[island[i][j]][island[t][j]] = min(bridge[island[i][j]][island[t][j]], i - t - 1);
				t = j + 1;
				while (t < M - 1 && island[i][t] == 0) t++;
				if (t < M - 1 && t > j + 2 && island[i][t] != island[i][j])
					bridge[island[i][j]][island[i][t]] = min(bridge[island[i][j]][island[i][t]], t - j - 1);
				t = j - 1;
				while (t > 0 && island[i][t] == 0) t--;
				if (t > 0 && t < j - 2 && island[i][t] != island[i][j])
					bridge[island[i][j]][island[i][t]] = min(bridge[island[i][j]][island[i][t]], j - t - 1);
			}
		}
	for (int i = 1; i < iidx; i++) {
		for(int j = 1; j < iidx; j++)
			if (bridge[i][j] <= N * M) {
				s.insert({ bridge[i][j], {i,j} });
			}
	}
	v = vector<int>(iidx);
	for (int i = 1; i < iidx; i++) v[i] = i;
	for (auto i : s) {
		if (fin()) break;
		pa = find(i.second.first);
		pb = find(i.second.second);
		if (pa == pb) continue;
		else if (pa < pb) v[pb] = pa;
		else v[pa] = pb;
		dist += i.first;
	}
	if (fin()) printf("%d", dist);
	else printf("-1");
}
