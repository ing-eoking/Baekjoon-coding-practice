#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> v;

inline int find(int root) {
	while(v[root] != root) root = v[root];
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


int main() {
	int V, E, A,B, C, num = 0, answer = 0,pa, pb;
	scanf("%d%d", &V, &E);
	set <pair<int, pair<int, int>>> s;
	v = vector<int>(V + 1);
	for (int i = 1; i <= V; i++) v[i] = i;
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &A, &B, &C);
		s.insert({ C,{A,B} });
	}
	for (auto i : s) {
		if (fin()) break;
		pa = find(i.second.first);
		pb = find(i.second.second);
		if (pa == pb) continue;
		else if (pa < pb) v[pb] = pa;
		else v[pa] = pb;
		answer += i.first;
	}
	printf("%d", answer);
}
