#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

vector<multimap<int, int>> d;
vector<pair<int, int>> chick;
vector<pair<int, int>> house;

int N, M, mini = 999999999;

void dfs(int st, unordered_set<int>& comb) {
	if (comb.size() == chick.size () - M) {
		int sum = 0;
		for (int i = 0; i < d.size(); i++) {
			for (auto j : d[i]) {
				if (comb.find(j.second) == comb.end()) {
					sum += j.first;
					break;
				}
			}
		}
		if (mini > sum) mini = sum;
		return;
	}
	for (int i = st; i < chick.size(); i++) {
		comb.insert(i);
		dfs(i + 1, comb);
		comb.erase(i);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	vector<vector<int>> m(N, vector<int>(N));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
			if (m[i][j] == 1) house.push_back({ i,j });
			else if (m[i][j] == 2) chick.push_back({ i,j });
		}
	d = vector<multimap<int, int>>(house.size());
	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chick.size(); j++) {
			d[i].insert({ abs(house[i].first - chick[j].first) + abs(house[i].second - chick[j].second), j });
		}
	}
	unordered_set<int> s;
	dfs(0, s);
	printf("%d", mini);

}
