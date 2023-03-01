#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

#define INF 100000001

int main() {
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);
	vector<unordered_map<int, int>> cost(n+1, unordered_map<int,int>());
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (cost[a][b] == 0 || cost[a][b] > c) cost[a][b] = c;
	}
	scanf("%d%d", &a, &b);
	priority_queue<pair<int, int>> pq;
	vector<pair<int, int>> dist(n + 1, { INF, 0 });
	pair<int, int> cur;
	dist[a] = { 0,-1 };
	pq.push({ 0, a });
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		for (auto i : cost[cur.second]) {
			if (dist[i.first].first > cur.first + i.second) {
				dist[i.first].first = cur.first + i.second;
				dist[i.first].second = cur.second;
				pq.push({ dist[i.first].first, i.first });
			}
		}
	}
	printf("%d\n", dist[b].first);
	vector<int> answer;
	while (b != -1) {
		answer.push_back(b);
		b = dist[b].second;
	}
	printf("%d\n", answer.size());
	for (int i = answer.size() - 1; i >= 0; i--) printf("%d ", answer[i]);
}
