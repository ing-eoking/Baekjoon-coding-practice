#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

vector<int> v;

inline int find(int root) {
	while (root != v[root]) root = v[root];
	return root;
}
bool fin() {
	int pa = find(0), pb;
	for (int i = 0; i < v.size(); i++) {
		pb = find(i);
		if (pa != pb) return false;
		v[i] = pa = pb;
	}
	return true;
}


int main() {
	int N, M, a, b, pa, pb;
	double dist = 0;
	scanf("%d%d", &N, &M);
	vector<pair<int, int>> c(N+1);
	v = vector<int>(N + 1);
	for (int i = 1; i <= N; i++) v[i] = i;
	set<pair<double, pair<int, int>>> s;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &c[i].first, &c[i].second);
		for (int j = 1; j < i; j++)
			s.insert({
				sqrt(pow(c[j].first - c[i].first, 2) + pow(c[j].second - c[i].second, 2)),
				{i, j}
			});
	}
	while (M--) {
		scanf("%d%d", &a, &b);
		pa = find(a);
		pb = find(b);
		if (pa < pb) v[pb] = pa;
		else v[pa] = pb;
	}
	for (auto i : s) {
		if (fin()) break;
		pa = find(i.second.first);
		pb = find(i.second.second);
		if (pa == pb) continue;
		else if (pa < pb) v[pb] = pa;
		else v[pa] = pb;
		dist += i.first;
	}
	printf("%.2f", dist);
}
