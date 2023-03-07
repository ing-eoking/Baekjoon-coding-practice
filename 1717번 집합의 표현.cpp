#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

inline int find(int idx) {
	while (v[idx] != idx) idx = v[idx];
	return idx;
}

int main() {
	int n, m, d, a, b, pa, pb;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) v.push_back(i);
	while (m--) {
		scanf("%d %d %d", &d, &a, &b);
		pa = find(a); pb = find(b);
		if (d) {
			if (pa == pb) printf("YES\n");
			else printf("NO\n");
		}
		else {
			if (pa < pb) v[pa] = pb;
			else v[pb] = pa;
		}
	}
}
