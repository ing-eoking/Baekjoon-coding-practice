#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

vector<int> par;

inline int find(int root) {
	while (root != par[root]) root = par[root];
	return root;
}
bool fin() {
	int pa = find(0), pb;
	for (int i = 0; i < (int)par.size(); i++) {
		pb = find(i);
		if (pa != pb) return false;
		par[i] = pa = pb;
	}
	return true;
}

int main() {
	int n, pa, pb;
	scanf("%d", &n);
	double dist, answer = 0;
	vector<pair<double, double>>v(n);
	par = vector<int>(n);
	for (int i = 0; i < n; i++) par[i] = i;
	multimap<double, pair<int,int>> m;
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &v[i].first, &v[i].second);
		for (int j = 0; j < i; j++) {
			dist = sqrt(pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2));
			m.insert({ dist, {i, j} });
		}
	}
	for (auto i : m) {
		if (fin()) break;
		pa = find(i.second.first);
		pb = find(i.second.second);
		if (pa == pb) continue;
		else if (pa < pb) par[pb] = pa;
		else par[pa] = pb;
		answer += i.first;
	}
	printf("%.2f", answer);
}
