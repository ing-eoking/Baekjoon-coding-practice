#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int N;
vector<vector<pair<int, int>>> d;

vector<int> dist(int st) {
	int cur;
	queue<int> q;
	q.push(st);
	vector<int> cost(N+1, -1);
	cost[st] = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (auto i : d[cur]) {
			if (cost[i.first] < 0) {
				cost[i.first] = cost[cur] + i.second;
				q.push(i.first);
			}
		}
	}
	return cost;
}


int main() {
	int V, a, b;
	scanf("%d", &N);
	d = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < N; i++) {
		scanf("%d", &V);
		while (true) {
			scanf("%d", &a);
			if (a < 0) break;
			scanf("%d", &b);
			d[V].push_back({ a,b });
		}
	}
	vector<int> first = dist(1);
	int midx = max_element(first.begin(), first.end()) - first.begin();
	vector<int> answer = dist(midx);
	int solution = *max_element(answer.begin(), answer.end());
	printf("%d", solution);
}
