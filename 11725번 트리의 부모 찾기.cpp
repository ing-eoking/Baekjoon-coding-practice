#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;


int main() {
	int N, a, b, cur;
	scanf("%d", &N);
	unordered_map<int, vector<int>> m;
	queue<int> q;
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		m[a].push_back(b);
		m[b].push_back(a);
	}
	q.push(1);
	vector<int> answer(N+1);
	answer[1] = -1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i : m[cur]) {
			if (answer[i] == 0) {
				answer[i] = cur;
				q.push(i);
			}
		}
	}
	for (int i = 2; i <= N; i++) printf("%d\n", answer[i]);
}
