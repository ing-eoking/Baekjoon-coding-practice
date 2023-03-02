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
	int a, b, c;
	scanf("%d", &N);
	d = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		d[a].push_back({ b,c });
		d[b].push_back({ a,c });
	}
	vector<int> first = dist(1);
	int midx = max_element(first.begin(), first.end()) - first.begin();
	vector<int> answer = dist(midx);
	int solution = *max_element(answer.begin(), answer.end());
	printf("%d", solution);
}
