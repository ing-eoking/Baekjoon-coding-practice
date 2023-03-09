#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> v;

inline int find(int root) {
	while (root != v[root]) root = v[root];
	return root;
}

int main() {
	set<pair<int, pair<int, int>>> s;
	int m, n, x, y, z, pa, pb, cost = 0;
	while (true) {
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0) break;
		cost = 0;
		while (n--) {
			scanf("%d%d%d", &x, &y, &z);
			s.insert({ z, {x,y} });
			cost += z;
		}
		v = vector<int>(m);
		for (int i = 1; i < m; i++) v[i] = i;
		for (auto i : s) {
			pa = find(i.second.first);
			pb = find(i.second.second);
			if (pa == pb) continue;
			else if (pa < pb) v[pb] = pa;
			else v[pa] = pb;
			cost -= i.first;
		}
		printf("%d\n", cost);
		s.clear();
	}
}
